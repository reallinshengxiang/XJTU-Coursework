#include<bits/stdc++.h>
using namespace std;
#define ll long long
class largeint
{
	public:
		largeint();
		largeint(const string &s);
		friend ostream & operator <<(ostream &os,const largeint &aa);
		friend istream & operator >>(istream &is,largeint &aa);
		friend largeint operator +(largeint &a,largeint &b);
		void display() const;
	private:
		ll a[200];
		ll lenth;
};
largeint operator +(largeint &aa,largeint &bb)
{
	largeint cc;
	if(aa.lenth<=bb.lenth) swap(aa,bb);
	ll t=0;
	ll i;
        for(i=0;i<=aa.lenth-1;i++)
	{
		t=t+aa.a[i];
		if(i<=bb.lenth-1) t=t+bb.a[i];
		cc.a[i]=t%10;
		t=t/10;
	}
	if(t!=0) 
	{
		cc.a[i]=t;
		i++;
	}
	cc.lenth=i;
	return cc;
}
void largeint::display() const
{
	cout<<lenth<<"\n";
}
largeint::largeint()
{
	a[0]=0;
	lenth=1;
}
largeint::largeint(const string &s)
{
	ll len=s.size();
	for(ll i=len-1;i>=0;i--) a[len-i-1]=s[i]-'0';
	lenth=len;
}
ostream & operator <<(ostream &os,const largeint &aa)
{
	for(ll i=aa.lenth-1;i>=0;i--) os<<aa.a[i];
	os<<"\n";
	return os;
}
istream & operator >>(istream &is,largeint &aa)
{
	string ss;
	is>>ss;
	ll len=ss.size();
	for(ll i=len-1;i>=0;i--) aa.a[len-i-1]=ss[i]-'0';
	aa.lenth=len;
	return is;
}
int main()
{
	largeint a,b,c;
	cin>>a>>b;
	c=a+b;
	cout<<c;
}
