#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct student{
	ll id,poor;
};
student stu[10010];      
ll b[10010];            
ll cnt,x;
int main()
{
	 freopen("113.txt","r",stdin);
     freopen("118.out","w",stdout);
     cnt=0;
     while(cin>>x)
     {
     	if(x==0) break;
     	cnt++;
     	b[cnt]=x;
     	stu[x].id=x;
	 }
	 for(ll i=1;i<=cnt;i++)  
	 {
	 	x=b[i];
	 	cin>>stu[x].poor;
	 	if(stu[x].poor==2) cout<<x<<" ";
 	 }
	 ll  sum=0; 
	 while(cin>>x)
	 {
	    if(x==0) break;
	    cout<<stu[x].poor<<",";
	    sum++;
	 }
	 cout<<"\n";
	 cout<<sum; 
	 return 0;
}
