#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> singles;
        for (int i = 0; i < n; i++) {
            bool is_single = (s[i] == '0');
            if (i > 0) is_single &= (s[i - 1] != '0');
            if (i < n - 1) is_single &= (s[i + 1] != '0');
            if (is_single) singles.push_back(i);
        }
        bool possible = true;
        size_t idx = 0;
        while (idx < singles.size() && possible) {
            size_t start = idx;
            while (idx + 1 < singles.size() && singles[idx + 1] == singles[idx] + 2) ++idx;
            int m = idx - start + 1;
            int first = singles[start];
            int last = singles[idx];
            bool opt_l = (first == 0) || (first >= 2 && s[first - 2] == '0');
            bool opt_r = (last == n - 1) || (last + 2 < n && s[last + 2] == '0');
            bool can = (m % 2 == 0) || ((opt_l || opt_r) && (m % 2 == 1));
            if (!can) possible = false;
            ++idx;
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}
