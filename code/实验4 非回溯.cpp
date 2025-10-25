#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=1010;
ll a[N][22],b[22][22],he,cha=1e9,c[22],sum[22],ansa=-1,ansb=-1,anum,bnum;
void init()
{
	for(ll i=0;i<=19;i++)
	{
		for(ll j=i+1;j<=19;j++)
		{
			b[i][j]=b[j][i]=1;
			for(ll k=0;k<=999;k++)
			{
				if(a[k][i]&&a[k][j])
				{
					b[i][j]=b[j][i]=0;
					break;
				}
			}
		}
	}
}
void get_c()
{
	for(ll i=0;i<=19;i++)
	{
		for(ll j=0;j<=19;j++)
		{
			if(b[i][j]) c[i]=c[i]+(1<<j);
		} 
	}
}
void get_cc()
{
	for(ll i=0;i<=19;i++)
	{
		for(ll j=0;j<=999;j++) sum[i]=sum[i]+a[j][i];
	}
}
ll get_sum(ll x)
{
	ll cnt=0,ans=0;
	while(x)
	{
		if(x&1) ans=ans+sum[cnt];
		cnt++;
		x>>=1;
	}
	return ans;
}    
void get_answer(ll x)
{
	ll k=0,len=20;
	while(len--)
	{
		if(x&1)	cout<<k<<" ";
		k++;
		x>>=1;
	}
	cout<<"\n";
}
ll get_num(ll x)
{
	ll ans=0;
	while(x) x=x-lowbit(x),ans++;
	return ans;
}   
bool compare(ll x,ll y)
{
	while(x&&y)
	{
		if(lowbit(x)==lowbit(y))
		{
			x=x-lowbit(x);
			y=y-lowbit(y);
			continue;
		}
		else
		{
			if(lowbit(x)>lowbit(y))  return true;
			return false;
		}
	}
	return false;
}
void update(int i, int j)
{
	ansa=i,ansb=j;
	he=anum+bnum;
	cha=anum-bnum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("1.in","r",stdin);
	clock_t start_time, end_time;
    start_time = clock();
	for(ll i=0;i<=999;i++)
	{
		for(ll j=0;j<=19;j++) cin>>a[i][j];
	}
	init();
	get_c();
	get_cc();
    for(ll i=1;i<(1<<20);i++)
	{
		ll x=i,k=0,j=-1;
		while(x)
		{
			if(x&1)  j=(j&c[k]);
			x>>=1;
			k++;
		}
		anum=get_num(i);
		bnum=get_num(j);
		if(anum>=bnum&&bnum)
		{
			if(anum+bnum>he)  update(i,j);
			else if(anum+bnum==he)
			{
				if (anum-bnum<cha)	update(i,j);
				else if(anum-bnum==cha)
				{
					if(compare(ansa,i))  update(i,j);
					else if(get_sum(ansa)>=get_sum(ansb)&&get_sum(i)<get_sum(j)) update(i,j);
				}
			}
		}
	}
	if(~ansa)   get_answer(ansa),get_answer(ansb);
	else cout<<"\n\n";
	end_time = clock();
    cout<< "Total time: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	return 0;
}
