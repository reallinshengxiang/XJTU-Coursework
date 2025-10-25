#include<bits/stdc++.h>
using namespace std;
template<class T>
const T& clamp(const T& v, const T& lo, const T& hi) {
    return v < lo ? lo : hi < v ? hi : v;
}
struct City {
    int id;
    double x;
    double y;
};
vector<City> read_tsp_data(const string& file_path) {
    vector<City> city_coordinates;
    ifstream file(file_path);
    string line;
    bool in_node_coord_section = false;
    while (getline(file, line)) {
        if (line == "EOF") {
            break;
        }
        if (line == "NODE_COORD_SECTION") {
            in_node_coord_section = true;
            continue;
        }
        if (in_node_coord_section) {
            std::istringstream iss(line);
            City city;
            iss >> city.id >> city.x >> city.y;
           // cout<<city.id<<"  "<<city.x<<"   "<<city.y<<"\n";
            city_coordinates.push_back(city);
        }
    }
    return city_coordinates;
}
vector<vector<double>> calculate_distance_matrix(const vector<City>& city_coordinates) {
    int num_cities = city_coordinates.size();
    vector<vector<double>> distance_matrix(num_cities, vector<double>(num_cities, numeric_limits<double>::infinity()));
    for (int i = 0; i < num_cities; ++i) {
        for (int j = 0; j < num_cities; ++j) {
            if (i == j) {
                continue;
            }
            const City& city1 = city_coordinates[i];
            const City& city2 = city_coordinates[j];
            double dx = city1.x - city2.x;
            double dy = city1.y - city2.y;
            distance_matrix[i][j] = std::sqrt(dx * dx + dy * dy);
        }
    }
    return distance_matrix;
}
double path_length(const std::vector<int>& path, const std::vector<std::vector<double>>& distances) {
    double length = 0;
    int num_cities = path.size();
    for (int i = 0; i < num_cities - 1; ++i) {
        length += distances[path[i]][path[i + 1]];
    }
    length += distances[path.back()][path[0]];
    return length;
}
vector<int> two_opt(const vector<int>& path, const vector<vector<double>>& distances) {
    vector<int> new_path = path;
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 1; i < new_path.size() - 2; ++i) {
            for (int j = i + 1; j < new_path.size(); ++j) {
                if (j - i == 1) {
                    continue;
                }
                vector<int> candidate_path = new_path;
                reverse(candidate_path.begin() + i, candidate_path.begin() + j);
                if (path_length(candidate_path, distances) < path_length(new_path, distances)) {
                    new_path = candidate_path;
                    improved = true;
                }
            }
        }
    }
    return new_path;
}
vector<vector<double>> initialize_pheromone(const vector<vector<double>>& distances) {
    int num_cities = distances.size();
    vector<std::vector<double>> pheromone(num_cities, vector<double>(num_cities));
    for (int i = 0; i < num_cities; ++i) {
        for (int j = 0; j < num_cities; ++j) {
            pheromone[i][j] = 1.0 / (distances[i][j] + 1e-10);
        }
    }
    return pheromone;
}
void spread_pheromone(std::vector<std::vector<double>>& pheromone, const vector<pair<std::vector<int>, double>>& all_paths, int n_best) {
    vector<pair<vector<int>, double>> sorted_paths = all_paths;
    sort(sorted_paths.begin(), sorted_paths.end(), [](const pair<vector<int>, double>& a, const pair<vector<int>, double>& b) {
        return a.second < b.second;
    });
    for (int k = 0; k < min(n_best, static_cast<int>(sorted_paths.size())); ++k) {
        const vector<int>& path = sorted_paths[k].first;
        double dist = sorted_paths[k].second;
        for (int i = 0; i < path.size() - 1; ++i) {
            int from = path[i];
            int to = path[i + 1];
            pheromone[from][to] += 1.0 / dist;
        }
        pheromone[path.back()][path[0]] += 1.0 / dist;
    }
}
int pick_move(const vector<double>& pheromone, const vector<double>& dist, const vector<bool>& visited, double alpha, double beta) {
    vector<double> probabilities(dist.size());
    double sum = 0;
    for (int i = 0; i < dist.size(); ++i) {
        if (visited[i]) {
            probabilities[i] = 0;
        } else {
            probabilities[i] = std::pow(pheromone[i], alpha) * std::pow(1.0 / (dist[i] + 1e-10), beta);
            sum += probabilities[i];
        }
    }
    if (sum == 0) {
        for (int i = 0; i < dist.size(); ++i) {
            if (!visited[i]) {
                return i;
            }
        }
    }
    for (double& p : probabilities) {
        p /= sum;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> d(probabilities.begin(), probabilities.end());
    return d(gen);
}
vector<int> gen_path(int start, const std::vector<std::vector<double>>& pheromone, const vector<vector<double>>& distances, double alpha, double beta) {
    vector<int> path = {start};
    vector<bool> visited(distances.size(), false);
    visited[start] = true;
    int prev = start;
    for (int i = 0; i < distances.size() - 1; ++i) {
        int move = pick_move(pheromone[prev], distances[prev], visited, alpha, beta);
        path.push_back(move);
        prev = move;
        visited[move] = true;
    }
    path = two_opt(path, distances);
    return path;
}
vector<pair<std::vector<int>, double>> gen_all_paths(int n_ants, const vector<vector<double>>& pheromone, const vector<vector<double>>& distances, double alpha, double beta) {
    vector<future<vector<int>>> futures;
    for (int i = 0; i < n_ants; ++i) {
        futures.emplace_back(async(launch::async, gen_path, 0, ref(pheromone), ref(distances), alpha, beta));
    }
    vector<pair<vector<int>, double>> paths;
    for (auto& future : futures) {
        vector<int> path = future.get();
        double length = path_length(path, distances);
        paths.emplace_back(path, length);
    }
    return paths;
}
tuple<vector<int>, double, double, int> ant_colony_optimization(const vector<vector<double>>& distances, int n_ants, int n_best, int n_iterations, double decay, double alpha, double beta, int n_generation_output) {
    vector<vector<double>> pheromone = initialize_pheromone(distances);
    pair<vector<int>, double> all_time_shortest_path = {{}, std::numeric_limits<double>::infinity()};
    vector<double> best_lengths;
    auto start_time = chrono::high_resolution_clock::now();
    int earliest_shortest_path_iterations = 0;
    for (int i = 0; i < n_iterations; ++i) {
        vector<pair<vector<int>, double>> all_paths = gen_all_paths(n_ants, pheromone, distances, alpha, beta);
        spread_pheromone(pheromone, all_paths, n_best);
        auto shortest_path = *std::min_element(all_paths.begin(), all_paths.end(), [](const std::pair<std::vector<int>, double>& a, const std::pair<std::vector<int>, double>& b) {
            return a.second < b.second;
        });
        best_lengths.push_back(shortest_path.second);
        if (shortest_path.second < all_time_shortest_path.second) {
            all_time_shortest_path = shortest_path;
            earliest_shortest_path_iterations = i;
        }
        for (auto& row : pheromone) {
            for (double& p : row) {
                p = clamp(p * decay, 0.1, 10.0);
            }
        }
        if ((i + 1) % n_generation_output == 0) {
            auto current_time = chrono::high_resolution_clock::now();
            double elapsed_time = chrono::duration<double>(current_time - start_time).count();
            std::cout << "generation:" << i + 1 << "  best_lengths:" << shortest_path.second << "  time:" << elapsed_time << std::endl;
        }
    }
    auto end_time = chrono::high_resolution_clock::now();
    double total_time = chrono::duration<double>(end_time - start_time).count();
    return make_tuple(all_time_shortest_path.first, all_time_shortest_path.second, total_time, earliest_shortest_path_iterations);
}

int main() {
    string file_path = "att532.tsp";
    freopen("att532_result.txt","w",stdout); 
    vector<City> city_coordinates = read_tsp_data(file_path);
    int num_cities = city_coordinates.size();
    vector<vector<double>> distance_matrix = calculate_distance_matrix(city_coordinates);
    auto result = ant_colony_optimization(distance_matrix, 30, 5, 50, 0.95, 1, 2, 1);
    vector<int> optimal_path;
    double best_path_length;
    double total_time;
    int earliest_shortest_path_iterations;
    tie(optimal_path, best_path_length, total_time, earliest_shortest_path_iterations) = result;
    for (int city_index : optimal_path)   cout << city_index << " ";
    cout << std::endl;
    cout << "best_path_length: " << best_path_length << std::endl;
    cout << "total_time: " << total_time << " s" << std::endl;
    cout << "earliest_shortest_path_iterations:" << earliest_shortest_path_iterations << std::endl;
    return 0;
}
