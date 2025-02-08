#include<bits/stdc++.h>
using namespace std;
class Move{
	public:
		Move(const double &a=0,const double &b=0):x(a),y(b){};
		void showmove() const;
		Move add(Move &p) const;
	        void reset(const double &a=0,const double &b=0){x=a;y=b;}
	private:
		double x,y;
};
void Move::showmove() const
{
	cout<<"x:"<<x<<"\n"<<"y:"<<y<<"\n";
}
Move Move::add(Move &p) const
{
	return Move(x+p.x,y+p.y);
}
int main()
{
    Move m1(1, 2), m2(3, 4);
    m1.showmove();
    m2.showmove();
    m1.add(m2).showmove();
    m1.reset(5, 6);
    m1.showmove();
    return 0;
}
