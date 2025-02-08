#include<bits/stdc++.h>
using namespace std;
class student 
{
	public:
		student();
		student(long long a,long long b,string c,double d1,double d2,double d3);
		void input();
		void caidan();
		void output();
		void shanchu();
		long long people();
		friend ostream &operator<<(ostream &os, const student &st);
        friend bool operator>(const student &s1,const student &s2);
        student &operator=(const student &s);
        friend bool compare(const student &s,string ss);
        friend bool compare(const student &s,long long ss);
	private:
		long long id;
		long long banji;
		string name;
		double chengji1;
		double chengji2;
		double chengji3;
		double zongfen;
		static long long renshu;
};
long long student::renshu=0;
student::student() 
{
	id=0;
	banji=0;
	name="";
	chengji1=chengji2=chengji3=zongfen=0;
}
student::student(long long a,long long b,string c,double d1,double d2,double d3) 
{
	id=a;
	banji=b;
	name=c;
	chengji1=d1;
	chengji2=d2;
	chengji3=d3;
	zongfen=d1+d2+d3;
}
student &student::operator=(const student &s)
{
     if(this==&s) return *this;
     id=s.id;
	 banji=s.banji;
	 name=s.name;
	 chengji1=s.chengji1;
	 chengji2=s.chengji2;
 	 chengji3=s.chengji3;
	 zongfen=s.zongfen;
     return *this;
}
void student::input() 
{
	cout<<"Id ";
	cin>>id;
	cout<<"class ";
	cin>>banji;
	cout<<"name ";
	cin>>name;
	cout<<"score1 ";
	cin>>chengji1;
	cout<<"score2 ";
	cin>>chengji2;
	cout<<"score3 ";
	cin>>chengji3;
	zongfen=chengji1+chengji2+chengji3;
	renshu++;
}
long long student::people() 
{
	return renshu;
}
void student::caidan() 
{
	cout<<"1.input"<<endl<<"2.delete"<<endl<<"3.select"<<endl<<"4.order"<<endl<<"5.output"<<endl<<"6.quit"<<endl<<"please input your option"<<endl;
}
void student::shanchu() 
{
	renshu--;
}
ostream &operator<<(ostream &os, const student &st) 
{
	os<<fixed<<setprecision(1)<<st.id<<","<<st.banji<<","<<st.name<<","<<st.chengji1<<","<<st.chengji2<<","<<st.chengji3<<","<<st.zongfen<<endl;
	return os;
}
bool operator>(const student &s1,const student &s2)
{
	if(s1.banji>s2.banji) return 1;
	if(s1.banji==s2.banji&&s1.zongfen<s2.zongfen) return 1;
	return 0;
}
bool compare(const student &s,string ss)
{
	long long f=0,k=0,l,num;
    l=ss.size();
    if(ss[0]>='0'&&ss[0]<='9') 
	{
		f=1;
		for(long long i=0;i<=l-1;i++)  num=num*10+ss[i]-'0';
	}
    if(f==1&&s.id==num)  return 1;
	else if(f==0&&s.name==ss) return 1;
	return 0; 
}
bool compare(const student &s,long long ss)
{
	if(s.id==ss||s.banji==ss) return 1;
	return 0;
}
int main() 
{
	long long x,n,i,j;
	student a[100],t;
	string s="";
	a[0].caidan();
	cin>>x;
	while(x!=6) 
	{
		n=a[0].people()+1;
		if(x==1) 
		{
			a[n].input();
			cout<<"continue?"<<endl;
			cin>>s;
			if(s=="yes") x=1;
			else 
			{
				a[0].caidan();
				cin>>x; 
			}
		}
		if(x==2)
		{ 
	       	  string ss;
	       	  long long k=0;
		      cin>>ss;
		      for(i=1;i<=a[0].people();i++) 
		      {
		      	if(compare(a[i],ss)) 
				  {
				  	k=i;
				  	break;
				  }
			  }
			  if(k) for(j=k;j<=a[0].people();j++) a[j]=a[j+1];
			  a[0].shanchu();
			  for(i=1;i<=a[0].people();i++) cout<<a[i];
			  cout<<"continue?"<<endl;
			  cin>>s;
			  if(s=="yes") x=2;
			  else 
			  {
				  a[0].caidan();
				  cin>>x; 
			  }			
		}
	    if(x==3)
	    {
	    	long long num;
	    	long long k=0;
	    	cin>>num;
		    for(i=1;i<=a[0].people();i++) 
		    {
		      	if(compare(a[i],num)) 
				{
				     k=i;
				  	 break;
				}
			}
		      for(i=1;i<=a[0].people();i++) 
		      {
		      	if(compare(a[i],num)) cout<<a[k];	
			  }
			  if(!k) cout<<" there is no eligible student"<<endl;
			  cout<<"continue?"<<endl;
			  cin>>s;
			  if(s=="yes") x=3;
			  else 
			  {
				  a[0].caidan();
				  cin>>x; 
			  }		
		}
		if(x==4) 
		{
			for(i=1;i<=a[0].people()-1;i++)
			{
				for(j=1;j<=a[0].people()-i;j++)
				{
					if(a[j]>a[j+1])
					{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
					}
				}
			}
			x=5;
		}
		if(x==5)
		{
			for(i=1;i<=a[0].people();i++) cout<<a[i];
			a[0].caidan();
			cin>>x;
		}
	}

}
