#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for(int tt = 0; tt < t; tt++) {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    long long OR_all = 0;
    vector<int> cnt(32, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      OR_all |= a[i];
      for(int k = 0; k < 32; k++) {
        if(a[i] & (1LL << k)) cnt[k]++;
      }
    }
    int cur = 0;
    for(int k = 0; k < 32; k++) if(OR_all & (1LL << k)) cur++;
    vector<long long> costs;
    for(int k = 0; k < 32; k++) {
      if((OR_all & (1LL << k)) == 0) {
        long long mc = 1LL << 60;
        for(int i = 0; i < n; i++) {
          bool is_safe = true;
          for(int m = 0; m < k; m++) {
            if((a[i] & (1LL << m)) && cnt[m] == 1) {
              is_safe = false;
              break;
            }
          }
          if(is_safe) {
            long long low = a[i] & ((1LL << k) - 1);
            long long c = (1LL << k) - low;
            mc = min(mc, c);
          }
        }
        if(mc == (1LL << 60)) {
          mc = (1LL << k);
        }
        costs.push_back(mc);
      }
    }
    sort(costs.begin(), costs.end());
    vector<long long> pre(costs.size() + 1, 0);
    for(size_t i = 1; i <= costs.size(); i++) {
      pre[i] = pre[i - 1] + costs[i - 1];
    }
    for(int iq = 0; iq < q; iq++) {
      long long b;
      cin >> b;
      auto it = upper_bound(pre.begin(), pre.end(), b);
      int r = it - pre.begin() - 1;
      cout << cur + r << '\n';
    }
  }
  return 0;
}
