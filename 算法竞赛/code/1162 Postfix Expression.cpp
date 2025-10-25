#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=22;
struct node{
	ll left_child,right_child;
	string data;
}; 
node a[N];
ll indegree[N],root,n;
void print(ll id)
{
	
	if(a[id].left_child!=-1&&a[id].right_child!=-1) 
	{
		cout<<"(";
		print(a[id].left_child);
		print(a[id].right_child);
		cout<<a[id].data<<")";
	}
	else if(a[id].left_child==-1&&a[id].right_child!=-1) 
	{
		cout<<"(";
		cout<<a[id].data;
		print(a[id].right_child);
		cout<<")";
	}
	else
	{
		cout<<"(";
		cout<<a[id].data;
		cout<<")";
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].data>>a[i].left_child>>a[i].right_child,indegree[a[i].left_child]++,indegree[a[i].right_child]++;
	for(ll i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			root=i;
			break;
		}
	}
	print(root);
	return 0;
}

