#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k=0,n;
void mov(ll nn,char aa,char cc,char bb)
{
	if(nn==0) return;
	mov(nn-1,aa,bb,cc);
	k++;
	cout<<k<<":from  "<<aa<<"--->"<<cc<<"\n";
	mov(nn-1,bb,cc,aa);
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cout<<"n= ";
	cin>>n;
	mov(n,'a','c','b');
	return 0;
}
