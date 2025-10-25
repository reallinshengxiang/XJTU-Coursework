#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, vector<vector<string>>> recipes;
map<string, ll> cost;
set<string> visiting;

ll solve(const string& potion) {
    if (cost.find(potion) != cost.end()) {
        return cost[potion];
    }
    if (recipes.find(potion) == recipes.end()) {
        return cost[potion] = 0;
    }
    if (visiting.find(potion) != visiting.end()) {
        return 1e18;
    }
    visiting.insert(potion);
    ll min_cost = 1e18;
    for (auto& r : recipes[potion]) {
        ll total = r.size() - 1;
        for (auto& ing : r) {
            ll c = solve(ing);
            if (c >= 1e18) {
                total = 1e18;
                break;
            }
            total += c;
        }
        if (total < min_cost) {
            min_cost = total;
        }
    }
    visiting.erase(potion);
    return cost[potion] = min_cost;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        size_t pos = s.find('=');
        string potion = s.substr(0, pos);
        string rest = s.substr(pos + 1);
        vector<string> ingredients;
        size_t start = 0;
        size_t plus_pos;
        while ((plus_pos = rest.find('+', start)) != string::npos) {
            ingredients.push_back(rest.substr(start, plus_pos - start));
            start = plus_pos + 1;
        }
        ingredients.push_back(rest.substr(start));
        recipes[potion].push_back(ingredients);
    }
    string target;
    getline(cin, target);
    ll ans = solve(target);
    cout << ans;
    return 0;
}


