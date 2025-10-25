#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct student{
	ll xuehao;
	double xueye,suzhi,zonghe,zongfen;
};
student a[1100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].xuehao>>a[i].xueye>>a[i].suzhi;
		a[i].zonghe=a[i].xueye*0.7+a[i].suzhi*0.3;
		a[i].zongfen=a[i].xueye+a[i].suzhi;
	}
	for(ll i=1;i<=n;i++)
	{
		if((a[i].zongfen>140)&&(a[i].zonghe>=80)) cout<<"Excellent\n";
		else cout<<"Not excellent\n";
	}
	return 0;
}
