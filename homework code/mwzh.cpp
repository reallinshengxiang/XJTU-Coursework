#include<bits/stdc++.h>
using namespace std;
struct zh{
     char mingwen;
     char miwen;
};
zh a[30]={{'a', 'd'}, {'b', 'w'}, {'c', 'k'},{'d', ';'}, {'e', 'i'}, {'f', 'h'},{'g', 'm'}, {'h', 'o'}, {'i', 'a'},{'j', 'z'}, {'k', 'b'}, {'l', 'n'},{'m', 'y'}, {';', 'c'}, {'w', 'e'},{'o', 'f'}, {'y', 'g'}, {'z', 'j'},{'n', 'l'}};
int main()
{
   char b[100];
   long long l,i,j,k;
   cin.getline(b,100);
   l=strlen(b);
   for(i=0;i<=l-1;i++)
   {
      k=19;
      for(j=0;j<=18;j++)
      {
	   if(a[j].miwen==b[i])
	   {
		k=j;
		break;
	   }
      }
      if(k==19) cout<<b[i];
      else cout<<a[k].mingwen;
   }
   cout<<endl;
}
