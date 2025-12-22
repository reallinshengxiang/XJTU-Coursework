import numpy as np
import matplotlib.pyplot as plt
import os
import pandas as pd

if not os.path.exists('result'):
    os.makedirs('result')

y_values_extended = [0.001, 0.01, 0.1, 0.33, 1, 3, 10, 100, 10000, 100000]

def analytical_solution(k, y):
    """Analytical solution: x^k = ((y-1)/(y+1))^k * [y, (-1)^k]"""
    coefficient = ((y - 1) / (y + 1)) ** k
    x1 = coefficient * y
    x2 = coefficient * ((-1) ** k)
    return np.array([x1, x2])

def objective_function(x1, x2, y):
    """Objective function: f(x) = 1/2(x1^2 + y*x2^2)"""
    return 0.5 * (x1**2 + y * x2**2)

def iterations_to_convergence(y_values, tolerance_values, max_iterations=10000000000):
    results = {}
    for y in y_values:
        results[y] = {}
        for tolerance in tolerance_values:
            iterations = 0
            converged = False
            for k in range(max_iterations):
                x_k = analytical_solution(k, y)
                f_val = objective_function(x_k[0], x_k[1], y)
                if f_val < tolerance:
                    iterations = k
                    converged = True
                    break
            if not converged:
                iterations = max_iterations
            results[y][tolerance] = iterations
    df = pd.DataFrame(results).T
    df.columns = [f'tol={tol}' for tol in tolerance_values]
    df['M/m'] = [max(y, 1/y) for y in y_values]
    df['Convergence Rate'] = [abs((y-1)/(y+1)) for y in y_values]
    return df

def plot_iterations_to_convergence(y_values, tolerance_values):
    df = iterations_to_convergence(y_values, tolerance_values)
    plt.figure(figsize=(10, 8))
    for i, tolerance in enumerate(tolerance_values):
        col_name = f'tol={tolerance}'
        plt.semilogy(y_values, df[col_name], 'o-', linewidth=2, label=f'Tolerance = {tolerance}')
    plt.xlabel('γ value')
    plt.ylabel('Iterations to Convergence (log scale)')
    plt.title('Iterations to Convergence vs γ Value')
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.xscale('log')
    plt.tight_layout()
    plt.savefig('result/iterations_vs_γ.png', dpi=300, bbox_inches='tight')
    plt.show()
    return df

def plot_3d_surface_and_trajectory():
    y_cases = [0.01, 0.1, 0.33, 1, 3, 10, 100]
    for y in y_cases:
        x1_range = max(1, y)
        x1 = np.linspace(-x1_range, x1_range, 100)
        x2 = np.linspace(-1, 1, 100)
        X1, X2 = np.meshgrid(x1, x2)
        Z = objective_function(X1, X2, y)
        max_iterations = 10000
        trajectory_x1 = []
        trajectory_x2 = []
        trajectory_z = []
        for k in range(max_iterations):
            x_k = analytical_solution(k, y)
            z_val = objective_function(x_k[0], x_k[1], y)
            trajectory_x1.append(x_k[0])
            trajectory_x2.append(x_k[1])
            trajectory_z.append(z_val)
        fig = plt.figure(figsize=(12, 5))
        ax1 = fig.add_subplot(121, projection='3d')
        ax1.plot_surface(X1, X2, Z, cmap='viridis', alpha=0.6)
        ax1.plot(trajectory_x1, trajectory_x2, trajectory_z, 'ro-', linewidth=2, markersize=4)
        ax1.set_xlabel('x1')
        ax1.set_ylabel('x2')
        ax1.set_zlabel('f(x)')
        ax1.set_title(f'3D Surface and Iteration Trajectory (γ={y})')
        ax2 = fig.add_subplot(122)
        contour = ax2.contour(X1, X2, Z, levels=20)
        ax2.clabel(contour, inline=True, fontsize=8)
        ax2.plot(trajectory_x1, trajectory_x2, 'ro-', linewidth=2, markersize=4)
        ax2.plot(0, 0, 'g*', markersize=10, label='Optimum')
        ax2.set_xlabel('x1')
        ax2.set_ylabel('x2')
        ax2.set_title(f'Contour and Iteration Path (γ={y})')
        ax2.legend()
        ax2.grid(True, alpha=0.3)
        plt.tight_layout()
        plt.savefig(f'result/3d_surface_trajectory_γ={y}.png', dpi=300, bbox_inches='tight')
        plt.show()

def plot_initial_iterations():
    """Plot first few iterations for different y values with publication quality"""
    # Set publication quality style
    plt.rcParams.update({
        'font.family': 'serif',
        'font.size': 11,
        'axes.labelsize': 12,
        'axes.titlesize': 13,
        'legend.fontsize': 10,
        'xtick.labelsize': 10,
        'ytick.labelsize': 10,
        'lines.linewidth': 1.5,
        'lines.markersize': 6,
    })
    y_values = [0.1, 0.5, 1, 2, 3, 5]
    colors = plt.cm.Set2(np.linspace(0, 1, len(y_values)))
    markers = ['o', 's', '^', 'D', 'v', '<']
    max_iterations = 10
    fig, ax = plt.subplots(figsize=(6, 4.5))
    for i, y in enumerate(y_values):
        f_values = []
        for k in range(max_iterations):
            x_k = analytical_solution(k, y)
            f_val = objective_function(x_k[0], x_k[1], y)
            f_values.append(f_val)
        ax.plot(range(max_iterations), f_values, 
                color=colors[i], 
                marker=markers[i],
                linewidth=1.5, 
                label=f'y = {y} (M/m = {max(y, 1/y):.1f})')
    ax.set_xlabel('Iteration $k$')
    ax.set_ylabel('Objective Value $f(x^k)$')
    ax.set_title('First few iterations for Different Condition Numbers', pad=15)
    ax.legend(loc='upper right', frameon=True, framealpha=0.9)
    ax.grid(True, alpha=0.3)
    ax.set_xlim(-0.5, max_iterations - 0.5)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    plt.tight_layout()
    plt.savefig('result/initial_iterations.png', bbox_inches='tight', dpi=300)
    plt.show()

print("Generating visualizations...")
print("First few iterations")
plot_initial_iterations()
print("3D surface and trajectory")
plot_3d_surface_and_trajectory()
print("Iterations to convergence analysis")
tolerance_values = [0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001]
df = plot_iterations_to_convergence(y_values_extended, tolerance_values)
print("\nIterations to convergence for different γ values and tolerances:")
print(df)
df.to_csv('result/iterations_to_convergence_table.csv')
print("\nIterations table saved to 'result/iterations_to_convergence_table.csv'")