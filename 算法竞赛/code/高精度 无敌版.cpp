#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=10000;
struct hp
{
    int num[MAX];
    hp & operator=(const char*);
    hp & operator=(int);
    hp();
    hp(int);
    bool operator > (const hp &) const; 
    bool operator < (const hp &) const; 
    bool operator <= (const hp &) const; 
    bool operator >= (const hp &) const; 
    bool operator != (const hp &) const; 
    bool operator == (const hp &) const;
    hp operator + (const hp &) const;
    hp operator - (const hp &) const;
    hp operator * (const hp &) const;
    hp operator / (const hp &) const;
    hp operator / (const int &) const;
    hp operator % (const hp &) const;
    hp & operator += (const hp &);
    hp & operator -= (const hp &);
    hp & operator *= (const hp &);
    hp & operator /= (const hp &);
    hp & operator %= (const hp &);
};
hp & hp::operator = (const char* c)
{
	memset(num,0,sizeof(num));
	int n=strlen(c),j=1,k=1;
	for (int i=1;i<=n;i++)
	{
		if (k==10000) j++,k=1;			
		num[j]+=k*(c[n-i]-'0');
		k*=10;
	}
	num[0]=j;
	return *this;
}
hp & hp::operator = (int a)
{
	char s[MAX];
	sprintf(s,"%d",a);
	return *this=s;
}
hp::hp() {memset(num,0,sizeof(num)); num[0]=1;}	
hp::hp (int n) {*this = n;}	 		
bool hp::operator > (const hp &b) const
{
	if (num[0]!=b.num[0]) return num[0]>b.num[0];
	for (int i=num[0];i>=1;i--)
		if (num[i]!=b.num[i])
			return (num[i]>b.num[i]);
	return false;
}
bool hp::operator < (const hp &b) const {return b>*this;}
bool hp::operator <= (const hp &b) const {return !(*this>b);}
bool hp::operator >= (const hp &b) const {return !(b>*this);}
bool hp::operator != (const hp &b) const {return (b>*this)||(*this>b);}
bool hp::operator == (const hp &b) const {return !(b>*this)&&!(*this>b);}
hp hp::operator + (const hp &b) const
{
	hp c;
	c.num[0] = max(num[0], b.num[0]);
	for (int i=1;i<=c.num[0];i++)
	{
		c.num[i]+=num[i]+b.num[i];
		if (c.num[i]>=10000)					
		{
			c.num[i]-=10000;
			c.num[i+1]++;
		}
	}
	if (c.num[c.num[0]+1]>0) c.num[0]++;				
	return c;
}
hp hp::operator - (const hp &b) const
{
	hp c;
	c.num[0] = num[0];
	for (int i=1;i<=c.num[0];i++)
	{
		c.num[i]+=num[i]-b.num[i];
		if (c.num[i]<0)								
		{
			c.num[i]+=10000;
			c.num[i+1]--;
		}
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;	
	return c;
}
hp & hp::operator += (const hp &b) {return *this=*this+b;}
hp & hp::operator -= (const hp &b) {return *this=*this-b;}
hp hp::operator * (const hp &b) const
{
	hp c;
	c.num[0] = num[0]+b.num[0]+1;
	for (int i=1;i<=num[0];i++)
	{
		for (int j=1;j<=b.num[0];j++)
		{
			c.num[i+j-1]+=num[i]*b.num[j];		
			c.num[i+j]+=c.num[i+j-1]/10000;		
			c.num[i+j-1]%=10000;
		}
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;
	
	return c;
}
hp & hp::operator *= (const hp &b) {return *this=*this*b;}
hp hp::operator / (const hp& b) const
{
	hp c, d;
	c.num[0] = num[0]+b.num[0]+1;
	d.num[0] = 0;
	for (int i=num[0];i>=1;i--)
	{
		memmove(d.num+2, d.num+1, sizeof(d.num)-sizeof(int)*2);
		d.num[0]++;
		d.num[1]=num[i];
		int left=0, right=9999, mid;
		while (left < right)
		{
			mid = (left+right)/2;
			if (b*hp(mid) <= d) left=mid+1;
			else right=mid;
		}
		c.num[i]=right-1;
		d=d-b*hp(right-1);
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;
	return c;	
}
hp hp::operator % (const hp& b) const
{
	hp c, d;
	c.num[0] = num[0]+b.num[0]+1;
	d.num[0] = 0;
	for (int i=num[0];i>=1;i--)
	{
		memmove(d.num+2, d.num+1, sizeof(d.num)-sizeof(int)*2);
		d.num[0]++;
		d.num[1]=num[i];
		int left=0, right=9999, mid;
		while (left < right)
		{
			mid = (left+right)/2;
			if (b*hp(mid) <= d) left=mid+1;
			else right=mid;
		}
		c.num[i]=right-1;
		d=d-b*hp(right-1);
	}
	while (c.num[c.num[0]]==0&&c.num[0]>1) c.num[0]--;
	return d;	
}
hp hp::operator /(const int &x) const
{ 
        hp a;
        a.num[0]=num[0];
        int rest = 0;
        for (int i = num[0]; i >= 1; i--) { //注意要从最高位开始模拟 
            rest = rest * 10 + num[i];
            a.num[i] = rest / x;
            rest %= x;
        }
        while (!a.num[a.num[0]] && a.num[0]>1) a.num[0]--; //去掉多余的 0 
        return a;
    }
ostream & operator << (ostream & o, hp &n)
{
	o<<n.num[n.num[0]];
	for (int i=n.num[0]-1;i>=1;i--)
	{
		o.width(4);
		o.fill('0');
		o<<n.num[i];
	}
	return o;
}
 
istream & operator >> (istream & in, hp &n)
{
	char s[MAX];
	in>>s;
	n=s;
	return in;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hp a,b,x1,x2,x3,x4,x5;
	cin>>a>>b;
	x1=a+b;
	cout<<x1<<"\n";
	if(a<b)
	{
		x2=b-a;
		cout<<"-"<<x2<<"\n";
	}
	else 
	{
		x2=a-b;
		cout<<x2<<"\n";
	}	
	x3=a*b;
	x4=a/b;
	x5=a%b;
	cout<<x3<<"\n"<<x4<<"\n"<<x5<<"\n";
	return 0;
}
