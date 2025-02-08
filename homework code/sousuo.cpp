#include<bits/stdc++.h>
using namespace std;
long long efsort(long long,long long);
long long a[20],x;
int main()
{
	   long long i,m,ans;
	      for(i=1;i<=10;i++) cin>>a[i];
	         cin>>x;
		    sort(a+1,a+11);
		       ans=efsort(1,10);
		          cout<<ans-1<<endl;		
}
long long efsort(long long l,long long r)
{
	    long long mid;
	       while(l<=r)
		          {
				        mid=(l+r)/2;
					      if(a[mid]>=x) r=mid-1;
					            else l=mid+1;
						       }
	          if(a[l]==x) return l;
		     else return 0;
}
