#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s=0,n,p,i;
    cin>>n>>p;
    for(i=1;i<=n;i++) s=s+pow(i,p);
    cout<<s<<endl;
}
