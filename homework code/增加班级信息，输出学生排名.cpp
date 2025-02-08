#include<bits/stdc++.h>
using namespace std;
struct student{
      long long xuehao;
      long long banji;
      long long chengji1;
      long long chengji2;
      long long chengji3;
      long long zongfen;
};
bool dy(student xx,student yy)
{
     if(xx.banji>yy.banji) return 1;
     else if(xx.banji==yy.banji&&xx.zongfen<yy.zongfen) return 1;
     else return 0;
}
student a[5];
int main()
{
    long long i;
    for(i=1;i<=3;i++)
    {
	cin>>a[i].xuehao>>a[i].banji>>a[i].chengji1>>a[i].chengji2>>a[i].chengji3;
	a[i].zongfen=a[i].chengji1+a[i].chengji2+a[i].chengji3;
    }
    sort(a+1,a+4,dy);
    for(i=1;i<=3;i++)
    {    if(i>=2&&a[i].banji==a[i-1].banji) cout<<";";
	  else if(i>=2) cout<<endl;
	 cout<<a[i].banji<<","<<a[i].xuehao<<","<<a[i].zongfen;
    }
}
