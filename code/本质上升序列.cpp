#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[220],f[220];
string s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=s.size();i++) a[i]=s[i-1]-'a';
	for(ll i=1;i<=s.size();i++)
	{
		f[i]=1;
		for(ll j=1;j<=i-1;j++)
		{
			if(a[i]==a[j]) f[i]=f[i]-f[j];
			else if(a[i]>a[j]) f[i]=f[i]+f[j];
		}
	}
	ll ans=0;
	for(ll i=1;i<=s.size();i++) ans=ans+f[i];
	cout<<ans; 
	return 0;
}
