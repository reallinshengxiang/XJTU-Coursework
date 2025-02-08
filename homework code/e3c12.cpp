#include<bits/stdc++.h>
using namespace std;
class Stock{
	public:
		Stock();
		Stock(const char *na,const double &a=0,const double &b=0);
		void buy(long num, double price);
                void sell(long num, double price);
                void update(double price);
                friend ostream& operator<<(ostream& os, const Stock& st);
                const Stock& topval(const Stock& s) const;
		~Stock(){delete []company;}
	private:
		char* company;
		int shares;
		double share_val;
		double total_val;
                void set_tot() { total_val = shares * share_val; }
};
Stock::Stock()
{
	company=new char[strlen("noname!")+1];
	strcpy(company,"noname!");
	shares=share_val=0;
}
Stock::Stock(const char *na,const double &a,const double &b)
{
	company=new char[strlen(na)+1];
	strcpy(company,na);
	shares=a;
	share_val=b;
	set_tot();
}
void Stock::buy(long num, double price)
{
        shares=shares+num;
        share_val=price;
        set_tot();
}
void Stock::sell(long num, double price)
{
        shares=shares-num;
        share_val=price;
        set_tot();
}
void Stock::update(double price)
{
        share_val=price;
        set_tot();
}
ostream& operator<<(ostream& os, const Stock& st)
{
        os<<"Company: "<<st.company<<" Shares: "<<setprecision(3)<<fixed<<st.shares<<endl<<"Share Price: $"<< st.share_val<<" Total Worth: $"<<st.total_val<<endl;
        return os;
}
const Stock& Stock::topval(const Stock& s) const
{
	if(total_val>s.total_val) return *this;
	else return s;
}
const int STKS = 4;
int main()
{
// create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        cout<<stocks[st];
// set pointer to first element
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
// now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
     cout<<*top;
    // std::cin.get();
    return 0;
}
