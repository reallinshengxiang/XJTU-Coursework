#include<bits/stdc++.h>
using namespace std;
long long space,captical,lowercase,number;
int main()
{
   char a[110],*pa;
   cin.getline(a,100);
   pa=a;
   while(*pa)
   {
      if(*pa==' ') space++;
      if(*pa>='A'&&*pa<='Z') captical++;
      if(*pa>='a'&&*pa<='z') lowercase++;
      if(*pa>='0'&&*pa<='9') number++;
      pa++;
   }
   cout<<"space: "<<space<<endl<<"capital: "<<captical<<endl<<"lowercase: "<<lowercase<<endl<<"number: "<<number<<endl;
}
