#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll x;
map<ll,ll> mp,vis;
vector<ll> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	cout<<"int[] arr = new int[]{";
	for(ll i=0;i<s.size();i++)	vis[s[i]-'0']=1;
	for(ll i=9;i>=0;i--)
	{
		if(vis[i]) arr.push_back(i);
	}
	for(ll i=0;i<arr.size();i++)
	{
		mp[arr[i]]=i;
		cout<<arr[i];
		if(i!=arr.size()-1) cout<<",";
	}
	cout<<"};\nint[] index = new int[]{";
	for(ll i=0;i<s.size();i++)
	{
		x=(ll)(s[i]-'0');
		cout<<mp[x];
		if(i!=s.size()-1) cout<<","; 
	}
	cout<<"};";
	return 0;
}
