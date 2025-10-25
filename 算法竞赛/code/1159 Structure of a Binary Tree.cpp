#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1010;
struct node{
	ll val,left_id,right_id,step;
};
node t[N];
ll cnt=0,n,post[N],in[N],pos[N],m,fa[N];
string s;
map<ll,ll> mp;
ll build_tree(ll postst,ll posted,ll inst,ll ined,ll step)
{
	if(postst<1||postst>posted||posted>n||inst<1||inst>ined||ined>n) return -1;
	cnt++;
	//cout<<cnt<<"  "<<postst<<"   "<<posted<<"   "<<inst<<"   "<<ined<<"\n";
	t[cnt].val=post[posted];
	t[cnt].step=step;
	ll posin=pos[t[cnt].val];
	ll tmp=cnt;
	t[tmp].left_id=build_tree(postst,postst+(posin-inst)-1,inst,posin-1,step+1);
	t[tmp].right_id=build_tree(postst+(posin-inst),postst-inst+ined-1,posin+1,ined,step+1);
	return tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>post[i];
	for(ll i=1;i<=n;i++) cin>>in[i];
	for(ll i=1;i<=n;i++) pos[in[i]]=i;
	ll root=build_tree(1,n,1,n,0);
	for(ll i=1;i<=cnt;i++)
	{
		mp[t[i].val]=i;
		if(t[i].left_id!=-1) fa[t[t[i].left_id].val]=t[i].val;
		if(t[i].right_id!=-1) fa[t[t[i].right_id].val]=t[i].val;
	}
	cin>>m;
	cin.get();
	while(m--)
	{
		string s;
		getline(cin,s);
		if(s[0]=='I')
		{
			ll flag=1;
			for(ll i=1;i<=cnt;i++)
			{
				if(t[i].left_id==-1&&t[i].right_id==-1) continue;
				if((t[i].left_id!=-1&&t[i].right_id==-1)||(t[i].left_id==-1&&t[i].right_id!=-1))
				{
					flag=0;
					break;
				}
			}
			if(!flag) cout<<"No";
			else cout<<"Yes";
		} 
		else if(s[s.size()-1]=='t')
		{
			ll num=0;
			for(ll i=0;i<=s.size();i++)
			{
				if(s[i]==' ') break;
				num=num*10+(s[i]-'0');
			}
			if(num==t[root].val) cout<<"Yes";
			else cout<<"No";
		}
		else if(s[s.size()-1]=='l')
		{
			ll num1=0,num2=0,pos=0;
			for(ll i=0;i<=s.size();i++)
			{
				if(s[i]==' ') 
				{
					pos=i+5;
					break;
				}
				num1=num1*10+(s[i]-'0');
			}
			for(ll i=pos;i<=s.size();i++)
			{
				if(s[i]==' ') break;
				num2=num2*10+(s[i]-'0');
			}
			ll ceng1,ceng2;
			for(ll i=1;i<=cnt;i++)
			{
				if(t[i].val==num1) 
				{
					ceng1=t[i].step;
				}
				if(t[i].val==num2) 
				{
					ceng2=t[i].step;
				}
			}
			//cout<<ceng1<<"  "<<ceng2<<"  "<<num1<<"   "<<num2<<"\n";
			if(ceng1==ceng2) cout<<"Yes";
			else cout<<"No";
		}
		else if(s[s.size()-1]=='s')
		{
			ll num1=0,num2=0,pos=0;
			for(ll i=0;i<=s.size();i++)
			{
				if(s[i]==' ') 
				{
					pos=i+5;
					break;
				}
				num1=num1*10+(s[i]-'0');
			}
			for(ll i=pos;i<=s.size();i++)
			{
				if(s[i]==' ') break;
				num2=num2*10+(s[i]-'0');
			}
			if(fa[num1]==fa[num2]) cout<<"Yes";
			else cout<<"No";
		}
		else
		{
			ll flag=0;
			for(ll i=0;i<s.size()-7;i++)
			{
				string ss=s.substr(i,6);
				if(ss=="parent")
				{
					flag=1;
					break;
				}
				else if(ss=="left c")
				{
					flag=2;
					break;
				}
				else if(ss=="right ")
				{
					flag=3;
					break;
				}
			}
			ll num1=0,num2=0,pos=0;
			for(ll i=0;i<=s.size();i++)
			{
				if(s[i]==' ') 	break;
				num1=num1*10+(s[i]-'0');
			}
			for(ll i=s.size();i;i--)
			{
				if(s[i]==' ')
				{
					pos=i+1;
					break;
				}
			}
			for(ll i=pos;i<=s.size();i++)
			{
			//	cout<<i<<"  "<<s[i]<<" ";
				if(!(s[i]>='0'&&s[i]<='9')) break;
				num2=num2*10+(s[i]-'0');
			}
		//	cout<<num1<<"   "<<num2<<"\n";
			if(flag==1)
			{
				if(fa[num2]==num1) cout<<"Yes";
				else cout<<"No";
			}
			else if(flag==2)
			{
				if(t[mp[num2]].left_id==mp[num1]) cout<<"Yes";
				else cout<<"No";
			}
			else if(flag==3)
			{
				if(t[mp[num2]].right_id==mp[num1]) cout<<"Yes";
				else cout<<"No";
			}	
		}
		cout<<"\n";
	}
	return 0;
}
