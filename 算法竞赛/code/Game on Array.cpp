#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        long long alice = 0, bob = 0;
        bool alice_turn = true;
        long long prev = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == prev) continue;
            long long current = a[i];
            long long d = current - prev;
            long long k = n - i;  // 该区间内的元素数量
            
            long long cnt = (d + 1) / 2;  // 当前玩家的层数
            long long opp_cnt = d / 2;    // 对手的层数
            
            if (alice_turn) {
                alice += cnt * k;
                bob += opp_cnt * k;
            } else {
                bob += cnt * k;
                alice += opp_cnt * k;
            }
            
            // 如果层数为奇数，切换回合
            if (d % 2 == 1) {
                alice_turn = !alice_turn;
            }
            
            prev = current;
        }
        
        cout << alice << " " << bob << "\n";
    }
    
    return 0;
}

