#include<bits/stdc++.h> 
namespace SALES
{
    using namespace std;
    const int QUARTERS=4;
    class Sales
    {
    public:
        Sales();
        Sales(const double ar[], int n);
        void showSales();
    private:
        double sales[QUARTERS];
        double average;
        double maxx;
        double minn;
    };
    Sales::Sales(const double ar[], int n)
    {
        minn=maxx=average=sales[0]=ar[0];
	for(int i=1;i<=3;i++)
	{
	    sales[i]=ar[i];
	    maxx=max(maxx,sales[i]);
	    minn=min(minn,sales[i]);
	    average=average+sales[i];
	}
	average=average/n;
    }
    Sales::Sales()
    {
        cout<<"Please enter 4 quarters for sales:"<<endl;
        cout<< "the 1 quarter :";
        cin>>sales[0];
        minn=maxx=average=sales[0];
	for(int i=1;i<=3;i++)
	{
             cout<< "the "<<i+1<<" quarter :";
             cin>>sales[i];
	     maxx=max(maxx,sales[i]);
	     minn=min(minn,sales[i]);
             average=average+sales[i];
	}
	average=average/4;
    }

    void Sales::showSales()
    {
        cout<<"Display all information in sales : "<<endl;
        cout<<"The 4 quarters are $"<<sales[0]<< ", $"<<sales[1]<<", $"<<sales[2]<<", $"<<sales[3]<<endl;
        cout<<"The average income is $"<<average<<endl;
        cout<<"The maximum income is $"<<maxx<<endl;
        cout<<"The minimum income is $"<<minn<<endl;
    }
}
using namespace SALES;
int main()
{
    double arr[4]={3.4, 5.6, 2.5, 6.1};
    Sales s1(arr, 4);
    s1.showSales();
    Sales s2;
    s2.showSales();
    return 0;
}
