import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import minimize
import os

os.makedirs('result', exist_ok=True)
n = 100
p = 30
np.random.seed(42)
A = np.random.randn(p, n)
rank_A = np.linalg.matrix_rank(A)
print(f"Matrix A rank: {rank_A} (full rank: {rank_A == p})")
x_hat = np.random.rand(n)
b = A @ x_hat
print(f"Problem dimensions: n={n}, p={p}")
print(f"Initial point x_hat range: [{x_hat.min():.4f}, {x_hat.max():.4f}]")

np.savetxt('result/matrix_A.txt', A, fmt='%.6f', header=f'Constraint matrix A ({p}x{n})')
np.savetxt('result/vector_b.txt', b, fmt='%.6f', header='Right-hand side vector b')
np.savetxt('result/initial_x_hat.txt', x_hat, fmt='%.6f', header='Initial point x_hat')

class OptimizationLogger:
    """Optimization progress logger"""
    def __init__(self, name):
        self.name = name
        self.objectives = []
        self.grad_norms = []
        self.constraint_violations = []
        self.iterations = []
        
    def log(self, iteration, objective, grad_norm, constraint_violation):
        self.iterations.append(iteration)
        self.objectives.append(objective)
        self.grad_norms.append(grad_norm)
        self.constraint_violations.append(constraint_violation)

def objective(x):
    """Objective function: sum(x_i * log(x_i))"""
    return np.sum(x * np.log(x))

def gradient(x):
    """Objective gradient: log(x_i) + 1"""
    return np.log(x) + 1

def hessian(x):
    """Objective Hessian: diag(1/x_i)"""
    return np.diag(1 / x)

def constraint_violation(x, A, b):
    """Constraint violation: ||Ax - b||_2"""
    return np.linalg.norm(A @ x - b)

def standard_newton_method(A, b, x0, max_iter=100, tol=1e-8):
    """Standard Newton method"""
    logger = OptimizationLogger("Standard Newton")
    x = x0.copy()
    n = len(x)
    p = A.shape[0]
    for i in range(max_iter):
        f_val = objective(x)
        g = gradient(x)
        H = hessian(x)
        KKT_matrix = np.block([
            [H, A.T],
            [A, np.zeros((p, p))]
        ])
        rhs = np.concatenate([-g, b - A @ x])
        try:
            step = np.linalg.solve(KKT_matrix, rhs)
        except np.linalg.LinAlgError:
            step = np.linalg.lstsq(KKT_matrix, rhs, rcond=None)[0]
        dx = step[:n]
        lambda_vals = step[n:]
        t = 1.0
        alpha = 0.3
        beta = 0.5
        while np.any(x + t * dx <= 0) or objective(x + t * dx) > f_val + alpha * t * g @ dx:
            t *= beta
            if t < 1e-12:
                break
        x = x + t * dx
        grad_norm = np.linalg.norm(g + A.T @ lambda_vals)
        constr_viol = constraint_violation(x, A, b)
        logger.log(i, objective(x), grad_norm, constr_viol)
        if grad_norm < tol and constr_viol < tol:
            break
    return x, lambda_vals, logger

def infeasible_newton_method(A, b, x0, max_iter=100, tol=1e-8):
    """Infeasible start Newton method"""
    logger = OptimizationLogger("Infeasible Newton")
    x = x0.copy()
    n = len(x)
    p = A.shape[0]
    v = np.zeros(p)
    for i in range(max_iter):
        r_dual = gradient(x) + A.T @ v
        r_pri = A @ x - b
        H = hessian(x)
        KKT_matrix = np.block([
            [H, A.T],
            [A, np.zeros((p, p))]
        ])
        rhs = -np.concatenate([r_dual, r_pri])
        try:
            step = np.linalg.solve(KKT_matrix, rhs)
        except np.linalg.LinAlgError:
            step = np.linalg.lstsq(KKT_matrix, rhs, rcond=None)[0]
        dx = step[:n]
        dv = step[n:]
        t = 1.0
        alpha = 0.1
        beta = 0.5
        
        def residual_norm(x, v):
            r_dual = gradient(x) + A.T @ v
            r_pri = A @ x - b
            return np.linalg.norm(np.concatenate([r_dual, r_pri]))
        
        current_residual = residual_norm(x, v)
        while np.any(x + t * dx <= 0) or residual_norm(x + t * dx, v + t * dv) > (1 - alpha * t) * current_residual:
            t *= beta
            if t < 1e-12:
                break
        x = x + t * dx
        v = v + t * dv
        grad_norm = np.linalg.norm(r_dual)
        constr_viol = np.linalg.norm(r_pri)
        logger.log(i, objective(x), grad_norm, constr_viol)
        if current_residual < tol:
            break
    return x, v, logger

def dual_function(lambda_, A, b):
    """Dual function for entropy maximization"""
    return np.sum(np.exp(-A.T @ lambda_ - 1)) + b.T @ lambda_

def dual_gradient(lambda_, A, b):
    """Gradient of the dual function"""
    return -A @ np.exp(-A.T @ lambda_ - 1) + b

def dual_hessian(lambda_, A):
    """Hessian of the dual function"""
    exp_term = np.exp(-A.T @ lambda_ - 1)
    return A @ np.diag(exp_term) @ A.T

def dual_newton_method(A, b, lambda0, max_iter=100, tol=1e-8):
    """Dual Newton method - CORRECTED"""
    logger = OptimizationLogger("Dual Newton")
    lambda_ = lambda0.copy()
    for i in range(max_iter):
        f_dual = dual_function(lambda_, A, b)
        g_dual = dual_gradient(lambda_, A, b)
        H_dual = dual_hessian(lambda_, A)
        try:
            L = np.linalg.cholesky(H_dual)
            d_lambda = -np.linalg.solve(L.T, np.linalg.solve(L, g_dual))
        except np.linalg.LinAlgError:
            print(f"Iteration {i}: Hessian not positive definite, using regular solve with damping")
            H_reg = H_dual + 1e-6 * np.eye(H_dual.shape[0])
            d_lambda = -np.linalg.solve(H_reg, g_dual)
        t = 1.0
        alpha = 0.3
        beta = 0.5
        while dual_function(lambda_ + t * d_lambda, A, b) > f_dual + alpha * t * g_dual.T @ d_lambda:
            t *= beta
            if t < 1e-12:
                print(f"Line search failed at iteration {i}")
                break
        lambda_prev = lambda_.copy()
        lambda_ = lambda_ + t * d_lambda
        x_dual = np.exp(-A.T @ lambda_ - 1)
        grad_norm = np.linalg.norm(g_dual)
        constr_viol = constraint_violation(x_dual, A, b)
        logger.log(i, objective(x_dual), grad_norm, constr_viol)
        if grad_norm < tol and np.linalg.norm(lambda_ - lambda_prev) < tol:
            break
    x_dual = np.exp(-A.T @ lambda_ - 1)
    return x_dual, lambda_, logger

print("\nRunning optimization algorithms...")
print("1. Standard Newton method...")
x_a, lambda_a, logger_a = standard_newton_method(A, b, x_hat)
print("2. Infeasible Newton method (initial: x_hat)...")
x_b1, lambda_b1, logger_b1 = infeasible_newton_method(A, b, x_hat)
print("3. Infeasible Newton method (initial: all-ones)...")
x_b2, lambda_b2, logger_b2 = infeasible_newton_method(A, b, np.ones(n))
print("4. Dual Newton method...")
lambda0 = lambda_a.copy() + 0.1 * np.random.randn(p)
x_c, lambda_c, logger_c = dual_newton_method(A, b, lambda0)

np.savetxt('result/solution_standard_newton.txt', x_a, fmt='%.8f', header='Optimal solution - Standard Newton')
np.savetxt('result/solution_infeasible_newton_xhat.txt', x_b1, fmt='%.8f', header='Optimal solution - Infeasible Newton (x_hat)')
np.savetxt('result/solution_infeasible_newton_ones.txt', x_b2, fmt='%.8f', header='Optimal solution - Infeasible Newton (all-ones)')
np.savetxt('result/solution_dual_newton.txt', x_c, fmt='%.8f', header='Optimal solution - Dual Newton')

np.savetxt('result/lambda_standard_newton.txt', lambda_a, fmt='%.8f', header='Lagrange multipliers - Standard Newton')
np.savetxt('result/lambda_infeasible_newton_xhat.txt', lambda_b1, fmt='%.8f', header='Lagrange multipliers - Infeasible Newton (x_hat)')
np.savetxt('result/lambda_dual_newton.txt', lambda_c, fmt='%.8f', header='Lagrange multipliers - Dual Newton')

print("\n" + "="*50)
print("Results Comparison")
print("="*50)
obj_a = objective(x_a)
obj_b1 = objective(x_b1)
obj_b2 = objective(x_b2)
obj_c = objective(x_c)
print(f"\nOptimal objective values:")
print(f"Standard Newton: {obj_a:.8e}")
print(f"Infeasible Newton (x_hat): {obj_b1:.8e}")
print(f"Infeasible Newton (all-ones): {obj_b2:.8e}")
print(f"Dual Newton: {obj_c:.8e}")
print(f"\nSolution differences:")
print(f"||x_a - x_b1|| = {np.linalg.norm(x_a - x_b1):.2e}")
print(f"||x_a - x_b2|| = {np.linalg.norm(x_a - x_b2):.2e}")
print(f"||x_a - x_c|| = {np.linalg.norm(x_a - x_c):.2e}")
print(f"||x_b1 - x_c|| = {np.linalg.norm(x_b1 - x_c):.2e}")
print(f"\nLagrange multiplier differences:")
print(f"||λ_a - λ_b1|| = {np.linalg.norm(lambda_a - lambda_b1):.2e}")
print(f"||λ_a - λ_c|| = {np.linalg.norm(lambda_a - lambda_c):.2e}")
print(f"||λ_b1 - λ_c|| = {np.linalg.norm(lambda_b1 - lambda_c):.2e}")
print(f"\nFeasibility check (||Ax - b||):")
print(f"Standard Newton: {constraint_violation(x_a, A, b):.2e}")
print(f"Infeasible Newton (x_hat): {constraint_violation(x_b1, A, b):.2e}")
print(f"Infeasible Newton (all-ones): {constraint_violation(x_b2, A, b):.2e}")
print(f"Dual Newton: {constraint_violation(x_c, A, b):.2e}")

with open('result/comparison_results.txt', 'w') as f:
    f.write("OPTIMIZATION RESULTS COMPARISON\n")
    f.write("="*50 + "\n")
    f.write(f"Problem dimensions: n={n}, p={p}\n")
    f.write(f"Matrix A rank: {rank_A} (full rank: {rank_A == p})\n\n")
    
    f.write("Optimal objective values:\n")
    f.write(f"Standard Newton: {obj_a:.8e}\n")
    f.write(f"Infeasible Newton (x_hat): {obj_b1:.8e}\n")
    f.write(f"Infeasible Newton (all-ones): {obj_b2:.8e}\n")
    f.write(f"Dual Newton: {obj_c:.8e}\n\n")
    
    f.write("Solution differences:\n")
    f.write(f"||x_a - x_b1|| = {np.linalg.norm(x_a - x_b1):.2e}\n")
    f.write(f"||x_a - x_b2|| = {np.linalg.norm(x_a - x_b2):.2e}\n")
    f.write(f"||x_a - x_c|| = {np.linalg.norm(x_a - x_c):.2e}\n")
    f.write(f"||x_b1 - x_c|| = {np.linalg.norm(x_b1 - x_c):.2e}\n\n")
    
    f.write("Feasibility check (||Ax - b||):\n")
    f.write(f"Standard Newton: {constraint_violation(x_a, A, b):.2e}\n")
    f.write(f"Infeasible Newton (x_hat): {constraint_violation(x_b1, A, b):.2e}\n")
    f.write(f"Infeasible Newton (all-ones): {constraint_violation(x_b2, A, b):.2e}\n")
    f.write(f"Dual Newton: {constraint_violation(x_c, A, b):.2e}\n\n")
    
    f.write("Iteration counts:\n")
    f.write(f"Standard Newton method: {len(logger_a.iterations)}\n")
    f.write(f"Infeasible Newton (x_hat): {len(logger_b1.iterations)}\n")
    f.write(f"Infeasible Newton (all-ones): {len(logger_b2.iterations)}\n")
    f.write(f"Dual Newton method: {len(logger_c.iterations)}\n")

plt.figure(figsize=(15, 10))
plt.subplot(2, 3, 1)
plt.semilogy(logger_a.iterations, [abs(obj - obj_a) for obj in logger_a.objectives], 
            'b-', linewidth=2, label='Standard Newton')
plt.semilogy(logger_b1.iterations, [abs(obj - obj_a) for obj in logger_b1.objectives], 
            'r--', linewidth=2, label='Infeasible Newton (x_hat)')
plt.semilogy(logger_b2.iterations, [abs(obj - obj_a) for obj in logger_b2.objectives], 
            'g-.', linewidth=2, label='Infeasible Newton (all-ones)')
plt.semilogy(logger_c.iterations, [abs(obj - obj_a) for obj in logger_c.objectives], 
            'm:', linewidth=2, label='Dual Newton')
plt.xlabel('Iteration')
plt.ylabel('|f(x) - f*|')
plt.title('Objective Function Convergence')
plt.legend()
plt.grid(True, alpha=0.3)

plt.subplot(2, 3, 2)
plt.semilogy(logger_a.iterations, logger_a.grad_norms, 'b-', linewidth=2, label='Standard Newton')
plt.semilogy(logger_b1.iterations, logger_b1.grad_norms, 'r--', linewidth=2, label='Infeasible Newton (x_hat)')
plt.semilogy(logger_b2.iterations, logger_b2.grad_norms, 'g-.', linewidth=2, label='Infeasible Newton (all-ones)')
plt.semilogy(logger_c.iterations, logger_c.grad_norms, 'm:', linewidth=2, label='Dual Newton')
plt.xlabel('Iteration')
plt.ylabel('Gradient Norm')
plt.title('Optimality Condition Convergence')
plt.legend()
plt.grid(True, alpha=0.3)

plt.subplot(2, 3, 3)
plt.semilogy(logger_a.iterations, logger_a.constraint_violations, 'b-', linewidth=2, label='Standard Newton')
plt.semilogy(logger_b1.iterations, logger_b1.constraint_violations, 'r--', linewidth=2, label='Infeasible Newton (x_hat)')
plt.semilogy(logger_b2.iterations, logger_b2.constraint_violations, 'g-.', linewidth=2, label='Infeasible Newton (all-ones)')
plt.semilogy(logger_c.iterations, logger_c.constraint_violations, 'm:', linewidth=2, label='Dual Newton')
plt.xlabel('Iteration')
plt.ylabel('||Ax - b||')
plt.title('Feasibility Convergence')
plt.legend()
plt.grid(True, alpha=0.3)

plt.subplot(2, 3, 4)
plt.plot(x_a, 'bo', markersize=3, alpha=0.6, label='Standard Newton')
plt.plot(x_b1, 'rx', markersize=3, alpha=0.6, label='Infeasible Newton (x_hat)')
plt.plot(x_c, 'g+', markersize=4, alpha=0.6, label='Dual Newton')
plt.xlabel('Variable Index')
plt.ylabel('Variable Value')
plt.title('Final Solution Comparison')
plt.legend()
plt.grid(True, alpha=0.3)

plt.subplot(2, 3, 5)
plt.plot(lambda_a, 'bo', markersize=3, alpha=0.6, label='Standard Newton')
plt.plot(lambda_b1, 'rx', markersize=3, alpha=0.6, label='Infeasible Newton (x_hat)')
plt.plot(lambda_c, 'g+', markersize=4, alpha=0.6, label='Dual Newton')
plt.xlabel('Multiplier Index')
plt.ylabel('Multiplier Value')
plt.title('Lagrange Multipliers Comparison')
plt.legend()
plt.grid(True, alpha=0.3)

plt.subplot(2, 3, 6)
rel_error_a = [abs(obj - obj_a)/(abs(obj_a)+1e-10) for obj in logger_a.objectives]
rel_error_b1 = [abs(obj - obj_a)/(abs(obj_a)+1e-10) for obj in logger_b1.objectives]
rel_error_b2 = [abs(obj - obj_a)/(abs(obj_a)+1e-10) for obj in logger_b2.objectives]
rel_error_c = [abs(obj - obj_a)/(abs(obj_a)+1e-10) for obj in logger_c.objectives]
plt.semilogy(logger_a.iterations, rel_error_a, 'b-', linewidth=2, label='Standard Newton')
plt.semilogy(logger_b1.iterations, rel_error_b1, 'r--', linewidth=2, label='Infeasible Newton (x_hat)')
plt.semilogy(logger_b2.iterations, rel_error_b2, 'g-.', linewidth=2, label='Infeasible Newton (all-ones)')
plt.semilogy(logger_c.iterations, rel_error_c, 'm:', linewidth=2, label='Dual Newton')
plt.xlabel('Iteration')
plt.ylabel('Relative Error')
plt.title('Relative Error Convergence')
plt.legend()
plt.grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig('result/optimization_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

print("\n" + "="*50)
print("Computational Complexity Analysis")
print("="*50)
print(f"\nIteration counts:")
print(f"Standard Newton method: {len(logger_a.iterations)}")
print(f"Infeasible Newton (x_hat): {len(logger_b1.iterations)}")
print(f"Infeasible Newton (all-ones): {len(logger_b2.iterations)}")
print(f"Dual Newton method: {len(logger_c.iterations)}")
n, p = A.shape
print(f"\nProblem dimensions: n={n}, p={p}")

results = {
    'x_optimal': x_a,
    'lambda_optimal': lambda_a,
    'objective_value': obj_a,
    'A': A,
    'b': b,
    'x_hat': x_hat,
    'solution_standard': x_a,
    'solution_infeasible_xhat': x_b1,
    'solution_infeasible_ones': x_b2,
    'solution_dual': x_c,
    'lambda_standard': lambda_a,
    'lambda_infeasible_xhat': lambda_b1,
    'lambda_dual': lambda_c
}

np.save('result/complete_results.npy', results)
print(f"\nResults saved to 'result' directory")
print("Files generated:")
print("- matrix_A.txt: Constraint matrix A")
print("- vector_b.txt: Right-hand side vector b") 
print("- initial_x_hat.txt: Initial point")
print("- solution_*.txt: Optimal solutions from each method")
print("- lambda_*.txt: Lagrange multipliers from each method")
print("- comparison_results.txt: Detailed comparison of results")
print("- optimization_comparison.png: Convergence plots")
print("- complete_results.npy: Complete results dictionary")
print("\nOptimization completed!")