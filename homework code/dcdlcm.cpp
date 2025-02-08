#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long a,b,m,n,r,rr;
     cin>>a>>b;
     m=max(a,b);
     n=min(a,b);
     r=m%n;
     while(r!=0)
     {
	 m=n;
	 n=r;
	 r=m%n;
     }
     rr=a*b/n;
     cout<<n<<" "<<rr<<endl;
}
