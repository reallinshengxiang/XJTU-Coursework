#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110],n;
void quicksort(ll l,ll r)
{
	ll i,j,mid,p;
	i=l;
	j=r;
	mid=a[l];                                         //这里也可以是a[(l+r)/2],a[r]等，反正要确保[]中的数在l到r之间 
	do
	{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
        	swap(a[i],a[j]);
        	i++;
        	j--;
		}
	}while(i<=j);
	if(l<j) quicksort(l,j);
	if(i<r) quicksort(i,r);
 } 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) a[i]=(rand()%(1000))+100;     //生成n个由100到1099的可能存在的随机整数
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //输出排序之前的序列 
	cout<<"\n"; 
	quicksort(1,n);
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //输出排序之后的序列 
	cout<<"\n"; 
	return 0;
} 

