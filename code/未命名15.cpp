#include<iostream>
using namespace std;
#define ll long long
const int M = 22, N = 1010;
bool judge[M][M];					
int a[N][M], c[M];				
int sum[M];					
int ares = -1, bres = -1;			
int asum, bsum, eps = 100, tc;
void init1()
{
	for(ll i=0;i<=19;i++)
	{
		for(ll j=i+1;j<=19;j++)
		{
			judge[i][j]=judge[j][i]=1;
			for(ll k=0;k<=999;k++)
			{
				if(a[k][i]+a[k][j]==2)
				{
					judge[i][j]=judge[j][i]=0;
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
			if(judge[i][j]) c[i]=c[i]+(1<<j);
		} 
	}
}
int lowbit(int x)
{
	return x & (-x);
}   
ll get_onesum(ll x)
{
	ll ans=0;
	while(x) x=x-lowbit(x),ans++;
	return ans;
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
bool compare(int x, int y)
{
	while (x && y)
	{
		if (lowbit(x) == lowbit(y))
		{
			x -= lowbit(x), y -= lowbit(y);
			continue;
		}
		else
		{
			if (lowbit(x) > lowbit(y))return true;
			return false;
		}
	}
	return false;
}
void update(int i, int j)
{
	ares = i, bres = j;
	tc = asum + bsum;
	eps = asum - bsum;
}
int main()
{
	freopen("1.in","r",stdin);
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 20; j++)      cin >> a[i][j];
	}	
	init1(), get_c(), get_cc();
	for (int i = 1; i < 1 << 20; i++)
	{
		int temp = i, k = 0, j = -1;
		while (temp)
		{
			if (temp & 1)
				j = (j & c[k]);
			temp >>= 1;
			k++;
		}
		asum = get_onesum(i), bsum = get_onesum(j);
		if (asum >= bsum && bsum)
		{
			if (asum + bsum > tc)  update(i, j);
			else if (asum + bsum == tc)
			{
				if (asum - bsum < eps)
					update(i, j);
				else if (asum - bsum == eps)
				{
					if (compare(ares, i))
						update(i, j);
					else if(get_sum(ares) >= get_sum(bres) && get_sum(i) < get_sum(j))
						update(i, j);
				}
			}
		}
	}
	if (~ares)   get_answer(ares),get_answer(bres);
	else cout << endl << endl;
	return 0;
}
