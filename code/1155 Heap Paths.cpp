#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e3+10;
ll f1,f2,a[N],ans[N],n;
map<ll,ll> mp;
void dfs(ll step,ll pos)
{
	if(pos<=n)	ans[step]=a[pos];
	if(pos*2>n)
	{
		for(ll i=1;i<=step;i++) 
		{
			if(i!=1)
			{
				if(ans[i]<=ans[i-1]) f2=1;
				if(ans[i]>=ans[i-1]) f1=1;
				cout<<" "<<ans[i];
			}
			else cout<<ans[i];
		}
		cout<<"\n";
		return;
	}
	if(pos*2+1<=n) dfs(step+1,pos*2+1);
	if(pos*2<=n) dfs(step+1,pos*2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	dfs(1,1);
	if(!f1&&f2) cout<<"Max Heap";
	else if(f1&&!f2) cout<<"Min Heap";
	else cout<<"Not Heap";
	return 0;
} 
