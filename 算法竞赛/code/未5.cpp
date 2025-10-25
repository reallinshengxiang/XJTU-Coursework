#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
#define ull unsigned long long
const ll N=1e5+10;
ull PP=131;
ll n,q,num;
ull p[N],h[N];
string s;
vector<ll> e[30];
map<ll,ll> mp[30],vis;
ll sum[N][30];
ull get_hash(ll l,ll r)
{
	return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	cin>>s; 
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=26;j++) sum[i][j]=sum[i-1][j];
		sum[i][s[i-1]-'a'+1]++;
		mp[s[i-1]-'a'+1][i-1]=1;
		e[s[i-1]-'a'+1].push_back(i-1);
	}
	p[0]=1;
	//for(ll i=1;i<=n-1;i++) p[i]=p[i-1]*PP;
	//for(ll i=1;i<=n;i++) h[i]=(s[i-1]-'a')+h[i-1]*PP;
	while(q--)
	{
		ll l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		/*ull x=get_hash(l1,r1);
		ull y=get_hash(l2,r2);
		vis.clear();
		if(x==y)
		{
			cout<<"0\n\n";
			continue;
		}*/
		l1--;
		r1--;
		l2--;
		r2--;
		num=0;
		for(ll i=1;i<=26;i++)
		{
			if(sum[r1+1][i]-sum[l1][i]!=sum[r2+1][i]-sum[l2][i]) vis[i]=1,num++;
			else if(sum[r1+1][i]-sum[l1][i])
			{
				/*ll pos=0;
				for(ll j=0;j<e[i].size();j++)
				{
					if(e[i][j]>=l1)
					{
						pos=j;
						break;
					}
				}*/
				ll pos=0,pl=0,pr=e[i].size()-1,mid;
				while(pl<=pr)
				{
					mid=(pl+pr)/2;
					if(e[i][mid]>=l1) pr=mid-1,pos=mid;
					else pl=mid+1;
				}
				for(ll j=pos;j<e[i].size();j++)
				{
				    if(e[i][j]>r1) break;
					if(mp[i][e[i][j]+l2-l1]==0) 
					{
						vis[i]=1,num++;
						break;		
					}		
				}
			}
		}
		if(num==0)
		{
			cout<<"0\n\n";
			continue;
		}
		cout<<num<<"\n";
		for(ll i=1;i<=26;i++)
		{
			if(vis[i]) cout<<char('a'-1+i);
		}
		cout<<"\n";
	}
	return 0;
} 
