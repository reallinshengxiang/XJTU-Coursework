#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=300005;
char s[N];
ll sa[N],rk[N],height[N],tmp[N+1],n,k,t1[N],t2[N],cnt[N];
bool cmp_sa(ll i,ll j)
{
	if(rk[i]!=rk[j]) return rk[i]<rk[j];
	else
	{
		ll ri,rj;
		if(i+k<=n) ri=rk[i+k];
		else ri=-1;
		if(j+k<=n) rj=rk[j+k];
		else rj=-1;
        return ri<rj;
	}
} 
void calc_sa() { 
    ll m = 127;
    ll i,*x=t1,*y=t2;
    for(i=0;i<m;i++)   cnt[i]=0;
    for(i=0;i<n;i++)    cnt[x[i]=s[i]]++;
    for(i=1;i<m;i++)   cnt[i]+=cnt[i-1];
    for(i=n-1;i>=0;i--)  sa[--cnt[x[i]]]=i;
    for(int k=1;k<=n;k=k*2)
	{ 
        ll p=0;
        for(i=n-k;i<n;i++)  y[p++]=i;
        for(i=0;i<n;i++)    if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0;i<m;i++)   cnt[i]=0;
        for(i=0;i<n;i++)   cnt[x[y[i]]]++;
        for(i=1;i<m;i++)   cnt[i]+=cnt[i-1];
        for(i=n-1;i>=0;i--)  sa[--cnt[x[y[i]]]]=y[i];
        swap(x,y);
        p=1; x[sa[0]]=0;
        for(i=1;i<n;i++)            
             x[sa[i]] = y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
void getheight(ll n)
{
	ll j,k=0;
	for(ll i=0;i<=n-1;i++) rk[sa[i]]=i;
	for(ll i=0;i<=n-1;i++)
	{
		if(k) k--;
		j=sa[rk[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rk[i]]=k;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n=strlen(s);
	calc_sa();
	for(ll i=0;i<=n-1;i++) cout<<sa[i]<<" ";
	cout<<"\n";
	getheight(n);
	for(ll i=0;i<=n-1;i++) cout<<height[i]<<" ";
	return 0;
}
