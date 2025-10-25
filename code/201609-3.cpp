#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct man{
	ll attack,health,flag;
};
man a[3][10];
ll pos,sum,position,attack,health,n,x,y,num[3],ed;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	a[0][0].health=a[1][0].health=30;
	a[0][0].flag=a[1][0].flag=1;
	while(n--)
	{
		cin>>s;
		if(s[0]=='e')  pos=(pos+1)%2;
		else if(s[0]=='s')
		{
			cin>>position>>attack>>health;
			for(ll i=7;i>=position+1;i--) a[pos][i]=a[pos][i-1];
			a[pos][position].flag=1;
			a[pos][position].attack=attack;
			a[pos][position].health=health;
		}
		else
		{
			cin>>x>>y;
			a[(pos+1)%2][y].health=a[(pos+1)%2][y].health-a[pos][x].attack;
			a[pos][x].health=a[pos][x].health-a[(pos+1)%2][y].attack;
			if(a[(pos+1)%2][y].health<=0) 
			{
				if(y!=0)
				{
					for(ll i=y+1;i<=7;i++) a[(pos+1)%2][i-1]=a[(pos+1)%2][i];
				}
			}
			if(a[pos][x].health<=0)
			{
				if(x!=0)
				{
					for(ll i=x+1;i<=7;i++) a[pos][i-1]=a[pos][i];
				}
			}
			if(a[0][0].health<=0) a[0][0].flag=0;
			if(a[1][0].health<=0) a[1][0].flag=0;	
		}
	}
	if(a[0][0].flag==1&&a[1][0].flag==0) cout<<"1\n";
	else if(a[1][0].flag==1&&a[0][0].flag==0) cout<<"-1\n";
	else cout<<"0\n";
	for(ll pos=0;pos<=1;pos++)
	{
		cout<<a[pos][0].health<<"\n";
		sum=0;
		for(ll i=1;i<=7;i++) sum=sum+a[pos][i].flag;
		cout<<sum<<" ";
		for(ll i=1;i<=7;i++)
		{
			if(a[pos][i].flag) cout<<a[pos][i].health<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
