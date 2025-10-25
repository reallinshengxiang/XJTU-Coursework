#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=12;
ll n,c,x[N],f[N],a[N],flag;  //flag表示是否找到解 
void print(ll nn)    //输出最优解 
{
	for(ll i=1;i<=nn;i++) cout<<a[i]<<" ";
}
void dfs(ll sum,ll step)
{
	if(sum>c) return;   
	if(sum==c)
	{
		flag=1;         //有解，flag=1 
		print(step);
		exit(0);
	}
	for(ll i=1;i<=n&&sum+x[i]<=c;i++)//因为此时的x[]单调递增，若当前的x[i]+sum>c,
	{  //说明接下来x[i+1],x[i+2]……x[n]肯定不合题意，没有枚举的必要 
		if(f[i]) continue;
		f[i]=1;
		a[step]=x[i];    
		dfs(sum+x[i],step+1);
		f[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>c;      //n表示S的大小，c是子集和的目标值 
	for(ll i=1;i<=n;i++) cin>>x[i];   //输入S的元素 
	sort(x+1,x+n+1);   //将S中的元素由小到大排列，为之后的优化做准备 
	dfs(0,1);          //从第一个位置开始进行深度优先搜索 
	if(!flag) cout<<"No solution!";  //flag=0,说明无解 
	return 0;
}


