#include<bits/stdc++.h>
using namespace std;
int main() 
{
	map<string,long long> a;
	map<long long,string> b;
	long long n,i,k=0,maxx;
	string ss,ans;
	while(cin>>ss) 
        {
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
	for(i=1; i<=k; i++) 
        {
		if(a[b[i]]>maxx) 
                 {
			maxx=a[b[i]];
			ans=b[i];
		}
	}
	for(i=1; i<=k; i++) 
        {
		if(b[i]<ans&&a[b[i]]==maxx) 	ans=b[i];
	}
	cout<<ans<<" "<<maxx<<endl;
}
