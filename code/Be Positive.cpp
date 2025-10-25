#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int count_zero = 0; 
        int count_neg = 0;  
        
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 0) {
                count_zero++;
            } else if (x == -1) {
                count_neg++;
            }
        }
        int ops = count_zero;
        if (count_neg % 2 != 0) {
            ops += 2;
        }
        
        cout << ops << '\n';
    }
    return 0;
}

