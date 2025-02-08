#include<bits/stdc++.h>
using namespace std;
class stock{
        public:
                stock();
                stock(char *p,long long x,double y);
                friend ostream &operator<<(ostream &os, const stock &st);
                friend bool operator<(const stock &s1, const stock &s2);
		        friend bool operator>(const stock &s1, const stock &s2);
		        friend bool operator==(const stock &s1, const stock &s2);
		        ~stock();
        private:
                char *str;
                double price,sum;
                long long num;
};
stock::stock()
{
        str=new char[1];
        num=0;
        price=0;
        sum=0;
}
stock::~stock()
{
	delete []str;
}
stock::stock(char *p,long long x,double y)
{
	    long long len;
        len=strlen(p);
        str=new char[len+1];
        strcpy(str,p);
        num=x;
        price=y;
        sum=x*y;
}
ostream &operator<<(ostream &os, const stock &st)
{
        os<<"Company: "<<st.str<<" Shares: "<<st.num<<endl<<setprecision(3)<<fixed<<"Share Price: $"<<st.price<<setprecision(2)<<fixed<<" Total Worth: $"<<st.sum<<" ";
        return os;
}
bool operator>(const stock &s1, const stock &s2) 
{
	return (s1.sum>s2.sum);
}
bool operator<(const stock &s1, const stock &s2)
{
	return (s1.sum<s2.sum);	
}
bool operator==(const stock &s1, const stock &s2)
{
	return (s1.sum==s2.sum);	
}
int main()
{
       stock tock[4] = {
        stock("NanoSmart", 12, 20.0),
        stock("Boffo Objects", 200, 2.0),
        stock("Monolithic Obelisks", 130, 3.25),
        stock("Fleep Enterprises", 60, 6.5)
        };
        long long i,t=0;
        cout<<"Stock holdings:"<<endl;
        for(i=0;i<=3;i++) cout<<tock[i];
        for(i=0;i<=3;i++)
        {
                if(tock[t]<tock[i]) t=i;
        }
        cout<<endl;
        cout<<endl<<"Most valuable holding:" <<endl;
        for(i=0;i<=3;i++)
		{
			if(tock[t]==tock[i])  cout<<tock[t]<<endl;
		}
}    
