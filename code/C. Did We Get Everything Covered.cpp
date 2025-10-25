#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll T,n,k,m,a[N],pos[30][N],num[30][30],flag,st,ed,pr,pl,ff[30];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>m>>s;
		memset(pos,0,sizeof(pos));
		memset(num,0,sizeof(num));
		for(ll i=0;i<=m-1;i++)	
		{
			a[i]=s[i]-96;
			pos[a[i]][++pos[a[i]][0]]=i;
		}
		flag=1;
		for(ll i=1;i<=k;i++)
		{
			if(pos[i][0]<k)
			{
				flag=0;
				cout<<"NO\n";
				for(ll ii=1;ii<=k;ii++) cout<<char(i+96);
				cout<<"\n";
				break;
			}
		}
		if(!flag) continue;
		for(ll i=0;i<=m-1;i++) num[i][a[i]]++;
		for(ll i=1;i<=k&&flag;i++)
		{
			for(ll len=k-2;len>=1&&flag;len--)
			{
				for(ll st=1;st+len+1<=pos[i][0]&&flag;st++)
				{
					ed=st+len+1;
					pl=pos[i][st];
					pr=pos[i][ed];
					for(ll j=1;j<=k&&flag;j++)
					{
						if(i==j) continue;
					    if(num[pr][j]-num[pl][j]<len)
					    {
							flag=0;
							cout<<"NO\n";
							for(ll ii=1;ii<=st;ii++) cout<<char(i+96);
				            for(ll ii=1;ii<=len;ii++) cout<<char(j+96);
				            for(ll ii=ed;ii<=pos[i][0];ii++) cout<<char(i+96);
				            cout<<"\n";
				            break;
						}						
					}					
				}
			}
		}
		if(flag) cout<<"YES\n";
	}
	return 0;
}
