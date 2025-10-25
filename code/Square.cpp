#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,x,cnt,k,y1,y2,flag;
	cin>>T;
	while(T--)
	{
		cin>>x;
		cnt=1;
		k=0;
		flag=1;
		while(1)
		{
			y1=sqrt(x*cnt);
			y2=sqrt((x+1)*cnt);
			if(y1>1e9) break;
			if(y1*y1==x*cnt) 
			{
				if(y1>1e9) break;
				flag=0;
				cout<<y1<<"\n";
				break;
			}
			else if(y1+1<y2||(y2*y2<(x+1)*cnt&&y1+1==y2)) 
			{
				if(y1+1>1e9) break;
				flag=0;
				cout<<y1+1<<"\n";
				break;
			} 
			cnt=cnt*10;
			k++;
		}
		if(flag) cout<<"-1\n";
	}
	return 0; 
}
