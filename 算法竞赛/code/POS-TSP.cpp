#include<bits/stdc++.h>
using namespace std;
struct City {
    int id;
    double x, y;
};
vector<City> read_tsp_data(const string& file_path) {
    vector<City> cities;
    ifstream file(file_path);
    string line;
    while (getline(file, line)) {
        line.erase(0, line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ') + 1);
        if (line.empty() || line[0] == '#') continue;
        int id;
        double x, y;
        istringstream iss(line);
        if (iss >> id >> x >> y) {
            cities.push_back({id, x, y});
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }
    return cities;
}
vector<vector<double>> calculate_distance_matrix(const vector<City>& cities) {
    int num_cities = cities.size();
    vector<vector<double>> distance_matrix(num_cities, vector<double>(num_cities, numeric_limits<double>::infinity()));
    for (int i = 0; i < num_cities; ++i) {
        for (int j = 0; j < num_cities; ++j) {
            if (i == j) continue;
            double dx = cities[i].x - cities[j].x;
            double dy = cities[i].y - cities[j].y;
            distance_matrix[i][j] = sqrt(dx * dx + dy * dy);
        }
    }
    return distance_matrix;
}
double path_length(const vector<int>& path, const vector<vector<double>>& distances) {
    double length = 0;
    int num_cities = path.size();
    for (int i = 0; i < num_cities - 1; ++i) {
        length += distances[path[i]][path[i + 1]];
    }
    length += distances[path.back()][path[0]];
    return length;
}
vector<vector<int>> initialize_particles(int num_particles, int num_cities) {
    vector<vector<int>> particles(num_particles);
    for (int i = 0; i < num_particles; ++i) {
        particles[i].resize(num_cities);
        for (int j = 0; j < num_cities; ++j) particles[i][j] = j;
        random_shuffle(particles[i].begin(), particles[i].end());
    }
    return particles;
}
vector<int> two_opt(vector<int> path, const vector<vector<double>>& distances) {
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 1; i < path.size() - 2; ++i) {
            for (int j = i + 1; j < path.size(); ++j) {
                if (j - i == 1) continue;
                vector<int> new_path = path;
                reverse(new_path.begin() + i, new_path.begin() + j);
                if (path_length(new_path, distances) < path_length(path, distances)) {
                    path = new_path;
                    improved = true;
                }
            }
        }
    }
    return path;
}
vector<int> update_velocity(const vector<int>& particle, const vector<int>& pbest, const vector<int>& gbest, double w) {
    vector<int> new_velocity = particle;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < particle.size(); ++i) {
        if (dis(gen) < w) continue;
        else if (dis(gen) < 0.5) new_velocity[i] = pbest[i];
        else new_velocity[i] = gbest[i];
    }
    return new_velocity;
}
vector<int> update_position(const vector<int>& particle, const vector<int>& velocity) {
    vector<int> new_particle = particle;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < particle.size(); ++i) {
        if (dis(gen) < 0.5) new_particle[i] = velocity[i];
    }
    unordered_set<int> missing_cities;
    for (int i = 0; i < new_particle.size(); ++i) missing_cities.insert(i);
    for (int city : new_particle) missing_cities.erase(city);
    for (int i = 0; i < new_particle.size(); ++i) {
        if (count(new_particle.begin(), new_particle.end(), new_particle[i]) > 1) {
            new_particle[i] = *missing_cities.begin();
            missing_cities.erase(missing_cities.begin());
        }
    }
    return new_particle;
}
vector<int> pso_tsp(const vector<City>& cities, const vector<vector<double>>& distances, int num_particles, int max_iter, int n_generation_output) {
    int num_cities = cities.size();
    auto particles = initialize_particles(num_particles, num_cities);
    auto velocities = particles;
    auto pbest = particles;
    vector<double> pbest_lengths(num_particles);
    for (int i = 0; i < num_particles; ++i) pbest_lengths[i] = path_length(particles[i], distances);
    auto gbest = pbest[min_element(pbest_lengths.begin(), pbest_lengths.end()) - pbest_lengths.begin()];
    double gbest_length = *min_element(pbest_lengths.begin(), pbest_lengths.end());
    vector<double> best_lengths;
    auto start_time = chrono::high_resolution_clock::now();
    for (int iteration = 0; iteration < max_iter; ++iteration) {
        double w = 0.9 - (0.9 - 0.4) * (iteration / max_iter);
        for (int i = 0; i < num_particles; ++i) {
            velocities[i] = update_velocity(particles[i], pbest[i], gbest, w);
            particles[i] = update_position(particles[i], velocities[i]);
            particles[i] = two_opt(particles[i], distances);
            double current_length = path_length(particles[i], distances);
            if (current_length < pbest_lengths[i]) {
                pbest[i] = particles[i];
                pbest_lengths[i] = current_length;
                if (current_length < gbest_length) {
                    gbest = particles[i];
                    gbest_length = current_length;
                }
            }
        }
        if (iteration % n_generation_output == 0) {
            auto current_time = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = current_time - start_time;
            cout << "generation:" << iteration + 1 << "  best_lengths:" << gbest_length << "  time:" << elapsed.count() << endl;
        }
    }
    return gbest;
}

int main() {
    string file_path = "att532.tsp";
    freopen("att532_result.txt","w",stdout); 
    auto cities = read_tsp_data(file_path);
    auto distance_matrix = calculate_distance_matrix(cities);
    auto best_path = pso_tsp(cities, distance_matrix, 30, 50, 1);
    cout << "Best Path: ";
    for (int city_index : best_path)   cout << city_index << " ";
    return 0;
}
