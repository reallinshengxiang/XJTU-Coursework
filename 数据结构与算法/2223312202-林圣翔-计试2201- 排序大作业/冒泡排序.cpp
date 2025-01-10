#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110],n,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin>>n>>x;
	for(ll i=1;i<=n;i++) a[i]=(rand()%(1000))+100;     //生成n个由100到1099的可能存在的随机整数
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //输出排序之前的序列 
	cout<<"\n"; 
	for(ll i=x+n-2;i>=x;i--)
	{
		for(ll j=n-1;j>=n-(i-x+2)-1;j--)                                                                               //从后往前冒泡 由小到大的排序         
		{
			if(a[j]>a[j+1])    swap(a[j],a[j+1]); 
		}                       
	}  
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //输出排序之后的序列 
	cout<<"\n"; 
	return 0;
}
