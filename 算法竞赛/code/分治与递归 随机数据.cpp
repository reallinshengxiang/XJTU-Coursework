#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const ll N=1e6+10;
struct node{
	ll num;
	double weight;
};
node a[N];
ll n;
double sum; 
bool cmp(node x,node y)
{
	return x.num<y.num;
}
int main()
{
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 srand(time(0));
	 n=rand()%100; 
	 for(ll i=1;i<=n;i++) a[i].num=rand()%1000000;
	 while(1)
	 {	 	
	 	for(ll i=1;i<=n-1;i++) a[i].weight=(double)(rand()%100000)/100000,a[n].weight=1-a[i].weight;
	 	if(a[n].weight>0) break;
	 }
	 cout<<n<<"\n";
	 for(ll i=1;i<=n;i++) cout<<a[i].num<<"  ";
	 cout<<"\n";
	 for(ll i=1;i<=n;i++) cout<<a[i].weight<<"  ";
	 cout<<"\n";
     sort(a+1,a+n+1,cmp);
     for(ll i=1;i<=n;i++) 
	 {
	 	sum=sum+a[i].weight;
	 	if(sum>=0.5) 
		{
		 	cout<<a[i].num;
		 	break;
		}
	 }
     return 0;
}



