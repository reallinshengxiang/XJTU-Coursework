#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    long long a=0,b=0,cc=0;
    while(cin.get(c))
    {
       if(c>='0'&&c<='9') a++;
       else if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))  b++;
       else if(c==' ') cc++;
    }
    cout<<a<<" "<<b<<" "<<cc<<endl;
}
