#include<bits/stdc++.h>
using namespace std;
bool isprime(long long);
int main()
{
    long long n,i,a,s=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
	cin>>a;
	if(isprime(a)) s=s+a;
    }
    cout<<s<<endl;
}
bool isprime(long long x)
{
    long long q;
    if(x==1||x==0) return 0;
    if(x==2) return 1;
    q=2;
    while(q<=sqrt(x))
    {
	if(x%q==0) return 0;
	q++;
    }
    return 1;
}
