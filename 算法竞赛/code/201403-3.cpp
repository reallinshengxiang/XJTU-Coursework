#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
struct ANS{
	string s1,s2;
};
ANS a[N];
string s,ss[N],sss;
map<char,ll> mpa,mpb;
ll len,m,num,cnt,pos,ans[N],ii;
bool cmp(ANS x,ANS y)
{
	if(x.s1<y.s1) return 1;
	if(x.s1==y.s1&&x.s2<y.s2) return 1;
	return 0;
}
ll check(string s)
{
	ll flag=1;
	for(ll i=0;i<s.size();i++)
	{
		if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]=='-')) flag=1;
		else
		{
			return 0;
		}
	}
	return flag;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	len=s.size();
	for(ll i=0;i<=len-1;i++)
	{
		if(s[i]>='a'&&s[i]<='z'&&s[i+1]!=':')
		{
			if(!mpa[s[i]]) mpa[s[i]]=1;
		}
		else if(s[i]>='a'&&s[i]<='z'&&s[i+1]==':')
		{
			if(!mpb[s[i]]) mpb[s[i]]=1;
		}
	}
	cin>>m;
	m++;
	while(m--)
	{
		ii++;
		getline(cin,s);
		s=s+" "; 
		len=s.size();
		num=0;
		cnt=0;
		for(ll j=0;j<=len-1;j++)
		{
			if(s[j]==' ') 
			{
			    num++;
				if(num==1) pos=j+1;
				if(num>=2)
				{
					cnt++;
					ss[cnt]=s.substr(pos,j-pos);
		        //	cout<<cnt<<"   "<<pos<<"  "<<j-pos<<"     "<<ss[cnt]<<"\n";
					pos=j+1;
				}
			}
		}
		if(ii==1) continue;
		cout<<"Case "<<ii-1<<": ";
//		for(ll j=1;j<=cnt;j++) cout<<ss[j]<<"    ";		
		map<string,ll> flaga,flagb,num;
		ll tt=0;
		memset(ans,0,sizeof(ans));
		for(ll j=1;j<=cnt;j++)
		{
		//	cout<<j<<"  "<<tt<<"   "<<ss[j]<<"  "<<mpa[ss[j][1]]<<"    "<<mpb[ss[j][1]]<<"\n";
			if(mpa[ss[j][1]]) ans[++tt]=j;
			else if(mpb[ss[j][1]]&&check(ss[j+1]))
			{
				ans[++tt]=j;
				ans[++tt]=j+1;
				num[ss[j]]++;
				j++;				
			}
			else break;
		}
	//	for(ll j=1;j<=tt;j++) cout<<ans[j]<<" "; 
	    ll pp=0;
		for(ll j=1;j<=tt;j++)
		{
			pos=ans[j];
			if(mpa[ss[pos][1]]&&!flaga[ss[pos]])
			{
				pp++;
				a[pp].s1=ss[pos];
				a[pp].s2="";
				flaga[ss[pos]]=1;
			}
			else if(mpb[ss[pos][1]])
			{
			//	cout<<ss[pos]<<" "<<num[ss[pos]]<<"\n";
			    for(ll k=j;k<=cnt-1;k++)
				{
					if(ss[k]==ss[pos])
					{
						if(num[ss[pos]]==1) 
					    {
					    	pp++;
					    	a[pp].s1=ss[pos];
					    	a[pp].s2=ss[k+1];
						    num[ss[pos]]=0;
					    }
					    else num[ss[pos]]--;
					}				
				} 
			}
			
		}
		sort(a+1,a+pp+1,cmp);
		for(ll i=1;i<=pp;i++)
		{
			cout<<a[i].s1<<" ";
			if(a[i].s2!="") cout<<a[i].s2<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
