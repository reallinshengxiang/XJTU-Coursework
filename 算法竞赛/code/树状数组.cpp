#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
#define lowbit(x)  ((x) & - (x))
int tree[N]={0};
void update(int x, int d) 
{
     while(x <= N) {
        tree[x] += d;
        x += lowbit(x);
     }
}
int sum(int x) 
{             
    int ans = 0;
    while(x > 0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int a[11]={0,4,5,6,7,8,9,10,11,12,13};         
int main (){
    for(int i=1;i<=10;i++)  update(i,a[i]);     
    cout << "old: [5,8]="<<sum(8)-sum(4)<<endl; 
    update(5,100);                              
    cout << "new: [5,8]="<<sum(8)-sum(4);      
    return 0;
}
