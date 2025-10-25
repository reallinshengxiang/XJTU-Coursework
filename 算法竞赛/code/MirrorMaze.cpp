#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<char>> grid(M, vector<char>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '0') continue;
            for (int d0 = 0; d0 < 4; d0++) {
                set<pair<int, int>> visited_cells;
                set<pair<pair<int, int>, int>> visited_states;
                int cur_i = i, cur_j = j, cur_d = d0;
                visited_states.insert({{cur_i, cur_j}, cur_d});
                visited_cells.insert({cur_i, cur_j});
                while (true) {
                    char c = grid[cur_i][cur_j];
                    int d_out;
                    if (c == '0') {
                        d_out = cur_d;
                    } else if (c == '/') {
                        if (cur_d == 0) d_out = 3;
                        else if (cur_d == 1) d_out = 2;
                        else if (cur_d == 2) d_out = 1;
                        else if (cur_d == 3) d_out = 0;
                    } else if (c == '\\') {
                        if (cur_d == 0) d_out = 1;
                        else if (cur_d == 1) d_out = 0;
                        else if (cur_d == 2) d_out = 3;
                        else if (cur_d == 3) d_out = 2;
                    }
                    int ni = cur_i + dx[d_out];
                    int nj = cur_j + dy[d_out];
                    if (ni < 0 || ni >= M || nj < 0 || nj >= N) {
                        break;
                    }
                    int next_d = (d_out + 2) % 4;
                    if (ni == i && nj == j && next_d == d0) {
                        ans = max(ans, (int)visited_cells.size());
                        break;
                    }
                    auto next_state = make_pair(make_pair(ni, nj), next_d);
                    if (visited_states.find(next_state) != visited_states.end()) {
                        break;
                    }
                    cur_i = ni;
                    cur_j = nj;
                    cur_d = next_d;
                    visited_states.insert(next_state);
                    visited_cells.insert({cur_i, cur_j});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
5 5
/ / 0 0 \
0 0 0 / 0
0 \ 0 0 /
\ / \ / 0
0 0 \ \ \
10

6 6
0 0 0 0 / \
/ 0 / 0 / 0
0 \ 0 \ / 0
0 / \ \ / 0
0 / \ / 0 0
0 0 / \ 0 /
0
*/
