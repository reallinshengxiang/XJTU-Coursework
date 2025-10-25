#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k, x;
        cin >> k;
        while (k--) cin >> x;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) ans = ans * i % 19961;
    printf("%d\n", ans);
    return 0;
}
