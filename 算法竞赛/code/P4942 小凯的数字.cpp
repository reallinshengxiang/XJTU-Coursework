#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,ans,l,r,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		l=l%9;
		r=r%9;
		if(r<l) r=r+9;
		ans=0;
		for(ll i=l;i<=r;i++) ans=ans+i;
		cout<<ans%9<<"\n";
	}
	return 0;
}
