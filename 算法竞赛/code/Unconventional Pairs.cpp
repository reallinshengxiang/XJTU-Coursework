#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n; i += 2) {
            ll diff = a[i+1] - a[i];
            if (diff > ans) {
                ans = diff;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
