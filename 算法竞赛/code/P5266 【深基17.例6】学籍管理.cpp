#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<string,ll> mp;
ll n,x,cj,num;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		if(x==1)
		{
			cin>>s>>cj;
			if(mp[s]<=0) num++;
			mp[s]=cj;
			cout<<"OK\n";
		}
		else if(x==2)
		{
			cin>>s;
			if(mp[s]<=0) cout<<"Not found\n";
			else cout<<mp[s]<<"\n";
		}
		else if(x==3)
		{
			cin>>s;
			if(mp[s]<=0) cout<<"Not found\n";
			else 
			{
				mp[s]=-1;
				num--;
				cout<<"Deleted successfully\n";
			}
		}
		else if(x==4) cout<<num<<"\n";
	}
	return 0;
}
