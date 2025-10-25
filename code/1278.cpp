#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
string s;
vector<ll> ailnoq[7];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='A') ailnoq[1].push_back(i);
		else if(s[i]=='I') ailnoq[2].push_back(i);
		else if(s[i]=='L') ailnoq[3].push_back(i);
		else if(s[i]=='N') ailnoq[4].push_back(i);
		else if(s[i]=='O') ailnoq[5].push_back(i);
		else if(s[i]=='Q') ailnoq[6].push_back(i);
	}
	/*for(ll i=1;i<=6;i++)
	{
		for(ll j=0;j<ailnoq[i].size();j++) cout<<ailnoq[i][j]<<" ";
		cout<<"\n";
	}*/
	for(ll p1=0;p1<ailnoq[3].size();p1++)
	{
		for(ll p2=0;p2<ailnoq[1].size();p2++)
		{
			if(ailnoq[1][p2]<ailnoq[3][p1]) continue;
			for(ll p3=0;p3<ailnoq[4].size();p3++)
			{
				if(ailnoq[4][p3]<ailnoq[1][p2]) continue;
				for(ll p4=0;p4<ailnoq[6].size();p4++)
				{
					if(ailnoq[6][p4]<ailnoq[4][p3]) continue;
					for(ll p5=0;p5<ailnoq[2].size();p5++)
					{
						if(ailnoq[2][p5]<ailnoq[6][p4]) continue;
						for(ll p6=0;p6<ailnoq[1].size();p6++)
						{
							if(ailnoq[1][p6]<ailnoq[2][p5]) continue;
							for(ll p7=0;p7<ailnoq[5].size();p7++)
							{
								if(ailnoq[5][p7]<ailnoq[1][p6]) continue;
								cout<<"YES"; 
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout<<"NO";
	return 0;
} 
