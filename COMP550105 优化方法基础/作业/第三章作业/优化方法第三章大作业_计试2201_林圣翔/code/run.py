import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import minimize, minimize_scalar
import os
import itertools
import pandas as pd
import seaborn as sns

plt.style.use('seaborn-v0_8-paper')
sns.set_palette("husl")
COLORS = sns.color_palette("husl", 8)
MARKERS = ['o', 's', '^', 'D', 'v', '<', '>', 'p']

if not os.path.exists('result'):
    os.makedirs('result')

def function(x):
    return np.exp(x[0] + 3 * x[1] - 0.1) + np.exp(x[0] - 3 * x[1] - 0.1) + np.exp(-x[0] - 0.1)

def gradient(x):
    df_dx1 = (np.exp(x[0] + 3 * x[1] - 0.1) + np.exp(x[0] - 3 * x[1] - 0.1) - np.exp(-x[0] - 0.1))
    df_dx2 = 3 * np.exp(x[0] + 3 * x[1] - 0.1) - 3 * np.exp(x[0] - 3 * x[1] - 0.1)
    return np.array([df_dx1, df_dx2])

def hessian(x):
    e1 = np.exp(x[0] + 3 * x[1] - 0.1)
    e2 = np.exp(x[0] - 3 * x[1] - 0.1)
    e3 = np.exp(-x[0] - 0.1)
    h11 = e1 + e2 + e3
    h12 = 3 * (e1 - e2)
    h22 = 9 * (e1 + e2)
    return np.array([[h11, h12], [h12, h22]])

def neg_gradient_direction(x):
    return -gradient(x)

def newton_direction(x):
    hess = hessian(x)
    grad = gradient(x)
    return -np.linalg.inv(hess).dot(grad)

def p_norm_direction(x, P=np.array([[2, 1], [1, 2]])):
    grad = gradient(x)
    return -np.linalg.inv(P).dot(grad)

def exact_line_search(x, direction):
    def g(alpha):
        return function(x + alpha * direction)
    result = minimize_scalar(g)
    return result.x

def backtracking_line_search(x, direction, alpha=0.3, beta=0.8):
    step_size = 1.0
    while function(x + step_size * direction) > function(x) + alpha * step_size * np.dot(gradient(x), direction):
        step_size *= beta
    return step_size

def gradient_descent_exact(x0, max_iter=10000, tol=1e-6, direction_func=neg_gradient_direction):
    x = x0.copy()
    p_star = minimize(function, x0).fun
    errors = [function(x) - p_star]
    trajectory = [x.copy()]
    for k in range(max_iter):
        direction = direction_func(x)
        step_size = exact_line_search(x, direction)
        x = x + step_size * direction
        trajectory.append(x.copy())
        error = function(x) - p_star
        grad_norm = np.linalg.norm(gradient(x), 2)
        errors.append(error)
        if grad_norm < tol:
            break       
    return x, errors, trajectory

def gradient_descent_backtracking(x0, alpha=0.3, beta=0.8, max_iter=10000, tol=1e-6, direction_func=neg_gradient_direction):
    x = x0.copy()
    p_star = minimize(function, x0).fun
    errors = [function(x) - p_star]
    trajectory = [x.copy()]
    for k in range(max_iter):
        direction = direction_func(x)
        step_size = backtracking_line_search(x, direction, alpha, beta)
        x = x + step_size * direction
        trajectory.append(x.copy())
        error = function(x) - p_star
        grad_norm = np.linalg.norm(gradient(x), 2)
        errors.append(error)
        if grad_norm < tol:
            break        
    return x, errors, trajectory

def grid_search_backtracking(x0, alpha_values=[0.1, 0.2, 0.3, 0.4], beta_values=[0.1, 0.3, 0.5, 0.7, 0.9], max_iter=10000, tol=1e-6, direction_func=neg_gradient_direction):
    results = []
    for alpha, beta in itertools.product(alpha_values, beta_values):
        x_opt, errors, trajectory = gradient_descent_backtracking(x0, alpha=alpha, beta=beta, max_iter=max_iter, tol=tol, direction_func=direction_func)
        final_error = errors[-1]
        iterations = len(errors) - 1
        convergence_rate = calculate_convergence_rate(errors) if len(errors) > 5 else float('inf')
        results.append({
            'alpha': alpha,
            'beta': beta,
            'final_error': final_error,
            'iterations': iterations,
            'convergence_rate': convergence_rate,
            'optimal_value': function(x_opt),
            'errors': errors,
            'trajectory': trajectory
        })
        print(f"α={alpha}, β={beta}: iterations={iterations}, final_error={final_error:.2e}")
    df_results = pd.DataFrame(results)
    best_by_error = df_results.loc[df_results['final_error'].idxmin()]
    best_by_iterations = df_results.loc[df_results['iterations'].idxmin()]
    print("\n=== Grid Search Results ===")
    print(f"Best by final error: α={best_by_error['alpha']}, β={best_by_error['beta']}, error={best_by_error['final_error']:.2e}")
    print(f"Best by iterations: α={best_by_iterations['alpha']}, β={best_by_iterations['beta']}, iterations={best_by_iterations['iterations']}")
    return df_results

def calculate_convergence_rate(errors):
    if len(errors) < 5:
        return float('inf')
    last_errors = errors[-5:]
    rates = []
    for i in range(1, len(last_errors)):
        if last_errors[i-1] > 0:
            rate = last_errors[i] / last_errors[i-1]
            rates.append(rate)
    return np.mean(rates) if rates else float('inf')

def plot_3d_surface_and_trajectory(x0, method_name, params=None, filename=None):
    if method_name == "exact":
        x_opt, errors, trajectory = gradient_descent_exact(x0)
        title_suffix = "Exact Line Search"
    elif method_name == "backtracking":
        if params is None:
            params = {'alpha': 0.3, 'beta': 0.8}
        x_opt, errors, trajectory = gradient_descent_backtracking(x0, alpha=params['alpha'], beta=params['beta'])
        title_suffix = f"Backtracking (α={params['alpha']}, β={params['beta']})"
    trajectory_x1 = [point[0] for point in trajectory]
    trajectory_x2 = [point[1] for point in trajectory]
    trajectory_z = [function(point) for point in trajectory]
    x1_min, x1_max = min(trajectory_x1), max(trajectory_x1)
    x2_min, x2_max = min(trajectory_x2), max(trajectory_x2)
    margin_x1 = (x1_max - x1_min) * 0.2
    margin_x2 = (x2_max - x2_min) * 0.2
    x1_range = np.linspace(x1_min - margin_x1, x1_max + margin_x1, 100)
    x2_range = np.linspace(x2_min - margin_x2, x2_max + margin_x2, 100)
    X1, X2 = np.meshgrid(x1_range, x2_range)
    Z = np.zeros_like(X1)
    for i in range(X1.shape[0]):
        for j in range(X1.shape[1]):
            Z[i, j] = function([X1[i, j], X2[i, j]])
    fig = plt.figure(figsize=(16, 6))
    ax1 = fig.add_subplot(121, projection='3d')
    surf = ax1.plot_surface(X1, X2, Z, cmap='viridis', alpha=0.6, linewidth=0, antialiased=True)
    ax1.plot(trajectory_x1, trajectory_x2, trajectory_z, 'ro-', linewidth=2, markersize=4, label='Optimization Path')
    ax1.scatter(trajectory_x1[0], trajectory_x2[0], trajectory_z[0], color='blue', s=100, marker='o', label='Start')
    ax1.scatter(trajectory_x1[-1], trajectory_x2[-1], trajectory_z[-1], color='green', s=100, marker='*', label='Optimum')
    ax1.set_xlabel('x1', fontweight='bold')
    ax1.set_ylabel('x2', fontweight='bold')
    ax1.set_zlabel('f(x)', fontweight='bold')
    ax1.set_title(f'3D Surface and Optimization Trajectory\n{title_suffix}', fontweight='bold')
    ax1.legend()
    ax2 = fig.add_subplot(122)
    contour = ax2.contour(X1, X2, Z, levels=20, cmap='viridis')
    ax2.clabel(contour, inline=True, fontsize=8)
    ax2.plot(trajectory_x1, trajectory_x2, 'ro-', linewidth=2, markersize=4, label='Optimization Path')
    ax2.scatter(trajectory_x1[0], trajectory_x2[0], color='blue', s=100, marker='o', label='Start')
    ax2.scatter(trajectory_x1[-1], trajectory_x2[-1], color='green', s=100, marker='*', label='Optimum')
    ax2.set_xlabel('x1', fontweight='bold')
    ax2.set_ylabel('x2', fontweight='bold')
    ax2.set_title(f'Contour and Optimization Path\n{title_suffix}', fontweight='bold')
    ax2.legend()
    ax2.grid(True, alpha=0.3)
    plt.tight_layout()
    if filename is None:
        filename = f"3d_contour_{method_name}_x0_{x0[0]}_{x0[1]}.png"
    filepath = os.path.join('result', filename)
    plt.savefig(filepath, dpi=300, bbox_inches='tight', facecolor='white')
    plt.close()
    print(f"3D surface and contour plot saved: {filepath}")
    return trajectory

def plot_results(all_errors, title, filename, figsize=(10, 8)):
    fig, ax = plt.subplots(figsize=figsize)
    for i, (errors, label) in enumerate(all_errors):
        if len(errors) > 0:
            ax.semilogy(range(len(errors)), errors, 
                       color=COLORS[i % len(COLORS)], 
                       marker=MARKERS[i % len(MARKERS)],
                       markersize=6, 
                       markevery=max(1, len(errors)//10),
                       linewidth=2,
                       label=label)
    ax.set_xlabel('Iteration', fontweight='bold')
    ax.set_ylabel('Error (log scale)', fontweight='bold')
    ax.set_title(title, fontweight='bold', pad=20)
    ax.legend(frameon=True, fancybox=True, shadow=True, framealpha=0.9)
    ax.grid(True, alpha=0.3, linestyle='--')
    for spine in ax.spines.values():
        spine.set_linewidth(1.5)
    filepath = os.path.join('result', filename)
    plt.tight_layout()
    plt.savefig(filepath, dpi=300, bbox_inches='tight', facecolor='white')
    plt.close()
    print(f"Figure saved: {filepath}")

def plot_grid_search_results(df_results, filename):
    fig, axes = plt.subplots(2, 2, figsize=(16, 14))
    alpha_vals = sorted(df_results['alpha'].unique())
    beta_vals = sorted(df_results['beta'].unique())
    error_matrix = df_results.pivot(index='alpha', columns='beta', values='final_error')
    im1 = axes[0, 0].imshow(error_matrix, cmap='viridis_r', aspect='auto')
    axes[0, 0].set_title('Final Error', fontweight='bold', pad=15)
    axes[0, 0].set_xlabel('β', fontweight='bold')
    axes[0, 0].set_ylabel('α', fontweight='bold')
    axes[0, 0].set_xticks(range(len(beta_vals)))
    axes[0, 0].set_xticklabels(beta_vals)
    axes[0, 0].set_yticks(range(len(alpha_vals)))
    axes[0, 0].set_yticklabels(alpha_vals)
    cbar1 = plt.colorbar(im1, ax=axes[0, 0])
    cbar1.set_label('Error', fontweight='bold')
    for i in range(len(alpha_vals)):
        for j in range(len(beta_vals)):
            axes[0, 0].text(j, i, f'{error_matrix.iloc[i, j]:.1e}', 
                           ha="center", va="center", color="w", fontsize=10, fontweight='bold')
    iter_matrix = df_results.pivot(index='alpha', columns='beta', values='iterations')
    im2 = axes[0, 1].imshow(iter_matrix, cmap='viridis_r', aspect='auto')
    axes[0, 1].set_title('Iterations to Convergence', fontweight='bold', pad=15)
    axes[0, 1].set_xlabel('β', fontweight='bold')
    axes[0, 1].set_ylabel('α', fontweight='bold')
    axes[0, 1].set_xticks(range(len(beta_vals)))
    axes[0, 1].set_xticklabels(beta_vals)
    axes[0, 1].set_yticks(range(len(alpha_vals)))
    axes[0, 1].set_yticklabels(alpha_vals)
    cbar2 = plt.colorbar(im2, ax=axes[0, 1])
    cbar2.set_label('Iterations', fontweight='bold')
    for i in range(len(alpha_vals)):
        for j in range(len(beta_vals)):
            axes[0, 1].text(j, i, f'{iter_matrix.iloc[i, j]:.0f}', 
                           ha="center", va="center", color="w", fontsize=10, fontweight='bold')
    rate_matrix = df_results.pivot(index='alpha', columns='beta', values='convergence_rate')
    im3 = axes[1, 0].imshow(rate_matrix, cmap='viridis_r', aspect='auto')
    axes[1, 0].set_title('Convergence Rate', fontweight='bold', pad=15)
    axes[1, 0].set_xlabel('β', fontweight='bold')
    axes[1, 0].set_ylabel('α', fontweight='bold')
    axes[1, 0].set_xticks(range(len(beta_vals)))
    axes[1, 0].set_xticklabels(beta_vals)
    axes[1, 0].set_yticks(range(len(alpha_vals)))
    axes[1, 0].set_yticklabels(alpha_vals)
    cbar3 = plt.colorbar(im3, ax=axes[1, 0])
    cbar3.set_label('Rate', fontweight='bold')
    for i in range(len(alpha_vals)):
        for j in range(len(beta_vals)):
            if rate_matrix.iloc[i, j] < float('inf'):
                axes[1, 0].text(j, i, f'{rate_matrix.iloc[i, j]:.3f}', 
                               ha="center", va="center", color="w", fontsize=10, fontweight='bold')
    axes[1, 1].set_title('Best Convergence Curves', fontweight='bold', pad=15)
    best_by_error = df_results.loc[df_results['final_error'].idxmin()]
    best_by_iter = df_results.loc[df_results['iterations'].idxmin()]
    axes[1, 1].semilogy(best_by_error['errors'], color=COLORS[0], marker='o', markersize=6, markevery=5,
                       linewidth=2, label=f'Best error (α={best_by_error["alpha"]}, β={best_by_error["beta"]})')
    axes[1, 1].semilogy(best_by_iter['errors'], color=COLORS[1], marker='s', markersize=6, markevery=5,
                       linewidth=2, label=f'Best iterations (α={best_by_iter["alpha"]}, β={best_by_iter["beta"]})')
    axes[1, 1].set_xlabel('Iterations', fontweight='bold')
    axes[1, 1].set_ylabel('Error (log scale)', fontweight='bold')
    axes[1, 1].legend(frameon=True, fancybox=True, shadow=True, framealpha=0.9)
    axes[1, 1].grid(True, alpha=0.3, linestyle='--')
    for ax_row in axes:
        for ax in ax_row:
            for spine in ax.spines.values():
                spine.set_linewidth(1.5)
    plt.tight_layout()
    filepath = os.path.join('result', filename)
    plt.savefig(filepath, dpi=300, bbox_inches='tight', facecolor='white')
    plt.close()
    print(f"Grid search results saved: {filepath}")
    return best_by_error, best_by_iter

def plot_exact_line_search():
    print("=== Exact Line Search - Different Initial Points ===")
    initial_points = [
        np.array([1, 2]),
        np.array([2, -3]),
        np.array([-3, 2]),
        np.array([-2, -1])
    ]
    all_errors = []
    for i, x0 in enumerate(initial_points):
        print(f"\nInitial point {i+1}: {x0}")
        optimal_x, errors, trajectory = gradient_descent_exact(x0)
        all_errors.append((errors, f'Initial point {x0}'))
        print(f"Optimal solution: {optimal_x}")
        print(f"Optimal value: {function(optimal_x):.8f}")
        print(f"Iterations: {len(errors)}")
        if i < 3:
            plot_3d_surface_and_trajectory(x0, "exact", filename=f"exact_line_search_trajectory_{i+1}.png") 
    plot_results(all_errors, 'Exact Line Search: Convergence with Different Initial Points', 'exact_line_search_initial_points.png')

def plot_backtracking_line_search():
    print("\n=== Backtracking Line Search - Different Parameters ===")
    param_groups = [
        [(alpha, beta) for alpha in [0.05, 0.1, 0.3] for beta in [0.1, 0.3, 0.5, 0.7, 0.9]],
        [(alpha, beta) for beta in [0.05, 0.1, 0.3] for alpha in [0.1, 0.3, 0.5, 0.7, 0.9]],
        [(alpha, beta) for beta in [0.1, 0.3, 0.5] for alpha in [0.1, 0.3, 0.5]],
    ]
    group_names = [
        'Fixed α (0.05, 0.1, 0.3), Varying β', 
        'Fixed β (0.05, 0.1, 0.3), Varying α', 
        'Both α and β Varying'
    ]
    filenames = [
        'backtracking_fixed_alpha.png', 
        'backtracking_fixed_beta.png', 
        'backtracking_both_changing.png'
    ]
    x0 = np.array([1.5, 1.5])
    example_params = [
        {'alpha': 0.1, 'beta': 0.3},
        {'alpha': 0.3, 'beta': 0.8},
        {'alpha': 0.5, 'beta': 0.5}
    ]
    for i, params in enumerate(example_params):
        plot_3d_surface_and_trajectory(
            x0, "backtracking", params,
            filename=f"backtracking_trajectory_example_{i+1}.png"
        )
    for group_idx, params in enumerate(param_groups):
        print(f"\n--- Parameter Group {group_idx+1}: {group_names[group_idx]} ---")
        all_errors = []
        x0 = np.array([1, 1])
        if group_idx == 0:
            alphas = sorted(set(alpha for alpha, beta in params))
            alpha_colors = sns.color_palette("husl", len(alphas))
            color_map = {alpha: alpha_colors[i] for i, alpha in enumerate(alphas)}
            markers = ['o', 's', '^', 'D', 'v']
        elif group_idx == 1:
            betas = sorted(set(beta for alpha, beta in params))
            beta_colors = sns.color_palette("husl", len(betas))
            color_map = {beta: beta_colors[i] for i, beta in enumerate(betas)}
            markers = ['o', 's', '^', 'D', 'v']  
        else: 
            color_map = None
            markers = ['o', 's', '^', 'D', 'v', '<', '>', 'p', '*']
        color_list = []
        marker_list = []
        label_list = []
        errors_list = []
        for i, (alpha, beta) in enumerate(params):
            optimal_x, errors, trajectory = gradient_descent_backtracking(x0, alpha=alpha, beta=beta)
            if group_idx == 0:
                label = f'α={alpha}, β={beta}'
                color = color_map[alpha]
                marker = markers[i % 5]
            elif group_idx == 1:
                label = f'α={alpha}, β={beta}'
                color = color_map[beta]
                marker = markers[i % 5]
            else:
                label = f'α={alpha}, β={beta}'
                color = COLORS[i % len(COLORS)]
                marker = markers[i % len(markers)]
            errors_list.append(errors)
            label_list.append(label)
            color_list.append(color)
            marker_list.append(marker)
            print(f"α={alpha}, β={beta}: iterations={len(errors)}, optimal value={function(optimal_x):.8f}")
        fig, ax = plt.subplots(figsize=(10, 8))
        for i, (errors, label, color, marker) in enumerate(zip(errors_list, label_list, color_list, marker_list)):
            if len(errors) > 0:
                ax.semilogy(range(len(errors)), errors, color=color, marker=marker,markersize=6, markevery=max(1, len(errors)//10), linewidth=2, label=label)
        ax.set_xlabel('Iteration', fontweight='bold')
        ax.set_ylabel('Error (log scale)', fontweight='bold')
        ax.set_title(f'Backtracking Line Search: {group_names[group_idx]}', fontweight='bold', pad=20)
        ax.legend(frameon=True, fancybox=True, shadow=True, framealpha=0.9, fontsize=9)
        ax.grid(True, alpha=0.3, linestyle='--')
        for spine in ax.spines.values():
            spine.set_linewidth(1.5)
        filepath = os.path.join('result', filenames[group_idx])
        plt.tight_layout()
        plt.savefig(filepath, dpi=300, bbox_inches='tight', facecolor='white')
        plt.close()
        print(f"Figure saved: {filepath}")

def plot_exact_vs_backtracking():
    print("\n=== Exact vs Backtracking Line Search ===")
    x0 = np.array([1, 1])
    all_errors = []
    optimal_x_exact, errors_exact, trajectory_exact = gradient_descent_exact(x0)
    all_errors.append((errors_exact, 'Exact Line Search'))
    print(f"Exact Line Search: iterations={len(errors_exact)}, optimal value={function(optimal_x_exact):.8f}")
    backtracking_params = [(0.1, 0.3), (0.5, 0.3)]
    for alpha, beta in backtracking_params:
        optimal_x_bt, errors_bt, trajectory_bt = gradient_descent_backtracking(x0, alpha=alpha, beta=beta)
        all_errors.append((errors_bt, f'Backtracking (α={alpha},β={beta})'))
        print(f"Backtracking (α={alpha},β={beta}): iterations={len(errors_bt)}, optimal value={function(optimal_x_bt):.8f}")
    plot_results(all_errors, 'Exact vs Backtracking Line Search', 'exact_vs_backtracking.png')
    plot_3d_surface_and_trajectory(x0, "exact", filename="comparison_exact.png")
    plot_3d_surface_and_trajectory(x0, "backtracking", {'alpha': 0.1, 'beta': 0.3}, filename="comparison_backtracking.png")

def main_grid_search():
    print("\n=== Grid Search for Backtracking Parameters ===")
    x0 = np.array([1.0, 1.0])
    alpha_values = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
    beta_values = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
    df_results = grid_search_backtracking(x0, alpha_values, beta_values)
    best_by_error, best_by_iter = plot_grid_search_results(df_results, 'grid_search_results.png')
    print("\n=== Creating 3D Visualization for Best Parameters ===")
    plot_3d_surface_and_trajectory(
        x0, "backtracking", 
        {'alpha': best_by_error['alpha'], 'beta': best_by_error['beta']},
        filename="grid_search_best_by_error.png"
    )
    plot_3d_surface_and_trajectory(
        x0, "backtracking", 
        {'alpha': best_by_iter['alpha'], 'beta': best_by_iter['beta']},
        filename="grid_search_best_by_iterations.png"
    )
    csv_path = os.path.join('result', 'grid_search_results.csv')
    df_results.to_csv(csv_path, index=False)
    print(f"Detailed results saved to: {csv_path}")
    return best_by_error, best_by_iter

def plot_comprehensive_3d_visualization():
    print("\n=== Creating Comprehensive 3D Visualizations ===")
    initial_points = [
        np.array([1, 2]),
        np.array([2, -3]),
        np.array([-3, 2]),
        np.array([-2, -1])
    ]
    for i, x0 in enumerate(initial_points):
        plot_3d_surface_and_trajectory(x0, "exact", filename=f"comprehensive_exact_x0_{i+1}.png")
    backtracking_params = [
        {'alpha': 0.1, 'beta': 0.3},
        {'alpha': 0.3, 'beta': 0.5},
        {'alpha': 0.5, 'beta': 0.8}
    ]
    x0 = np.array([1.0, 1.0])
    for i, params in enumerate(backtracking_params):
        plot_3d_surface_and_trajectory(x0, "backtracking", params,filename=f"comprehensive_backtracking_params_{i+1}.png")

plot_comprehensive_3d_visualization()
plot_exact_line_search()
plot_backtracking_line_search()
main_grid_search()
plot_exact_vs_backtracking()