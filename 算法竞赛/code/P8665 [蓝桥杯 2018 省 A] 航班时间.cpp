#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct tim{
	ll h,m,s,ss;
};
tim t[5],ans;
ll T,t1,t2,tt;
void print(tim tt)
{
	if(tt.h<=9) cout<<"0";
	cout<<tt.h<<":";
    if(tt.m<=9) cout<<"0";
    cout<<tt.m<<":";
    if(tt.s<=9) cout<<"0";
    cout<<tt.s;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>T;
	cin.get();
	while(T--)
	{		
		for(ll i=1;i<=2;i++)
		{
			scanf("%lld:%lld:%lld %lld:%lld:%lld",&t[i*2-1].h,&t[i*2-1].m,&t[i*2-1].s,&t[i*2].h,&t[i*2].m,&t[i*2].s);
			if(getchar()==' ') 
			{
				scanf("(+%lld)",&tt);
				t[i*2].h=t[i*2].h+tt*24;
			}
			t[2*i-1].ss=t[2*i-1].h*3600+t[2*i-1].m*60+t[2*i-1].s;
			t[2*i].ss=t[2*i].h*3600+t[2*i].m*60+t[2*i].s;
		}
		t1=t[2].ss-t[1].ss;
		t2=t[4].ss-t[3].ss;
		ans.ss=(t1+t2)/2;
		ans.h=ans.ss/3600;
		ans.m=(ans.ss%3600)/60;
		ans.s=ans.ss%60;
		print(ans);
		cout<<"\n";		
	}
	return 0;
}
