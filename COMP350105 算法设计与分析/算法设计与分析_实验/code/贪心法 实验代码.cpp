#include<bits/stdc++.h>
using namespace std;
struct node
{
	int father,dis,degree,maxsonroad,flag;
};
class dTree
{
	private:
		node tree[10010];
		deque<int> que;
		int sum=0,nn,dd;
	public:
		dTree(int n, int d)
		{
			nn=n;
			dd=d;
			tree[0].father=-1;
			tree[0].dis=0;
			for(int i=0; i<=n-1; i++)
			{
				cin>>tree[i].degree;
				tree[i].maxsonroad=tree[i].flag=0;
				for(int j=1; j<=tree[i].degree; j++)
				{
					int x,y;
					cin>>x>>y;
					tree[x].father=i;
					tree[x].dis=y;
				}
			}
		}
		void solution()
		{
			for(int i=nn-1; i>=0; i--)
			{
				if(tree[i].degree==0) que.push_back(i);
			}
			while(!que.empty())
			{
				int p=que.front();
				que.pop_front();
				int dis=tree[p].dis;
				int fa=tree[p].father;
				if(tree[fa].flag==0&&tree[p].maxsonroad+dis>dd)
				{
					tree[fa].flag=1;
					fa=tree[fa].father;
					sum++;
				}
				else if(tree[fa].flag==0&&tree[fa].maxsonroad<tree[p].maxsonroad+dis) 
				{
					tree[fa].maxsonroad=tree[p].maxsonroad+dis;
				}
				tree[fa].degree--;
				if(tree[fa].degree==0) que.push_back(fa);
			}
			cout<<sum;
		}
};
int main()
{
	int n, d;
	cin >> n >> d;
	dTree dt(n, d);   
	dt.solution();    
	return 0;
}




