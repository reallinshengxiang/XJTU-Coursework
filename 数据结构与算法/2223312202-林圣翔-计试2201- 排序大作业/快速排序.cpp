#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110],n;
void quicksort(ll l,ll r)
{
	ll i,j,mid,p;
	i=l;
	j=r;
	mid=a[l];                                         //����Ҳ������a[(l+r)/2],a[r]�ȣ�����Ҫȷ��[]�е�����l��r֮�� 
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
	for(ll i=1;i<=n;i++) a[i]=(rand()%(1000))+100;     //����n����100��1099�Ŀ��ܴ��ڵ��������
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //�������֮ǰ������ 
	cout<<"\n"; 
	quicksort(1,n);
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //�������֮������� 
	cout<<"\n"; 
	return 0;
} 

