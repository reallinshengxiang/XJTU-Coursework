#include<bits/stdc++.h>
using namespace std;
struct student
{
	long long xuehao;
	long long banji;
	string xingming;
	double chengji1;
	double chengji2;
	double chengji3;
	double zongfen;
};
student a[10];
void paixu(long long x,long long y)
{
	long long i,j;
	for(i=x; i<=y-x; i++)
	{
		for(j=x; j<=y-i; j++)
		{
			if(a[j].banji>a[j+1].banji||(a[j].banji==a[j+1].banji&&a[j].zongfen<a[j+1].zongfen)) swap(a[j],a[j+1]);
		}
	}
}
void shuchu(long long x)
{
	cout<<fixed<<setprecision(1)<<a[x].xuehao<<" "<<a[x].banji<<" "<<a[x].xingming<<" "<<a[x].chengji1<<" "<<a[x].chengji2<<" "<<a[x].chengji3<<endl;
}
int main()
{
	long long c,d,f,i,k,n,l;
	double e;
	a[1]= {10001,11,"Zhang",99.5,88.5,89.5};
	a[2]= {10002,12,"Yang",77.9,56.5,87.5};
	a[3]= {10003,11,"Liang",92.5,99.0,60.5};
	a[4]= {10004,11,"Cai",89.6,56.9,90.5};
	a[5]= {10005,14,"Fu",55.6,67.9,98.9};
	a[6]= {10006,12,"Mao",22.1,45.9,99.2};
	a[7]= {10007,13,"Zhan",35.6,67.9,88.0};
	for(i=1; i<=7; i++) a[i].zongfen=a[i].chengji1+a[i].chengji2+a[i].chengji3;
	paixu(1,7);
	cin>>n;
	if(n==1)
	{
		cin>>c;
		cin.get();
		cin>>d;
		for(i=1; i<=7; i++)
		{
			if(a[i].banji>=c&&a[i].banji<=d) shuchu(i);
		}
	}
	else if(n==2)
	{
		cin>>c;
		cin.get();
		cin>>d;
		for(i=1; i<=7; i++)
		{
			if(a[i].xuehao>=c&&a[i].xuehao<=d) shuchu(i);
		}
	}
	else if(n==4)
	{
		cin>>e;
		for(i=1; i<=7; i++)
		{
			if(a[i].zongfen>=e) shuchu(i);
		}
	}
	else if(n==5)
	{
		cin>>f;
		cin.get();
		cin>>c;
		cin.get();
		cin>>d;
		for(i=1; i<=7; i++)
		{
			if(a[i].xuehao>=c&&a[i].xuehao<=d&&a[i].banji==f) shuchu(i);
		}
	}
	else if(n==3)
	{
		string ss;
		cin.get();
		getline(cin,ss,'*');
		l=ss.size();
		for(i=1; i<=7; i++)
		{
			for(k=0; k<=l-1; k++)
			{
				if(ss[k]!=a[i].xingming[k]) break;
			}
			if(k==l) shuchu(i);
		}

	}
}
