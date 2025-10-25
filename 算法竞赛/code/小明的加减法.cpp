#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll x,y,f1,f2,a,b,ans1,ans2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x>>y;
	a=(x+y)/2;
	b=x-a;
	f1=f2=1;
	if(a<0) f1=-1;
	if(b<0) f2=-1;
	a=abs(a);
	b=abs(b);
	while(a!=0)
	{
		ans1=ans1*10+a%10;
		a=a/10;
	}
	while(b!=0)
	{
		ans2=ans2*10+b%10;
		b=b/10;
	}
	cout<<f1*ans1+f2*ans2<<" "<<f1*ans1-f2*ans2;
	return 0;
}
