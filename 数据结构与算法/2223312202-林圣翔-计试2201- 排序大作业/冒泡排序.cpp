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
	for(ll i=1;i<=n;i++) a[i]=(rand()%(1000))+100;     //����n����100��1099�Ŀ��ܴ��ڵ��������
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //�������֮ǰ������ 
	cout<<"\n"; 
	for(ll i=x+n-2;i>=x;i--)
	{
		for(ll j=n-1;j>=n-(i-x+2)-1;j--)                                                                               //�Ӻ���ǰð�� ��С���������         
		{
			if(a[j]>a[j+1])    swap(a[j],a[j+1]); 
		}                       
	}  
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";              //�������֮������� 
	cout<<"\n"; 
	return 0;
}
