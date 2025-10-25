#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
struct st{
	ll left,right;
};
st a[110];
string s,maxs;
ll len,maxlen,l,r,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	l=0;
	r=0;
	cnt=1;
	s=s+" ";
	for(ll i=0;i<=s.size()-1;i++)
	{
		if(s[i]==' ')
		{
			r=i-1;
			len=r-l+1;
			if(len>maxlen)
			{
				cnt=1;
				a[cnt].left=l;
				a[cnt].right=r;
				maxlen=len;
			}
			else if(len==maxlen)
			{
				cnt++;
				a[cnt].left=l;
				a[cnt].right=r;
			}
			l=r+2;
		}
	}
	for(ll i=1;i<=cnt-1;i++)
	{
		for(ll j=a[i].left;j<=a[i].right;j++)
		{
			cout<<s[j];
		}
		cout<<"  ";
	}
	for(ll j=a[cnt].left;j<=a[cnt].right;j++)	cout<<s[j];
	return 0;
}
