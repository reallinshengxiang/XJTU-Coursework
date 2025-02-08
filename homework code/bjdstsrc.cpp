#include<bits/stdc++.h>
using namespace std;
int main()
{
    char dst[110],src[110];
    long long l,l1,l2,m,i;
    cin.getline(dst,100);
    cin.getline(src,100);
    l1=strlen(dst);
    l2=strlen(src);
    l=max(l1,l2);
    m=0;
    for(i=0;i<=l-1;i++)
    {
       if(dst[i]!=src[i])
       {
           m=i+1;
	   break;
       }
    }
    cout<<m<<endl;
}
