#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y;
    cin>>x;
    if(x==0) y=0;
    else if(x>0) y=3*x+1;
    else y=x*x-1;
    cout<<y<<endl;
}
