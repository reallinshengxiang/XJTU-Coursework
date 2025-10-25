#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10; // 最多 10000 人

map<int, int> sex; // 性别映射：0 表示男孩，1 表示女孩
vector<int> friends[N]; // 邻接表存储朋友关系

// 将字符串转换为整数，并处理性别
int to_int(string s) {
    int flag = 1;
    if (s[0] == '-') {
        flag = -1;
        s = s.substr(1);
    }
    int id = stoi(s);
    sex[id] = (flag == -1); // 女孩标记为 1
    return id;
}

// 格式化输出 ID
void print_id(int id) {
    printf("%04d", id);
}

int main() {
    int n, m;
    cin >> n >> m;

    // 输入朋友关系
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int u = to_int(s1);
        int v = to_int(s2);
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        a = abs(a); // 取绝对值
        b = abs(b); // 取绝对值

        // 找到 A 的所有同性朋友
        vector<int> a_friends;
        for (int u : friends[a]) {
            if (sex[u] == sex[a] && u != b) { // 同性且不是 B
                a_friends.push_back(u);
            }
        }

        // 找到 B 的所有同性朋友
        vector<int> b_friends;
        for (int v : friends[b]) {
            if (sex[v] == sex[b] && v != a) { // 同性且不是 A
                b_friends.push_back(v);
            }
        }

        // 检查朋友对是否满足条件
        vector<pair<int, int>> ans;
        for (int u : a_friends) {
            for (int v : b_friends) {
                // 检查 u 和 v 是否是朋友
                bool is_friend = false;
                for (int x : friends[u]) {
                    if (x == v) {
                        is_friend = true;
                        break;
                    }
                }
                if (is_friend) {
                    ans.push_back({u, v});
                }
            }
        }

        // 按题目要求排序
        sort(ans.begin(), ans.end());

        // 输出结果
        cout << ans.size() << endl;
        for (auto p : ans) {
            print_id(p.first);
            cout << " ";
            print_id(p.second);
            cout << endl;
        }
    }

    return 0;
}
