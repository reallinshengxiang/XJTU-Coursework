#include<bits/stdc++.h>
using namespace std;
int main()
{
     string str;
     char ch;
     long long l,i,m=0;
     getline(cin,str);
     l=str.size();
     cin>>ch;
     for(i=0;i<=l-1;i++)
     {
	 if(str[i]==ch)
	 {
	    m=i+1;
	    break;
	 }
     }
     cout<<m<<endl;
}
