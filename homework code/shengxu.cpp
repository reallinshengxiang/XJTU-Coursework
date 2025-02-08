#include<bits/stdc++.h>
using namespace std;
void qsort(long long,long long);
double a[20];
int main()
{
   long long i;
   for(i=1;i<=10;i++) cin>>a[i];
   qsort(1,10);
   for(i=1;i<=10;i++) cout<<a[i]<<" ";
   cout<<endl;
}
void qsort(long long l,long long r)
{
    long long i,j,mid,p;
    i=l;
    j=r;
    mid=a[(i+j)/2];
    do{
       while(a[i]<mid) i++;
       while(a[j]>mid) j--;
       if(i<=j)
       {
	   p=a[i];
	   a[i]=a[j];
	   a[j]=p;
	   i++;
	   j--;
       }
    }while(i<=j);
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}

