#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
ll a[N][22],b[22][22],he,cha=1e9,sum[22],anum,bnum,numa,numb,ansa[22],ansb[22],aa[22],bb[22];
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
void get_cc()
{
	for(ll i=0;i<=19;i++)
	{
		for(ll j=0;j<=999;j++) sum[i]=sum[i]+a[j][i];
	}
}
void update(ll i,ll j)
{
	numa=i,numb=j;
	he=anum+bnum;
	cha=abs(anum-bnum);
	for(ll i=1;i<=numa;i++) ansa[i]=aa[i];
	for(ll i=1;i<=numb;i++) ansb[i]=bb[i];
}
void check(ll anum,ll bnum)
{
	if(anum+bnum>he)  update(anum,bnum);
	else if(anum+bnum==he)
	{
		if(anum-bnum<cha)  update(anum,bnum);
		else if(anum-bnum==cha)
		{
			ll sum1=0,sum2=0,flag1=1,flag2=1;
			for(ll i=1;i<=anum;i++)
			{
				if(ansa[i]>aa[i])
				{
					flag1=0;
					break;
				}
				else if(ansa[i]<aa[i])
				{
					flag1=2;
					break;
				}
			}
			for(ll i=1;i<=bnum;i++)
			{
				if(ansb[i]>bb[i])
				{
					flag2=0;
					break;
				}
				else if(ansb[i]<bb[i])
				{
					flag2=2;
					break;
				}
			}
			if(flag1==0||(flag1==1&&flag2==0))
			{
				update(anum,bnum);
			    return;
			}
			for(ll i=1;i<=anum;i++) sum1=sum1+sum[aa[i]];
			for(ll i=1;i<=bnum;i++) sum2=sum2+sum[bb[i]];
			if(sum1<sum2) update(anum,bnum);
		}
	}
}
void dfs(ll step)
{
	ll flaga=1,flagb=1;
	if(anum+20-step<bnum) return;
	if(step>=20)
	{
		if(anum&&bnum&&anum>=bnum) check(anum,bnum);
		return;
	}
	for(ll i=1;i<=anum;i++)
	{
		if(!b[step][aa[i]])
		{
			flaga=0;
			break;
		} 
	}
	for(ll i=1;i<=bnum;i++)
	{
		if(!b[step][bb[i]])
		{
			flagb=0;
			break;
		} 
	}
	dfs(step+1);
	if(flaga)
	{
		bnum++;
		bb[bnum]=step;
		dfs(step+1);
		bnum--;
	}
	if(flagb)
	{
		anum++;
		aa[anum]=step;
		dfs(step+1);
		anum--;
	}
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("1.in","r",stdin);
	clock_t start_time, end_time;
    start_time = clock();
	for(ll i=0;i<=999;i++)
	{
		for(ll j=0;j<=19;j++) cin>>a[i][j];
	}
	init();
	get_cc();
    dfs(0);
	if(numa)
	{
		for(ll i=1;i<=numa;i++) cout<<ansa[i]<<" ";
		cout<<"\n";
		for(ll i=1;i<=numb;i++) cout<<ansb[i]<<" ";
	}
	else cout<<"\n\n";
	end_time=clock();
    cout<< "\nTotal time: "<<(double)(end_time-start_time)/CLOCKS_PER_SEC<<"s"<< std::endl;
	return 0;
}
