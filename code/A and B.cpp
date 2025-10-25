#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout<<n<<"\n";
        //cin >> ch;
        string s;
        cin >> s;
        vector<int> a_pos, b_pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                a_pos.push_back(i);
            } else {
                b_pos.push_back(i);
            }
        }
        ll cost_a = 0, cost_b = 0;
        int cnt_a = a_pos.size();
        int cnt_b = b_pos.size();
        if (cnt_a > 0) {
            vector<int> q_a(cnt_a);
            for (int i = 0; i < cnt_a; i++) {
                q_a[i] = a_pos[i] - i;
            }
            sort(q_a.begin(), q_a.end());
            int mid = q_a[cnt_a / 2];
            for (int i = 0; i < cnt_a; i++) {
                cost_a += abs(q_a[i] - mid);
            }
        } else {
            cost_a = 0;
        }
        if (cnt_b > 0) {
            vector<int> q_b(cnt_b);
            for (int i = 0; i < cnt_b; i++) {
                q_b[i] = b_pos[i] - i;
            }
            sort(q_b.begin(), q_b.end());
            int mid = q_b[cnt_b / 2];
            for (int i = 0; i < cnt_b; i++) {
                cost_b += abs(q_b[i] - mid);
            }
        } else {
            cost_b = 0;
        }
        cout << min(cost_a, cost_b) << "\n";
    }
    return 0;
}
