nclude <iostream>
#include <cstring>
using namespace std;
 
class largeInt
{
	private:
		    char * longint;
		    int len;
		    char * opplus(char *p,char *q);
		    void revStr(char *p);
	public:
		    largeInt();
		    largeInt(const char *pch);
		    largeInt(const largeInt &);
		    largeInt operator+(const largeInt &);
		    friend ostream & operator<<(ostream &os,const largeInt &lI);
		    const char *getStr() const { return longint;}
		    ~largeInt();
};
 
char * largeInt::opplus(char *p,char *q){
	    long int len1=std::strlen(p),len2=std::strlen(q);
	    long int tmplen =len1>len2?len1:len2;
	    char * tmp = new char [tmplen+2];
	    int carry = 0,tmpsum=0,m;
	    revStr(p);
	    revStr(q);
	     
		    for(int i =0;i < len1;i++) p[i]-=0x30;
	    for (int j =0; j < len2; j++) q[j]-=0x30;
	     
		    for (int k=0;k < tmplen; k++){
			        tmpsum = (k<len1? p[k]:0) + (k<len2? q[k]:0) + carry;
			        if (tmpsum >9){
				            tmp[k] = tmpsum - 10;
				            carry = 1;
				        }
			        else  {
				            tmp[k] = tmpsum;
				            carry = 0;
				        }
			    }
	     
		    for(m=0;m<tmplen;m++)
		        tmp[m]+=0x30;
	    tmp[m]='\0';
	    revStr(tmp);
	    return tmp;
}
void largeInt::revStr(char *p){
	    long int len = std::strlen(p);
	    char * tmp = new char [len+1];
	    std::strcpy(tmp,p);
	    for (int i =0,j = len-1;i<len,j>=0;i++,j--)
		        p[i] = tmp[j];
	    delete [] tmp;
};
 
largeInt::largeInt() {
	    len = 1;
	    longint = new char [1];
	    *longint ='\0';
};
 
largeInt::largeInt(const char *pch)
{
	    //unsigned long lentmp;
	    len = (int)std::strlen(pch);
	    longint = new char [len+1];
	    std::strcpy(longint,pch);
	     
};
largeInt::largeInt(const largeInt &lI)
{
	    len =lI.len;
	    longint = new char[len+1];
	    std::strcpy(longint,lI.longint);
};
largeInt largeInt::operator+(const largeInt &lI)
{
	    largeInt tmp;
	    delete tmp.longint;
	    tmp.longint = opplus(this->longint,lI.longint);
	    return tmp;
};
 
largeInt::~largeInt()
{
	    delete longint;
};
 
std::ostream & operator<<(std::ostream &os,const largeInt &lI)
{
	    os << lI.getStr()<< std::endl;
	    return os;
}
 
 
int main(int argc, const char * argv[]) {
	    // insert code here...
		    char tmp1[200],tmp2[200];
	    std::cin  >> tmp1;
	    std::cin  >> tmp2;
	    largeInt lI1(tmp1),lI2(tmp2);
	    std::cout << lI1+lI2 <<std::endl;
	    return 0;
}
