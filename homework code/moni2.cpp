#include<bits/stdc++.h>
using namespace std;
template<class T>
class compare{
	public:
	       compare(const T &a=0,const T &b=0):x(a),y(b){}
	       T maxx(){return max(x,y);}
	       T minn(){return min(x,y);}
	private:
	       T x,y;
};
int main()
{
	compare<int> a(4,7);
	cout<<"a：max="<<a.maxx()<<",min="<<a.minn()<<endl;
}
