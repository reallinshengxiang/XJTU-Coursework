#include<bits/stdc++.h>
using namespace std;
class largeInt{
        public:
               string aa;
               friend largeInt operator +(const largeInt &a1,const largeInt &a2);
               friend ostream& operator << (ostream &os,const largeInt &c);
               friend istream& operator >> (istream& in, largeInt& z);      	   
};
istream& operator >> (istream& in, largeInt& z) {
	in>>z.aa;
	return in;
}
ostream& operator << (ostream &os,const largeInt &c)
{
	return os<<c.aa;
}
largeInt operator +(const largeInt &a1,const largeInt &a2)
{
        long long i,a[202],b[202],c[202],t=0,m,p;
        largeInt a3;
        char ch;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        p=0;
        for(i=a1.aa.size()-1;i>=0;i--) 
		{
			a[p]=a1.aa[i]-'0';
			p++;
		}
		p=0;
        for(i=a2.aa.size()-1;i>=0;i--) 
		{
			b[p]=a2.aa[i]-'0';
			p++;
		}
        for(i=0;i<=max(a2.aa.size()-1,a1.aa.size()-1);i++)
        {
                c[i]=(t+a[i]+b[i])%10;
                t=(a[i]+b[i]+t)/10;
        }
        if(t)  c[i]=t;
        else i--;
        m=i;
        for(i=m;i>=0;i--)  
		{
			ch=c[i]+'0';
			a3.aa=a3.aa+ch;
		}
        return a3;
}
int main(int argc, const char * argv[]) 
{
     largeInt int1,int2;
     std::cin >> int1;
     std::cin >> int2;
     std::cout << int1+int2 <<std::endl;
     return 0;
}
