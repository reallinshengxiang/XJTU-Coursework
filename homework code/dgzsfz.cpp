#include<bits/stdc++.h>
using namespace std;
void fz(long long);
long long a;
int main()
{
    cin>>a;
    if(a==0) 
    {
	cout<<a<<endl;
	return 0;
    }
    while(a%10==0) a=a/10;
    fz(a);
    cout<<endl;
}
void fz(long long x)
{
    cout<<x%10;
    x=x/10;
    if(x>=10) fz(x);
    else if(x) cout<<x;
}
