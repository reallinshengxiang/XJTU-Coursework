#include<bits/stdc++.h>
using namespace std;
char shibie(string a,string b)
{
	long long c[100],i;
	memset(c,0,sizeof(c));
	for(i=0;i<=a.size()-1;i++) c[a[i]-' ']++;
	for(i=0;i<=b.size()-1;i++) c[b[i]-' ']--;
	for(i=0;i<=99;i++)
	{
		if(c[i]!=0) return i+' ';
	}
}
int main()
{
	string a,b;
	char ch;
	getline(cin,a);
	getline(cin,b);
        ch=shibie(a,b);
	cout<<ch<<endl;
}
