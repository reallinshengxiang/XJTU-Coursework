#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<vector<int>> positions;
vector<int> comp, vals;

void build(int node, int start, int end) {
    int sz = end - start + 1;
    int thresh = sz / 3;
    if (start == end) {
        tree[node] = {{comp[start], 1}};
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    auto& lh = tree[2 * node];
    auto& rh = tree[2 * node + 1];
    set<int> cand_set;
    for (auto& p : lh) cand_set.insert(p.first);
    for (auto& p : rh) cand_set.insert(p.first);
    vector<pair<int, int>> nh;
    for (int id : cand_set) {
        auto& ps = positions[id];
        auto it1 = lower_bound(ps.begin(), ps.end(), start);
        auto it2 = lower_bound(it1, ps.end(), end + 1);
        int ftot = it2 - it1;
        if (ftot > thresh) {
            nh.emplace_back(id, ftot);
        }
    }
    tree[node] = nh;
}

void get_heavies(int node, int start, int end, int ql, int qr, set<int>& cands) {
    if (ql > end || qr < start) return;
    if (ql <= start && end <= qr) {
        for (auto& p : tree[node]) {
            cands.insert(p.first);
        }
        return;
    }
    int mid = (start + end) / 2;
    get_heavies(2 * node, start, mid, ql, qr, cands);
    get_heavies(2 * node + 1, mid + 1, end, ql, qr, cands);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        set<int> uniq;
        for (int i = 1; i <= n; i++) uniq.insert(a[i]);
        vals.assign(uniq.begin(), uniq.end());
        int d = vals.size();
        map<int, int> compress;
        for (int i = 0; i < d; i++) {
            compress[vals[i]] = i + 1;
        }
        comp.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            comp[i] = compress[a[i]];
        }
        positions.assign(d + 1, {});
        for (int i = 1; i <= n; i++) {
            positions[comp[i]].push_back(i);
        }
        int N = 4 * (n + 1);
        tree.assign(N, {});
        build(1, 1, n);
        for (int iq = 0; iq < q; iq++) {
            int l, r;
            cin >> l >> r;
            set<int> cands;
            get_heavies(1, 1, n, l, r, cands);
            int len_ = r - l + 1;
            int thresh = len_ / 3;
            vector<int> high;
            for (int id : cands) {
                auto& ps = positions[id];
                auto it1 = lower_bound(ps.begin(), ps.end(), l);
                auto it2 = lower_bound(it1, ps.end(), r + 1);
                int cnt = it2 - it1;
                if (cnt > thresh) {
                    high.push_back(vals[id - 1]);
                }
            }
            if (high.empty()) {
                cout << -1 << '\n';
            } else {
                sort(high.begin(), high.end());
                for (size_t j = 0; j < high.size(); j++) {
                    if (j > 0) cout << " ";
                    cout << high[j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
