#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct date{
	double x1,x2,x3;
	string ss;
};
date a[220];
ll sum,num,sum2;
double ave2;
string s;
int main()
{
	freopen("data_HW5.txt","r",stdin);
	for(ll i=1;i<=200;i++)
	{
		cin>>a[i].x1>>s>>a[i].x2>>s>>a[i].x3>>s>>a[i].ss;
		//cout<<a[i].x1<<"  "<<a[i].x2<<"  "<<a[i].x3<<"   "<<a[i].ss<<"\n";
		
		if(a[i].ss=="sig")
		{
			if(a[i].x3>0.25) sum++;
			num++;
		}
	}
	for(ll i=1;i<=200;i++) cout<<a[i].x1<<"  "<<a[i].x2<<"  "<<a[i].x3<<"   "<<a[i].ss<<"\n"; 
	cout<<(double)sum*1.0/num<<"  "<<sum<<"  "<<num<<"\n";
	cout<<sum2<<"   "<<ave2*1.0/sum2;
 } 
