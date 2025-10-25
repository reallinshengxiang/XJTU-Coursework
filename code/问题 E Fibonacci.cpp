#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2;
const ll mod=10000;
struct matrix{
	ll m[N+1][N+1];
};
matrix operator * (const matrix &aa,const matrix &bb)
{
	matrix cc;
	memset(cc.m,0,sizeof(cc.m));
	for(ll i=1;i<=N;i++)
	{
		for(ll j=1;j<=N;j++)
		{
			for(ll k=1;k<=N;k++) cc.m[i][j]=(cc.m[i][j]+(aa.m[i][k]*bb.m[k][j]%mod))%mod;
		}
	}
	return cc;
}
matrix fastpow_matrix(matrix aa,ll n) 
{
	matrix ans;
	memset(ans.m,0,sizeof(ans.m));
	for(ll i=1;i<=N;i++) ans.m[i][i]=1;
	while(n)
	{
		if(n&1) ans=ans*aa;
		aa=aa*aa;
		n>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	matrix a;
	while(cin>>n&&n!=-1)
	{
		a.m[1][1]=a.m[1][2]=a.m[2][1]=1;
		a.m[2][2]=0;
		if(n>=1) 
		{
			a=fastpow_matrix(a,n);
			cout<<a.m[2][1]<<"\n";
		}
		else if(n==0) cout<<"0\n";
	}
	return 0;
}
