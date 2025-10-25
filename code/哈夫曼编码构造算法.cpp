#include<iostream>
using namespace std;
#define ll long long
ll n,x,ans,a,b;
string s;
struct Tree{
	ll data;
	Tree *lson,*rson;
}; 

Tree *build_tree(ll n)
{
	Tree* st[110]={NULL};
	Tree* tmp;
	for(ll i=1;i<=n;i++)
	{
		tmp=new Tree;
		cin>>tmp->data;
		tmp->lson=NULL;
		tmp->rson=NULL;
		st[i]=tmp;
	}
	ll flag=0;
	Tree* p=NULL;
	while(!flag)
	{
		ll min1=1,min2=1,c=0;
		for(ll i=1;i<=n;i++)
		{
			if(st[i]!=NULL)
			{
				if(st[min1]->data>st[i]->data) min1=i;
			}
		}
		if(min1==1) min2=2;
		for(ll i=1;i<=n;i++)
		{
			if(i!=min1)
			{
				if(st[min2]==NULL&&min2<=n) min2++;
				if(st[i]!=NULL&&st[min2]!=NULL)
				{
					if(st[i]->data<st[min2]->data) min2=i;
				}
			}
		}
		tmp=new Tree;
		tmp->data=st[min1]->data+st[min2]->data;
		tmp->lson=st[min1];
		tmp->rson=st[min2];
		st[min1]=tmp;
		st[min2]=NULL;
		for(ll i=1;i<=n;i++)
		{
			if(st[i]!=NULL)
			{
				p=st[i];
				c++;
			}
		} 
		if(c==1) return p;
	}
}
ll wpl(Tree *tree,ll len)
{
	Tree *p=tree;
	if(p==NULL) return 0;
	else 
	{
		if(!p->lson&&!p->rson) return p->data*len;
		else return wpl(p->lson,len+1)+wpl(p->rson,len+1);
	}
}

void preorder(Tree *tree)
{
	if(tree==NULL) return;
	cout<<tree->data;
	if(tree->lson)
	{
		cout<<"(";
		preorder(tree->lson);
		cout<<","; 
	}
	if(tree->rson)
	{
		preorder(tree->rson);
		cout<<")";
	}
}
void huffmancode(Tree* huff,ll len)
{
    Tree* p=huff;
    static ll code[30];
	ll i;
    if(p)
    {
        if (!p->lson&&!p->rson) 
        {
            for(i=0;i<len;i++)cout<<code[i];
            cout<<" ";
        }
        else
        {
            code[len] = 0;
            huffmancode(p->lson,len+1);
            code[len]=1;
            huffmancode(p->rson,len+1);
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	Tree* tree;
	tree=build_tree(n);
    cout<<wpl(tree,0)<<"\n";
	preorder(tree);
	cout<<"\n";
	huffmancode(tree,0);
	return 0;
}
