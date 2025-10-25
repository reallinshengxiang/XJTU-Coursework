#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=2e6+10;
ll root,cnt;
struct Node{
	ll ls,rs,pri,size,lazy;
	char val;
};
Node t[N];      
void update(ll u)
{
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
}
ll newnode(char x)
{
	cnt++;
	t[cnt].size=1;
	t[cnt].pri=rand();
	t[cnt].ls=t[cnt].rs=0;
	t[cnt].val=x;
	return cnt;
}
void pushdown(ll u)
{
    if(t[u].lazy)
    {
    	swap(t[u].ls,t[u].rs);
    	t[t[u].ls].lazy^=1;
    	t[t[u].rs].lazy^=1;
    	t[u].lazy=0;
	}
}
void split(ll u,ll x,ll &l,ll &r)
{
	if(u==0)
	{
		l=r=0;
		return;
	}
	pushdown(u);
	if(t[t[u].ls].size+1<=x)
	{
		l=u;
		split(t[u].rs,x-t[t[u].ls].size-1,t[u].rs,r);
	}
	else
	{
		r=u;
		split(t[u].ls,x,l,t[u].ls);
	}
	update(u);
}
ll merge(ll l,ll r)
{
	if(l==0||r==0) return l+r;
	if(t[l].pri>t[r].pri) 
	{
		pushdown(l);
		t[l].rs=merge(t[l].rs,r);
		update(l);
		return l;
	}
	else
	{
		pushdown(r);
		t[r].ls=merge(l,t[r].ls);
		update(r);
		return r;
	}
};
void inorder(ll u)
{
	if(u==0) return;
	inorder(t[u].ls);
	cout<<t[u].val;
	inorder(t[u].rs);
}
int main()
{
    srand(time(NULL));
    ll n,len,L,p,R,pos=0;     
    cin>>n;
    while(n--)
	{
        char opt[10];    
		cin>>opt;
        if(opt[0]=='M')  cin>>pos; 
        if(opt[0]=='I')
		{        
            cin>>len;
            split(root,pos,L,R);
            for(int i=1;i<=len;i++)  
			{    
                char ch=getchar();   while(ch<32||ch>126)  ch=getchar();
                L=merge(L,newnode(ch)); 
            }
            root=merge(L,R);
        }
        if(opt[0]=='D')
		{            
            cin>>len;     split(root,pos+len,L,R); split(L,pos,L,p);
            root=merge(L,R);
        }
        if(opt[0]=='G')
		{             
            len=1;     
			split(root,pos+len,L,R); 
			split(L,pos,L,p);
            inorder(p); 
			cout<<"\n";
            root=merge(merge(L,p),R);
        }
        if(opt[0]=='P') pos--;     
        if(opt[0]=='N') pos++;
        if(opt[0]=='R')
		{
			ll x,y,l,r,p,nn;
			cin>>nn;
			x=pos+1;
			y=x+nn;
			split(root,y,l,r);
			split(l,x-1,l,p);
			t[p].lazy^=1;
			root=merge(merge(l,p),r);
	    }
    }
    return 0;
}
