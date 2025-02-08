nclude <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
 
int trim(int* a,int n)
{
	    int tot=0;
	    int p[n+1];
	    memset(p,0,sizeof(p));
	    int i,j;
	    for(i=0;i<n;++i)
		    {
			        for(j=0;j<tot;++j)
				        {
					            if (p[j]==a[i]) break;
					        }
			        if (j>=tot)
				        {
					            p[tot]=a[i];
					            tot++;
					        }
			    }
	    for(i=0;i<n;++i) a[i]=p[i];
	    return tot;
}
 
class myset
{
	    private:
		        int* mset;
	        int len;
	    public:
		        myset()
		        {
			            mset=new int[1];
			            len=0;
			        }
	        myset(int* p,const int n)
		        {
			            mset=new int[n+1];
			            for(int i=0;i<n;++i) mset[i]=p[i];
			            len=n;
			        }
	        myset(const myset& ms)
		        {
			            len=ms.len;
			            mset=new int[len+1];
			            for(int i=0;i<len;++i) mset[i]=ms.mset[i];
			        }
	        ~myset()
		        {
			            delete [] mset;
			        }
	        myset operator+(const myset& ms) const
		        {
			            int totlen=len+ms.len;
			            int tmp[totlen+1];
			            for(int i=0;i<len;++i) tmp[i]=mset[i];
			            for(int i=len;i<totlen;++i) tmp[i]=ms.mset[i-len];
			            totlen=trim(tmp,totlen);
			            return myset(tmp,totlen);
			        }
	        myset operator-(const myset& ms) const
		        {
			            bool f=0;
			            int totlen=0,tmp[len+ms.len+1];
			            memset(tmp,0,sizeof(tmp));
			            for(int i=0;i<len;++i)
				            {
					                f=0;
					                for(int j=0;j<ms.len;++j)
						                {
							                    if (mset[i]==ms.mset[j])
								                    {
									                        f=1;
									                        break;
									                    }
							                }
					                if (!f)
						                {
							                    tmp[totlen]=mset[i];
							                    totlen++;
							                }
					            }
			            return myset(tmp,totlen);
			        }
	        myset operator*(const myset& ms) const
		        {
			            int totlen=0,tmp[len+ms.len];
			            memset(tmp,0,sizeof(tmp));
			            for(int i=0;i<len;++i)
				            {
					                for(int j=0;j<ms.len;++j)
						                {
							                    if (mset[i]==ms.mset[j])
								                    {
									                        tmp[totlen]=mset[i];
									                        totlen++;
									                        break;
									                    }
							                }
					            }
			            return myset(tmp,totlen);
			        }
	        void sort()
		        {
			            for(int i=0;i<len-1;++i)
				            {
					                for(int j=i+1;j<len;++j)
						                {
							                    if (mset[i]>mset[j]) swap(mset[i],mset[j]);
							                }
					            }
			        }
	        friend istream& operator>>(istream& is,myset& ms)
		        {
			            int tmp[1001],tot;
			            is >> tot;
			            for(int i=0;i<tot;++i) is >> tmp[i];
			            tot=trim(tmp,tot);
			            //cout << "tot=" << tot << endl;
			            delete [] ms.mset;
			            ms.mset=new int[tot+1];
			            for(int i=0;i<tot;++i) ms.mset[i]=tmp[i];
			            ms.len=tot;
			            return is;
			        }
	        friend ostream& operator<<(ostream& os,myset ms)
		        {
			            if (ms.len<1) cout << "empty\n";
			            else
				            {
					                ms.sort();
					                for(int i=0;i<ms.len-1;++i) os << ms.mset[i] << " ";
					                os << ms.mset[ms.len-1] << endl;
					            }
			            return os;
			        }
	        myset operator=(const myset& ms)
		        {
			            if (this==&ms) return *this;
			            delete [] mset;
			            len=ms.len;
			            mset=new int[len+1];
			            for(int i=0;i<len;++i) mset[i]=ms.mset[i];
			            return *this;
			        }
};
 
int main()
{
	    myset ms0,ms1;
	    cin >> ms0 >> ms1;
	    myset ms2(ms1);
	    myset ms3,ms4,ms5;
	    ms3=ms0+ms2;
	    ms4=ms0*ms2;
	    ms5=ms0-ms2;
	    cout << ms3;
	    cout << ms4;
	    cout << ms5;
	    return 0;
}
