#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans1,ans2,l,r,x1,x2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l>>r;
	x1=l;
	x2=r; 
	while(x1%2==0) x1++;
	while(x2%2==0) x2--;
	if(x1>x2) ans1=0;
	else ans1=(x2-x1)/2+1;
	x1=l;
	x2=r;
	while(x1%4!=0) x1++;
	while(x2%4!=0) x2--;
	if(x1>x2) ans2=0;
	else ans2=(x2-x1)/4+1;
	cout<<ans1+ans2;
	return 0;
}
