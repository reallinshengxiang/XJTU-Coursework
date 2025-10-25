#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],x,n;
void search(ll x,ll &xl,ll &xr)                          //用引用xl和xr传递结果 
{
	ll l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(x>=a[mid]) l=mid+1;
		else r=mid-1;
	}
	if(x==a[r]) xl=xr=r;
	else xl=r,xr=l;
	return;
}
int main()
{
	srand(time(0));
	ll xl,xr;
	cin>>n;
	for(ll i=0;i<=n-1;i++) a[i]=(rand()%(1000))+100;    // 生成n个数据
	sort(a,a+n);                                        //将n个数从小到大排序
	for(ll i=0;i<=n-1;i++) cout<<a[i]<<" ";            
	cout<<"\n";                                         //从小到大输出n个数
	cin>>x;                                             //输入搜索元素x
	search(x,xl,xr);                                   
	if(xl==xr) cout<<xl;                                //xl==xr时，说明x在n个数据中，xl即为x的位置 
	else cout<<xl<<" "<<xr<<"\n";	                    //xl!=xr时，说明x不在n个数据中，
	return 0;                                           //xl即为小于x的元素最大位置，xr即为大于x的元素的最大位置 
}                                                       //xl==-1时，说明n个数据中不存在比x小的数 
                                                        //xr==n时，说明n个数据中不存在比x大的数 
                                                        
                                                        
                                                        
