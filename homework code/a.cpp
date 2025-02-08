#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    long long a[10],i,j,m;
    for(i=1;i<=4;i++) cin>>a[i];
    for(i=1;i<=3;i++)
    {
       for(j=1;j<=4-i;j++)
        {
            if(a[j]>a[j+1])
            {
		 m=a[j];
		 a[j]=a[j+1];
		 a[j+1]=m;
	    }
	}
    }
    for(i=1;i<=4;i++) cout<<a[i]<<" ";
    cout<<endl;
}
