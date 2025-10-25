#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4;
struct matrix{
	ll ma[N+1][N+1];
};
ll n,mod;
matrix operator*(matrix &a,matrix &b)
{
	matrix c;
	memset(c.ma,0,sizeof(c.ma));
	for(ll i=1;i<=N;i++)
	{
		for(ll j=1;j<=N;j++)
		{
			for(ll k=1;k<=N;k++) c.ma[i][j]=(c.ma[i][j]+(a.ma[i][k]*b.ma[k][j])%mod)%mod;
		}
	}
	return c;
}
matrix matrix_pow(matrix a,ll n)
{
	matrix ans;
	memset(ans.ma,0,sizeof(ans.ma));
	for(ll i=1;i<=N;i++) ans.ma[i][i]=1;
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
	cin>>n>>mod;
	matrix a;
	memset(a.ma,0,sizeof(a.ma));
	a.ma[1][1]=a.ma[1][2]=a.ma[2][2]=a.ma[2][3]=a.ma[3][3]=a.ma[3][4]=a.ma[4][3]=1;
	a=matrix_pow(a,n);
	ll pn=a.ma[1][3];
	ll sn=a.ma[2][3];
	cout<<((n*sn-pn)%mod+mod)%mod;
	return 0;
}
