#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) : p(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) p[x] = y;
    }
};

vector<double> gauss(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    vector<vector<double>> a(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = A[i][j];
        }
        a[i][n] = b[i];
    }
    for (int col = 0; col < n; col++) {
        int maxr = col;
        for (int i = col + 1; i < n; i++) {
            if (fabs(a[i][col]) > fabs(a[maxr][col])) maxr = i;
        }
        swap(a[col], a[maxr]);
        if (fabs(a[col][col]) < 1e-12) continue;
        for (int i = col + 1; i < n; i++) {
            double c = a[i][col] / a[col][col];
            for (int j = col; j <= n; j++) {
                a[i][j] -= c * a[col][j];
            }
        }
    }
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        if (fabs(a[i][i]) < 1e-12) {
            x[i] = 0; // assume
            continue;
        }
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> g(N);
    for (int i = 0; i < N; i++) {
        cin >> g[i];
    }
    pair<int, int> op, cl;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j] == '.') {
                if (cnt == 0) op = {i, j};
                else cl = {i, j};
                cnt++;
            }
        }
    }
    int NR = N + 1;
    int total = NR * NR;
    DSU dsu(total);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (g[r][c] == '+' || g[r][c] == '.') {
                int n1 = r * NR + c;
                int n2 = r * NR + (c + 1);
                int n3 = (r + 1) * NR + c;
                int n4 = (r + 1) * NR + (c + 1);
                dsu.unite(n1, n2);
                dsu.unite(n1, n3);
                dsu.unite(n1, n4);
            }
        }
    }
    int s_node = op.first * NR + op.second;
    int t_node = (cl.first + 1) * NR + (cl.second + 1);
    int s_comp_raw = dsu.find(s_node);
    int t_comp_raw = dsu.find(t_node);
    if (s_comp_raw == t_comp_raw) {
        cout << 0 << endl;
        return 0;
    }
    set<int> roots;
    for (int i = 0; i < total; i++) {
        roots.insert(dsu.find(i));
    }
    int num = roots.size();
    map<int, int> comp_to_id;
    int cid = 0;
    for (int rt : roots) {
        comp_to_id[rt] = cid++;
    }
    auto get_comp = [&](int node) {
        return comp_to_id[dsu.find(node)];
    };
    int sc = get_comp(s_node);
    int tc = get_comp(t_node);
    vector<vector<double>> conductance(num, vector<double>(num, 0.0));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (g[r][c] == '-') {
                int u = r * NR + c;
                int v = r * NR + (c + 1);
                int cu = get_comp(u);
                int cv = get_comp(v);
                if (cu != cv) {
                    conductance[cu][cv] += 1.0;
                    conductance[cv][cu] += 1.0;
                }
            } else if (g[r][c] == '|') {
                int u = r * NR + c;
                int v = (r + 1) * NR + c;
                int cu = get_comp(u);
                int cv = get_comp(v);
                if (cu != cv) {
                    conductance[cu][cv] += 1.0;
                    conductance[cv][cu] += 1.0;
                }
            }
        }
    }
    vector<int> floats;
    for (int i = 0; i < num; i++) {
        if (i != sc && i != tc) floats.push_back(i);
    }
    int varn = floats.size();
    if (varn == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<double>> A(varn, vector<double>(varn, 0.0));
    vector<double> b(varn, 0.0);
    for (int idx = 0; idx < varn; idx++) {
        int k = floats[idx];
        double sum_g = 0.0;
        for (int l = 0; l < num; l++) {
            sum_g += conductance[k][l];
        }
        A[idx][idx] = sum_g;
        for (int jdx = 0; jdx < varn; jdx++) {
            int l = floats[jdx];
            A[idx][jdx] -= conductance[k][l];
        }
        b[idx] = conductance[k][sc] * 1.0;
    }
    vector<double> V_float = gauss(A, b);
    map<int, double> voltages;
    voltages[sc] = 1.0;
    voltages[tc] = 0.0;
    for (int idx = 0; idx < varn; idx++) {
        voltages[floats[idx]] = V_float[idx];
    }
    double Is = 0.0;
    for (int l = 0; l < num; l++) {
        Is += conductance[sc][l] * (1.0 - voltages[l]);
    }
    double req = (Is > 1e-12) ? 1.0 / Is : 0.0;
    cout << (int)round(req);
    return 0;
}

/*
4
.-+-
--|-
+-+-
|-+.

5
.-+-+
--|-|
--|-|
--|-|
--+-.
*/ 
