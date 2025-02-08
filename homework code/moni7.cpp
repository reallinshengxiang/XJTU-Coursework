#include<bits/stdc++.h>
using namespace std;
class test
{
		string a;
	public:
		test(string aa="N"):a(aa) {}
		void show();
		friend ostream &operator<<(ostream& os,const test& m);
};

class test2:public test
{
		int b;
	public:
		test2(int bb=0,string aa="N"):test(aa),b(bb) {}
		void show();
		friend ostream &operator<<(ostream &os,const test2& m);
};
int main()
{
	int x;
	string y;
	cin>>y>>x;
	test2 an(x,y);
	cout<<an;
	return 0;
}
void test::show()
{
	cout<<a<<endl;
}
void test2::show()
{
	test::show();
	cout<<b<<endl;
}
ostream &operator<<(ostream &os, const test& m)
{
	os<<m.a;
	return os;
}
ostream &operator<<(ostream &os, const test2& m)
{
	const test *p;
	p=&m;
	os<<*p;
	os<<m.b<<endl;
	return os;
}
