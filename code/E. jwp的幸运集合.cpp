#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll vis[40],a[40],ans,sum,n,d[40],p,flag,q[40];
void dfs(ll num,ll step)
{
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i]&&i>d[step-1]&&(!(a[i]>=0&&sum>0))&&!q[d[1]])             
		{
			sum=sum+a[i];
			vis[i]=1;
			d[step]=i;
			if(step==num)
	        {
		       if(sum==0)   ans++;
		       if(sum>0) q[d[1]]=1;	
		       for(ll i=1;i<=step;i++) cout<<d[i]<<" ";
		       if(sum==0) cout<<"          "<<ans<<"\n";
	        }
			dfs(num,step+1);			
			sum=sum-a[i];
			vis[i]=0;
			if(step==1) q[d[1]]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i=i*2) 
	{
		memset(q,0,sizeof(q));
		flag=1;
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}
