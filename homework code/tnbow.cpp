#include<bits/stdc++.h>
using namespace std;
int main()
{
   string words;
   long long n,l,i;
   getline(cin,words);
   l=words.size();
   n=0;
   for(i=0;i<=l-1;i++)
   {
      if(words[i]==' '&&((words[i+1]>='a'&&words[i+1]<='z')||(words[i+1]>='A'&&words[i+1]<='Z'))) n++;
      if(words[i]=='d'&&words[i+1]=='o'&&words[i+2]=='n'&&words[i+3]=='e') break;
   }
   cout<<"You entered a total of "<<n<<" words."<<endl;
}
