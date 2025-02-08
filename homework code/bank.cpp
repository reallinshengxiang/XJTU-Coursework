#include<bits/stdc++.h>
using namespace std;
class bank{
	public:
		long long balance;
		void cunqian(long long x);
		void quqian(long long x);		
};
void bank::cunqian(long long x)
{
	balance=balance+x;
	cout<<balance<<endl;
}
void bank::quqian(long long x)
{
	balance=balance-x;
	if(balance>=0) cout<<balance<<endl;
	else cout<<"no enough balance!"<<endl;
}
int main()
{
	bank a;
	long long b;
        cin>>a.balance;
	cout<<a.balance<<endl;
	cin>>b;
	a.cunqian(b);
	cin>>b;
	a.quqian(b);
}
