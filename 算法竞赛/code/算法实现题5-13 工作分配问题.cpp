#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=21;
ll ans,f[N],c[N][N],n;  //f[]记录当前工作有无被选用 
void dfs(ll sum,ll step) //sum表示在当前情况下的费用和，step表示当前正在分配第step个人的工作 
{
	if(sum>=ans) return; //当前解已超过最优解，无继续搜索的意义 
	if(step==n+1)        //已经完成了step个人的工作分配 
	{
		ans=min(ans,sum); //将sum和ans比较，找出更优解 
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(f[i]) continue;
		f[i]=1;
		sum=sum+c[step][i]; 
		dfs(sum,step+1);
		sum=sum-c[step][i];
		f[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;  //n表示工作数和人数 
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cin>>c[i][j]; //c[i][j]表示将工作i分配给第j人的费用 
	}
	for(ll i=1;i<=n;i++) ans=ans+c[i][i]; //由于不知输入参数的数据范围，这里任取一种方案给ans赋初值 
	dfs(0,1);    //从第一个人开始进行深度优先搜索 
	cout<<ans;   //输出最优解 
	return 0;
} 




