#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=22;
ll b[N],ansb[N],a[N][N],n,m,pl[N][N],pr[N][N],f[N],ans; //f[]表示该电路板有无被使用 
//pl[i][j]表示前i块电路板中，连接块需连接的最左边的位置
//pr[i][j[表示前i块电路板中，连接块需连接的最右边的位置 
void dfs(ll len,ll step)  //len表示当前排列中step-1个电路板位置放在产生的最大距离的最小值 
{                         //step表示目前正处理到第step位置的电路板放置 
	if(ans<=len) return;  //当前的len大于等于现有的最优解，已无继续搜索的意义 
	if(step==n+1)        //完成了n个电路板位置的摆放 
	{
		if(ans>len)    //说明有更优解，记录 
		{
			ans=len;
			for(ll i=1;i<=n;i++) ansb[i]=b[i];
		}
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(f[i]) continue;   
		f[i]=1;
		b[step]=i;
		ll s=len;
		for(ll j=1;j<=m;j++)
		{
			pl[step][j]=pl[step-1][j];  
			pr[step][j]=pr[step-1][j];
			if(a[j][i]) //如果第j个连通块和当前第step个电路板i有连接 
			{           //需更新pr[step][j]、pr[step][j] 和len 
				pl[step][j]=min(pl[step][j],step);
				pr[step][j]=max(pr[step][j],step);
			    len=max(len,pr[step][j]-pl[step][j]);
			}
		}
		dfs(len,step+1);	
		len=s;	
		f[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[j][i];  
	}
	for(ll i=0;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) pl[i][j]=n;  //为pl[][]赋初值 
	}
	ans=n;
	dfs(0,1);
	cout<<ans<<"\n";
	for(ll i=1;i<=n;i++) cout<<ansb[i]<<" ";
	return 0; 
}



