#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	char ch;
	long long i,x;
	getline(cin,a);
	ch=a[0];
	x=1;
	for(i=1;i<=a.size()-1;i++)
	{
		if(a[i]==ch) x++;
                 else
		 {
			 if(x>=2) cout<<ch<<x;
			 else cout<<ch;
			 ch=a[i];
			 x=1;
		 }
	}
	if(x>=2) cout<<ch<<x;
	else cout<<ch;
	cout<<endl;
}
