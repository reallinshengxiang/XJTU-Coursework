#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=12;
ll n,x[N],c,sum,flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>c;
	for(ll i=1;i<=n;i++) cin>>x[i];
	sort(x+1,x+n+1);
	do{
		sum=0;
		for(ll i=1;i<=n;i++) 
		{
			sum=sum+x[i];
			if(sum==c) 
			{
				for(ll j=1;j<=i;j++) cout<<x[j]<<" ";
				return 0; 
			}
			else if(sum>c) break;
		}		
	}while(next_permutation(x+1,x+n+1));
	if(!flag) cout<<"No solution!";
	return 0;
}
