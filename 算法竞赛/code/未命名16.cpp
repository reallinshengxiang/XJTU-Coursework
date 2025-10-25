#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k, n;
	cin >> n>>k;
	string d;
	cin >> d;
	list<char> li(d.begin(), d.end());
	list<char>::iterator it1 = li.begin(), it2 = li.begin();
	for (int i = 0; i < k; i++)
	{
		for (++it2; it2 != li.end(); ++it1, ++it2)
		{
			if (*it1 <= *it2) continue;
			it2 = it1 = --li.erase(it1);
			break;
		}
	};
	for (it1 = li.begin(); it1 != li.end(); ++it1) cout << *it1;
	return 0;
}

