#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,long long> a;
    map<long long,string> b;
    long long n,i,k,maxx;
    string ss,ans;
    cin>>n;
    k=0;
    for(i=1;i<=n;i++)
    {
       cin>>ss;
       cin.get();
       if(a[ss]==0)
       {
	   k++;
	   b[k]=ss;
	   a[ss]=1;
       }
       else a[ss]++;
    }
    maxx=0;
    for(i=1;i<=k;i++)
    {
	 if(a[b[i]]>maxx)
	 {
             maxx=a[b[i]];
	     ans=b[i];
	 }
    }
    cout<<ans<<" "<<maxx<<endl;
}
