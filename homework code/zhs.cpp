#include<bits/stdc++.h>
using namespace std;
void search(long long k);
void print();
long long a[20],b[20],n,r;
int main()
{
    cin>>n>>r;
    search(1);
}
void search(long long k)
{
    long long i;
    for(i=n;i>=1;i--)
    {
	 if(!b[i]&&(k==1||(k>1&&i<a[k-1])))
	 {
            a[k]=i;
	    b[i]=1;
	    if(k==r) print();
	    else search(k+1);
	    b[i]=0;
	 }
    }
}
void print()
{
   long long i;
   for(i=1;i<=r;i++) cout<<a[i];
   cout<<endl;
}
