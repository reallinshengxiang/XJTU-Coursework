#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k=0,n;
void hnt(char aa,char bb,char cc,ll nn)
{
        if(nn==0) return ;
        hnt(aa,bb,cc,nn-1);
        k++;	
        cout<<k<<aa<<"---->"<<cc<<"\n";
	hnt(bb,cc,aa,nn-1);
}
int main()
{
	cin>>n;
	hnt('a','c','b',n);
	return 0;
}
