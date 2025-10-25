#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
    int countComponents() {
        set<int> comps;
        // 将循环变量i改为size_t（无符号类型），与parent.size()类型匹配
        for (size_t i = 0; i < parent.size(); i++) {
            comps.insert(find(i));
        }
        return comps.size();
    }
};

int main() {
    int N;
    cin >> N;
    vector<pair<pair<int, int>, pair<int, int>>> edges;
    set<pair<int, int>> points_set;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pair<int, int> p1 = make_pair(x1, y1);
        pair<int, int> p2 = make_pair(x2, y2);
        edges.push_back(make_pair(p1, p2));
        points_set.insert(p1);
        points_set.insert(p2);
    }

    map<pair<int, int>, int> idx_map;
    int idx = 0;
    for (auto p : points_set) {
        idx_map[p] = idx++;
    }

    int V = points_set.size();
    DSU dsu(V);

    for (auto e : edges) {
        auto p1 = e.first;
        auto p2 = e.second;
        int id1 = idx_map[p1];
        int id2 = idx_map[p2];
        if (id1 != id2) {
            dsu.unionSet(id1, id2);
        }
    }

    int C = dsu.countComponents();
    int E = N;
    int result = E - V + C;
    cout << result ;

    return 0;
}
