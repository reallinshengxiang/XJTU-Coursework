#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct xs{
	ll xh;
	string xm;
	ll cj;
};
xs a[110];
ll n;
void BubbleSort(xs *a,ll n)
{
	for(ll i=1;i<=n-1;i++)
	{
		for(ll j=1;j<=n-i;j++)
		{
			if(a[j].cj<a[j+1].cj) swap(a[j],a[j+1]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)  cin>>a[i].xh>>a[i].xm>>a[i].cj;
    BubbleSort(a,n);
    for(ll i=1;i<=n;i++)
    {
    	cout<<a[i].xh<<" "<<a[i].xm<<" "<<a[i].cj;
		if(i!=n) cout<<"\n"; 
	}
	return 0;
}
