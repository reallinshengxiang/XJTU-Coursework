#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,y=0,i;
    cin>>n;
    a=n;
    i=5;
    while(a>=i)
    {
        y=y+a/i;
	i=i*5;
    }
    cout<<y<<endl;
}
