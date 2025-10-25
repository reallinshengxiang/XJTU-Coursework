#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<pair<double, double>> s;
double k,b;
ll ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll x1=0;x1<=19;x1++)
	{
		for(ll y1=0;y1<=20;y1++)
		{
			for(ll x2=0;x2<=19;x2++)
			{
				for(ll y2=0;y2<=20;y2++)
				{
					if(x1==x2||y1==y2) continue;
					k=(y1-y2)*1.0/(x1-x2);
					b=(y1*x2-y2*x1)*1.0/(x2-x1);
					s.insert({k,b});
				}
			}
		}
	}
	cout<<s.size()+41;
	return 0;
} 
