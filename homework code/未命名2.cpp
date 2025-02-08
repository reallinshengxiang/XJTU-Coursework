#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,q,t,n,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
	   scanf("%d",&n); 
	   map<string,int> a;
	   map<int,string> b;
	   string ss;
	   int x1=0,x2=0,x3=0;
	   q=0;
	   for(j=1;j<=3;j++)
	   {
	   	  for(k=1;k<=n;k++)
	   	  {
	   	  	 cin>>ss;
	   	  	 a[ss]=a[ss]+pow(2,j-1);
	   	  	 if(a[ss]==1||a[ss]==2||a[ss]==4)
			 {
			 	q++;
			 	b[q]=ss;
			 }
		  }
	   }
	   for(j=1;j<=q;j++)
	   {
	   	  if(a[b[j]]==1)  x1=x1+3;
	   	  else if(a[b[j]]==2)  x2=x2+3;
	   	  else if(a[b[j]]==4)  x3=x3+3;
	   	  else if(a[b[j]]==3)  
          {
			x2=x2+1;
			x1=x1+1;	
		  }
		  else if(a[b[j]]==5)  
          {
			x3=x3+1;
			x1=x1+1;	
		  }
		 else if(a[b[j]]==6)  
          {
			x2=x2+1;
			x3=x3+1;	
		  }
	   }
	   printf("%d %d %d\n",x1,x2,x3);
	}
}
