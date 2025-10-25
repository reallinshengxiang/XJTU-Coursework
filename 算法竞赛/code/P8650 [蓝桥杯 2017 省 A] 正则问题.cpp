#include<bits/stdc++.h>
using namespace std;
#define ll long long
char x;
ll dfs()
{
	ll num=0;
	while(cin>>x)
	{
		if(x=='(') num=num+dfs();
		else if(x=='x') num++;
		else if(x==')') return num;
		else if(x=='|') return max(num,dfs());
	}
	return num;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<dfs();
	return 0;
}
