#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss;
    long long l,i;
    getline(cin,ss);
    l=ss.size();
    for(i=0;i<=l-1;i++) ss[i]=toupper(ss[i]);
    cout<<ss<<endl;
}
