#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool canReach(ll h, ll d, ll rests) {
    ll segments = rests + 1;
    ll base_moves = d / segments;
    ll remainder = d % segments;
    ll penalty = (segments - remainder) * (base_moves * (base_moves + 1)) / 2
                 + remainder * ((base_moves + 1) * (base_moves + 2)) / 2;
    return (h + rests) > penalty;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll h, d;
        cin >> h >> d;
        
        ll left = 0, right = 1e10; 
        ll answer = right;
        
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            
            if (canReach(h, d, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << d + answer << "\n";
    }
    
    return 0;
}
