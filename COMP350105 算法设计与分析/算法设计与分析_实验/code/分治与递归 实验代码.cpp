#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void WeightMedian(int length,vector<int>num, vector<double>weight,int index)
{
	int st=index,ed=index+length-1,nn=num.size();
	if(length==nn) weight.push_back(0.5);
	if(length<5)
	{
		for(int i=1; i<=length-1; i++)
		{
			for(int j=st; j<=ed-i; j++)
			{
				if(num[j]>num[j+1])
				{
					swap(num[j],num[j+1]);
					swap(weight[j],weight[j+1]);
				}
			}
		}
		double sum=0;
		for(int i=st; i<=ed; i++)
		{
			sum=sum+weight[i];
			if(sum>weight[nn]) cout<<num[i],exit(0);
		}
	}
	for(int ii=0; ii<=(ed-st-4)/5; ii++)
	{
		int pl=st+5*ii;
		int pr=pl+4;
		for(int i=1; i<=4; i++)
		{
			for(int j=pl; j<=pr-1; j++)
			{
				if(num[j]>num[j+1])
				{
					swap(num[j],num[j+1]);
					swap(weight[j],weight[j+1]);
				}
			}
		}
		swap(num[st+ii],num[pl+2]);
		swap(weight[st+ii],weight[pl+2]);
	}
	for(int i=1; i<=(ed-st-4)/5; i++)
	{
		for(int j=st; j<=st+(ed-st-4)/5-i; j++)
		{
			if(num[j]>num[j+1])
			{
				swap(num[j],num[j+1]);
				swap(weight[j],weight[j+1]);
			}
		}
	}
	int xx=num[st+(ed-st+6)/10];
	int l=st,r=ed;
	while(l<r)
	{
		if(num[l]<xx) l++;
		if(num[r]>xx) r--;
		swap(num[l],num[r]);
		swap(weight[l],weight[r]);
	}
	int pos=l;
	double sum=0;
	for(int i=st; i<=pos; i++)	sum=sum+weight[i];
	if(sum>weight[nn]) WeightMedian(pos-st+1,num,weight,st);
	else weight[nn]=weight[nn]-sum,WeightMedian(ed-pos,num,weight,pos+1);
}
int main()
{
	int n,x;
	double y;
	vector<int> num;
	vector<double> weight;
	cin>>n;
	for(int i=0; i<=n-1; i++) cin>>x,num.push_back(x);
	for(int i=0; i<=n-1; i++) cin>>y,weight.push_back(y);
	WeightMedian(n,num,weight,0);
	return 0;
}
