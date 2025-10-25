#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m;
struct matrix{
	ll m[101][101];
};
ll x;
matrix operator*(const matrix &a,const matrix &b)
{
	matrix c;
	memset(c.m,0,sizeof(c.m));
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll k=1;k<=n;k++) c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j]%mod)%mod;
		}
	}
	return c;
} 
matrix pow_matrix(matrix a,ll k)
{
	matrix ans;
	memset(ans.m,0,sizeof(ans.m));
	for(ll i=0;i<=n;i++) ans.m[i][i]=1;
	while(k)
	{
		if(k&1) ans=ans*a;
		a=a*a;
		k>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k;
    cin>>n>>m>>k;
    matrix aa;
    while(m--)
    {
    	ll x,y;
    	cin>>x>>y;
    	aa.m[x][y]++;
    	aa.m[y][x]++;
	}
	aa=pow_matrix(aa,k);
	cout<<(aa.m[1][n]%mod);
	return 0;
}
