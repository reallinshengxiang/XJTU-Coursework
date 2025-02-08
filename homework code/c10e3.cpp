#include<bits/stdc++.h>
using namespace std;
class golf{
	public:
		golf();
		golf(const char *name,int hc);
		int setgolf();
                void sethandicap(int hc);
		void showgolf() const;
	private:
	        static const int Len = 40;
		char fullname[Len];
		int handicap;
};
golf::golf()
{
	strcpy(fullname,"no name!");
	handicap=0;
}
golf::golf(const char *name,int hc)
{
	strcpy(fullname,name);
	handicap=hc;
}
int golf::setgolf()
{
	cout<<"fullname:";
	cin.getline(fullname,Len);
	if(strlen(fullname)==0) return 0;
	cout<<"handicap:";
	cin>>handicap;
	cin.get();
	return 1;
}
void golf::sethandicap(int hc)
{
	handicap=hc;
}
void golf::showgolf() const
{
	cout<<"fullname:"<<fullname<<endl<<"handicap:"<<handicap<<endl;
}
int main()
{
    golf ann("Ann Birdfree", 24), andy, arrGolf[3];
    ann.showgolf();
    andy.showgolf();
    andy.setgolf();
    andy.showgolf();
    andy.sethandicap(20);
    andy.showgolf();
    int i=0;
    while(i<3&&arrGolf[i].setgolf())
    {
        arrGolf[i].showgolf();
        i++;
        if (i<3)
            cout << "next one" << endl;
    }
    return 0;
}
