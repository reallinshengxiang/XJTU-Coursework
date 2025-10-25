#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            cout << 0 << endl;
            continue;
        }
        if (y == 0 && x >= 1) {
            cout << 1 << endl;
            continue;
        }
        ll n_max = 2 * sqrt(x) + 100;
        bool found = false;
        for (ll n = 2; n <= n_max; n++) {
            ll k = (n + 1) / 2;
            ll A = k * k;
            if (A > x) break;
            ll T = n * (n + 1) / 2;
            if (T > x + y) break;
            ll l = n / 2;
            ll B = l * (l + 1);
            if (y < B) continue;
            ll E = x + y - T;
            if (n % 2 == 0) {
                if (x - A <= E / 2) {
                    cout << n << endl;
                    found = true;
                    break;
                }
            } else {
                if (x - A >= E - E / 2 && x - A <= E) {
                    cout << n << endl;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}










/*
10
1 2
5 6
4 2
1 1
2 1
3 3
5 1
5 4
752 18572
95152 2322
*/
