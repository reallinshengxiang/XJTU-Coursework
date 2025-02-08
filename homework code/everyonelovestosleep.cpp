#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[100],t,i,n,m,h,j,hh,mm,aa;
    cin>>t;
    for(i=1;i<=t;i++)
    {
      cin>>n>>h>>m;
      aa=h*60+m;
      memset(a,0,sizeof(a));
      for(j=1;j<=n;j++)
      {
         cin>>hh>>mm;
	 a[j]=hh*60+mm;
	 if(a[j]<aa) a[j]=a[j]+24*60;
      }
      sort(a,a+n);
      hh=(a[1]-aa)/60;
      mm=(a[1]-aa)%60;
      cout<<hh<<" "<<mm<<endl;
    }
}
