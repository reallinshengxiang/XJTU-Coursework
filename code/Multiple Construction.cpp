#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 1; i <= 2 * n; i++) {
            s.insert(i);
        }
        vector<int> ans(2 * n + 1, 0);
        bool valid = true;
        for (int x = n; x >= 1; x--) {
            if (s.empty()) {
                valid = false;
                break;
            }
            auto it = s.end();
            it--;
            int j = *it;
            s.erase(j);
            int i = j - x;
            while (i > 0 && s.find(i) == s.end()) {
                i -= x;
            }
            if (i <= 0) {
                valid = false;
                break;
            }
            ans[i] = x;
            ans[j] = x;
            s.erase(i);
        }
        if (!valid) {
            cout << -1 << endl;
        } else {
            for (int i = 1; i <= 2 * n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

/*
3
2
3
1
*/ 
