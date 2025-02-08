#include<bits/stdc++.h>
using namespace std;
vector<int> add(vector<int>,vector<int>);
int main()
{
	string a1,b1;
	vector<int> a,b,c;
	long long i;
	cin>>a1>>b1;
	for(i=a1.size()-1;i>=0;i--) a.push_back(a1[i]-'0');
	for(i=b1.size()-1;i>=0;i--) b.push_back(b1[i]-'0');
	c=add(a,b);
	for(i=c.size()-1;i>=0;i--) cout<<c[i];
        cout<<endl; 
} 
vector<int> add(vector<int> a,vector<int> b)
{
	long long i,t=0;
	vector<int> c;
	if(a.size()<b.size()) return add(b,a);
	for(i=0;i<=a.size()-1;i++)
	{
		t=t+a[i];
		if(i<=b.size()-1) t=t+b[i];
		c.push_back(t%10);
		t=t/10;
	}
	return c;
}
