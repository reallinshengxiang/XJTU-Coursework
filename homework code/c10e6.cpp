#include<bits/stdc++.h>
using namespace std;
class Move{
	public:
		Move(double a=0,double b=0):x(a),y(b){};
		void showmove() const;
                Move add(const Move & m) const;
		void reset(double a=0,double b=0){x=a,y=b;}
	private:
	        double x;
	        double y;	
};
void Move::showmove() const
{
	cout<<"x:"<<x<<endl<<"y:"<<y<<endl;
}
Move Move::add(const Move & m) const
{
	return Move(x+m.x,y+m.y);
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
