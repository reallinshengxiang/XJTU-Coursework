#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> get_lefts(int m, const vector<int>& a) {
    int nn = a.size();
    vector<int> res(nn);
    unordered_map<int, int> freq;
    int dist = 0;
    int lef = 0;
    for (int ri = 0; ri < nn; ri++) {
        if (freq[a[ri]] == 0) dist++;
        freq[a[ri]]++;
        while (dist > m && lef <= ri) {
            freq[a[lef]]--;
            if (freq[a[lef]] == 0) dist--;
            lef++;
        }
        res[ri] = lef;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        auto leftk = get_lefts(k, a);
        auto leftkm1 = get_lefts(k - 1, a);
        ll ans = 0;
        for (int right = 0; right < n; right++) {
            int L1 = leftk[right];
            int L2 = leftkm1[right] - 1;
            if (L1 > L2) continue;
            int loww = max(0, right - r + 1);
            int highh = right - l + 1;
            if (highh < loww) continue;
            int ist = max(L1, loww);
            int ien = min(L2, highh);
            if (ist <= ien) {
                ans += ien - ist + 1LL;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
