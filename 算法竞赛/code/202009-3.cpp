#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2515;
struct point{
	ll num,inout;
};
struct qijian{
	string name;
	point p[6];
};
qijian q[N];
string s;
point pp[N];
ll Q,n,m,iin[10010][N],oou[10010][N],ss,cnt,mm,num[N],flag[N];
vector<ll> e[N];
map<ll,ll> mp1,mp2;
ll calc(ll ii)
{
	memset(flag,0,sizeof(flag));
	memset(num,0,sizeof(num));
	for(ll i=1;i<=m;i++) num[mp1[i]]=iin[ii][i],flag[mp1[i]]=1;
	//for(ll i=1;i<=cnt;i++) cout<<num[i]<<" ";
	//cout<<"\n";
	ll step=0;
	while(1)
	{
		step++;
		for(ll i=1;i<=n;i++)
		{
			string s1=q[i].name;
			ll pos=mp2[i];
			if(flag[pos]) continue;
			ll ff=1;
			for(ll j=0;j<e[pos].size();j++)
			{
				if(!flag[e[pos][j]])
				{
					ff=0;
					break;
				}
			}
			if(!ff) continue;
			flag[pos]=1;
			num[pos]=num[e[pos][0]];
			if(s1=="XOR")
			{
				for(ll j=1;j<e[pos].size();j++) num[pos]=(num[pos]^num[e[pos][j]]);
			}
			else if(s1=="AND")
			{
				for(ll j=1;j<e[pos].size();j++) num[pos]=(num[pos]&num[e[pos][j]]);
			}
			else if(s1=="OR")
			{
				for(ll j=1;j<e[pos].size();j++) num[pos]=(num[pos]|num[e[pos][j]]);
			}
			else if(s1=="NOT") num[pos]=(!num[pos]);
			else if(s1=="NAND")
			{
				for(ll j=1;j<e[pos].size();j++) num[pos]=(num[pos]&num[e[pos][j]]);
				num[pos]=(!num[pos]);
			}
			else if(s1=="NOR")
			{
				for(ll j=1;j<e[pos].size();j++) num[pos]=(num[pos]|num[e[pos][j]]);
				num[pos]=(!num[pos]);
			}
			//for(ll i=1;i<=cnt;i++) cout<<flag[i]<<" ";	cout<<"\n";
		}
		ll kk=1;
		for(ll i=1;i<=cnt;i++)
		{
			if(flag[i]==0) 
			{
				kk=0;
				break;
			}
		}
		if(kk) break;
		if(step>cnt) 
		{
			cout<<"LOOP\n";
			return 1;
		}
	}
	for(ll i=1;i<=oou[ii][0];i++)
	{
		ll pos=mp2[oou[ii][i]];
		cout<<num[pos]<<" ";
	}
	cout<<"\n";
	return 0;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>Q;
	while(Q--)
	{
	//	memset(q,0,sizeof(q));
		for(ll i=1;i<=N-1;i++) e[i].clear();
		cin>>m>>n;
		cnt=0;
		mp1.clear();
		mp2.clear();
		for(ll i=1;i<=n;i++)
		{
			cin>>q[i].name>>q[i].p[0].num;
			if(!mp2[i])
			{
				cnt++;
				pp[cnt].num=i;
				pp[cnt].inout=0;
				mp2[i]=cnt;
			}
			for(ll j=1;j<=q[i].p[0].num;j++)
			{
				cin>>s;
				if(s[0]=='I')
				{
					q[i].p[j].num=0;
					for(ll k=1;k<s.size();k++) q[i].p[j].num=q[i].p[j].num*10+(s[k]-'0');
					q[i].p[j].inout=1;		
					if(!mp1[q[i].p[j].num])
					{
						cnt++;
						pp[cnt].num=q[i].p[j].num;
						pp[cnt].inout=1;
						mp1[q[i].p[j].num]=cnt;
					}
					e[mp2[i]].push_back(mp1[q[i].p[j].num]);
				}
				else
				{
					q[i].p[j].num=0;
					for(ll k=1;k<s.size();k++) q[i].p[j].num=q[i].p[j].num*10+(s[k]-'0');
					q[i].p[j].inout=0;
					if(!mp2[q[i].p[j].num])
					{
						cnt++;
						pp[cnt].num=q[i].p[j].num;
						pp[cnt].inout=0;
						mp2[q[i].p[j].num]=cnt;
					}
					e[mp2[i]].push_back(mp2[q[i].p[j].num]);
				}				
			}						
		}
		/*for(ll i=1;i<=n;i++)
		{
			cout<<q[i].name<<"  "<<q[i].p[0].num<<"\n";
			for(ll j=1;j<=q[i].p[0].num;j++) 
			{
				cout<<q[i].p[j].num<<"  "<<q[i].p[j].inout<<"            ";
			}
			cout<<"\n";
		}
		for(ll i=1;i<=cnt;i++) cout<<i<<"   "<<pp[i].num<<" "<<pp[i].inout<<"\n";
		cout<<"\n";
		for(ll i=1;i<=cnt;i++)
		{
			cout<<i<<"  "<<pp[i].num<<"   "<<pp[i].inout<<":            ";
			for(ll j=0;j<e[i].size();j++) cout<<e[i][j]<<"  "<<pp[e[i][j]].num<<" "<<pp[e[i][j]].inout<<"             "; 
			cout<<"\n";
		}	*/	
		ll anss;
		cin>>ss;
		for(ll i=1;i<=ss;i++)
		{
			for(ll j=1;j<=m;j++) cin>>iin[i][j];
		}
		for(ll i=1;i<=ss;i++)
		{
			cin>>oou[i][0];
			for(ll j=1;j<=oou[i][0];j++) cin>>oou[i][j];
		}
		for(ll i=1;i<=ss;i++) 
		{
			anss=calc(i);
			if(anss==1) break;
		}
	}
	return 0;
}
/*
3
2 6
NOR 2 O4 I2
AND 2 O4 O6
XOR 2 O5 O1
NOT 1 O6
NAND 2 O2 O2
AND 2 I1 O3
2
0 0
1 0
3 2 3 4
6 1 2 3 4 5 6

3 9
AND 3 I1 I2 I3
OR 3 I1 I2 I3
AND 2 I1 I2
AND 2 I1 I3
AND 2 I2 I3
OR 2 O1 O7
AND 2 O2 O8
NOT 1 O9
OR 3 O3 O4 O5
8
0 0 0
0 0 1
0 1 0
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1
2 6 9
2 6 9
2 6 9
2 6 9
2 6 9
2 6 9
2 6 9
2 6 9


3 5
XOR 2 I1 I2
XOR 2 O1 I3
AND 2 O1 I3
AND 2 I1 I2
OR 2 O3 O4
4
0 1 1
1 0 1
1 1 1
0 0 0
2 5 2
2 5 2
2 5 2
2 5 2


*/
