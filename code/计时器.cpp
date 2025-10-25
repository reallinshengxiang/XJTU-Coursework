#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
ll a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	clock_t startTime,endTime; 
    startTime=clock();//计时开始
    for(ll i=1;i<=1e10;i++) a=a+1;
	endTime=clock();
    cout << "Totle Time : " <<(double)(endTime - startTime)/1000 << "ms" << endl;	
	return 0;
} 
