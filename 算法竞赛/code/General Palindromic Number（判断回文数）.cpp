#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,b,cnt,a[110],flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>b;
	cnt=0;
	while(n!=0)
	{
		cnt++;
		a[cnt]=n%b;
		n=n/b;
	}
	flag=1;
	for(ll i=1;i<=cnt/2;i++)
	{
		if(a[i]!=a[cnt+1-i])
		{
			cout<<"No\n";
			flag=0;
			break;
		}
	}
	if(flag) cout<<"Yes\n";
	for(ll i=cnt;i>=2;i--) cout<<a[i]<<" ";
   cout<<a[1];
	return 0;
}
