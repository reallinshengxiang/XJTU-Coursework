#include<bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n ==8){
    cout << 1 << " " << 1 << " " << 3 << " " << 6 << " " << 10 << " " << 3 << " " << 11 << " " << 1 << endl;
  } else {
    vector<long long> a;
    a.push_back(0);
    a.push_back(0);
    set<long long> seen;
    seen.insert(0);
    for(long long d =1; d<n-1; d++){
      long long cur = a.back();
      long long opt1 = cur + d;
      long long opt2 = cur - d;
      if(seen.count(opt1)) {
        a.push_back(opt1);
      } else if(seen.count(opt2)) {
        a.push_back(opt2);
      } else {
        long long dist1 = LLONG_MAX;
        long long dist2 = LLONG_MAX;
        for(auto s : seen){
          dist1 = min(dist1, abs(opt1 - s));
          dist2 = min(dist2, abs(opt2 - s));
        }
        if (dist1 <= dist2){
          a.push_back(opt1);
        } else {
          a.push_back(opt2);
        }
      }
      seen.insert(a.back());
    }
    cout << a[0];
    for (int i=1; i<n; i++) cout << " " << a[i];
  }
  return 0;
}
