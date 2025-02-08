#include<bits/stdc++.h>
using namespace std;
struct student{
	long long xuehao;
	long long banji;
	string name;
	double cj1;
	double cj2;
	double cj3;
	double zf;
};
student a[10];
int main()
{
	a[1]={10001,11,"Zhang",99.5,88.5,89.5};
	a[2]={10002,12,"Yang",77.9,56.5,87.5};
	a[3]={10003,11,"Liang",92.5,99.0,60.5};
	a[4]={10004,11,"Cai",93.6,67.9,90.5};
	a[5]={10005,14,"Fu",55.6,67.9,98.9};
	a[6]={10006,12,"Mao",22.1,45.9,99.2};
	a[7]={10007,13,"Zhan",35.6,67.9,88.0};
	long long i,j;
	for(i=1;i<=7;i++) a[i].zf=a[i].cj1+a[i].cj2+a[i].cj3;
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=7-i;j++)
		{
			if((a[j].banji>a[j+1].banji)||((a[j].banji==a[j+1].banji)&&(a[j].zf<a[j+1].zf))) swap(a[j],a[j+1]);
			else if(((a[j].banji==a[j+1].banji)&&(a[j].zf==a[j+1].zf))&&(a[j].cj1>a[j+1].cj2)) swap(a[j],a[j+1]);
		}
	}
	for(i=1;i<=7;i++)  cout<<a[i].xuehao<<" "<<a[i].banji<<" "<<a[i].name<<" "<<fixed<<setprecision(1)<<a[i].cj1<<" "<<a[i].cj2<<" "<<a[i].cj3<<" "<<a[i].zf<<endl;
}
