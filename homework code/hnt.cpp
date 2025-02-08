#include<bits/stdc++.h>
using namespace std;
long long hnt(long long);
int main()
{
    long long m;
    cin>>m;
    m=hnt(m);
    cout<<m<<endl;
}
long long hnt(long long x)
{
    if(x==1) return 1;
    return (hnt(x-1)*2+1)%1000000;
}
