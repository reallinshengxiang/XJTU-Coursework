#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (k == 0) {
            int count0 = 0;
            for (int x : a) {
                if (x == 0) count0++;
            }
            cout << count0 << "\n";
        } else {
            vector<bool> present(k, false);
            int c = 0;
            for (int x : a) {
                if (x < k) {
                    present[x] = true;
                }
                if (x == k) {
                    c++;
                }
            }
            int missing = 0;
            for (int i = 0; i < k; i++) {
                if (!present[i]) missing++;
            }
            cout << max(missing, c) << "\n";
        }
    }
    return 0;
}
