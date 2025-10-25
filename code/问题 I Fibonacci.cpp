#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2;
const ll mod=10000;
struct matrix{
	ll m[N+1][N+1];
};
ll x;
matrix operator*(const matrix &a,const matrix &b)
{
	matrix c;
	memset(c.m,0,sizeof(c.m));
	for(ll i=1;i<=N;i++)
	{
		for(ll j=1;j<=N;j++)
		{
			for(ll k=1;k<=N;k++) c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j]%mod)%mod;
		}
	}
	return c;
} 
matrix pow_matrix(matrix a,ll n)
{
	matrix ans;
	memset(ans.m,0,sizeof(ans.m));
	for(ll i=0;i<=N;i++) ans.m[i][i]=1;
	while(n)
	{
		if(n&1) ans=ans*a;
		a=a*a;
		n>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>x)
	{
		if(x==-1) break;
		matrix aa;
		aa.m[1][1]=aa.m[1][2]=aa.m[2][1]=1;
		aa.m[2][2]=0;
		aa=pow_matrix(aa,x);
		cout<<aa.m[2][1]%mod<<"\n";
	}
	return 0;
}
