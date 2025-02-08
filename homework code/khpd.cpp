#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    string ss;
    long long l,i,top;
    char a[10000];
    cin>>ss;
    l=ss.size();
    top=0;
    while(i<=l-1&&top>=0)
    {
	if(ss[i]=='[')
	{
          top++;
	  a[top]='[';
	}
	else if(ss[i]=='(')
	{
           top++;
	   a[top]='(';
	}
	else if(ss[i]==']')
	{
	   if(a[top]=='[') top--;
	   else break;
	}
	else if(ss[i]==')')
        {
	     if(a[top]=='(') top--;
	     else break;
        }
	i++;
    }
    if(i==l&&top==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
