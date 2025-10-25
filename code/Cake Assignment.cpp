#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll k, x;
        cin >> k >> x;
        ll base = 1LL << k;
        ll M = base * 2;
        if (x == base) {
            cout << 0 << endl;
            continue;
        }
        vector<int> ops;
        ll a = x;
        while (a != base) {
            if (a <= base) {
                ops.push_back(1);
                a *= 2;
            } else {
                ops.push_back(2);
                a = 2 * a - M;
            }
        }
        cout << ops.size() << endl;
        if (!ops.empty()) {
            reverse(ops.begin(), ops.end());
            for (size_t i = 0; i < ops.size(); i++) {
                if (i > 0) cout << " ";
                cout << ops[i];
            }
            cout << endl;
        }
    }
    return 0;
}
