#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,flag;
string aa,bb,cc;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll a=1;a<=1999;a++)
	{
		for(ll b=a+1;b<=1999;b++)
		{
			for(ll c=b+1;c<=1999;c++)
			{
				if(a+b+c==2019)
				{
					aa=to_string(a);
					bb=to_string(b);
					cc=to_string(c);
					flag=1;
					for(ll i=0;i<aa.size();i++)
					{
						if(aa[i]=='2'||aa[i]=='4') flag=0;
					}
					for(ll i=0;i<bb.size();i++)
					{
						if(bb[i]=='2'||bb[i]=='4') flag=0;
					}
					for(ll i=0;i<cc.size();i++)
					{
						if(cc[i]=='2'||cc[i]=='4') flag=0;
					}
					if(flag) ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
