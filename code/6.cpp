#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>w>>n;
    cout<<(w+n-1)%7+1;
	return 0;
}
