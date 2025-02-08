#include<bits/stdc++.h>
using namespace std;
int main()
{ 
   long long a,b,c,i;
   cin>>a>>b>>c;
   for(i=10;i<=100;i++)
   {
	if(i%3==a&&i%5==b&&i%7==c) break;
   }
   if(i>100) cout<<"No answer"<<endl;
   else cout<<i<<endl;
}
