#include<bits/stdc++.h>
using namespace std;
void msort(long long,long long);
double a[20];
int main()
{
    long long i;
    for(i=1;i<=10;i++) cin>>a[i];
    msort(1,10);
    for(i=1;i<=10;i++) cout<<a[i]<<" ";
    cout<<endl;
}
void msort(long long s,long long t)
{
    if(s==t) return;
    double r[20];
    long long mid=(s+t)/2;
    msort(s,mid);
    msort(mid+1,t);
    long long i=s,j=mid+1,k=s;
    while(i<=mid&&j<=t)
    {
	if(a[i]>=a[j])
        {
	   r[k]=a[i];
	   k++;
	   i++;
	}
	else
	{
	   r[k]=a[j];
	   k++;
	   j++;
	}
    }
    while(i<=mid)
    {
	 r[k]=a[i];
	 k++;
	 i++;
    }
    while(j<=t)
    {
	 r[k]=a[j];
	 k++;
	 j++;
    }
    for(i=s;i<=t;i++) a[i]=r[i];
}
