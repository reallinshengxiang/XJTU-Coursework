#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define pr pair
#define mkp make_pair
#define fi first
#define se second
const int N=110;
int an[N],n,m,fa[N],deg[N],cnt[N];
pr<int,int>edge[N*N];
int fd(int x){
	if(fa[x]!=x)return x=fd(fa[x]);return x;
}
void merg(int x,int y){
	x=fd(x);y=fd(y);
	if(x!=y){
		fa[y]=x;//cnt[x]+=cnt[y];
	}
}
int main(int argc,char* argv[]){
	registerTestlibCmd(argc, argv);
	int i;
	n=inf.readInt(1,100);m=inf.readInt(0,10000);
	for(i=1;i<=m;++i){
		int x,y;
		x=inf.readInt(1,n);
		y=inf.readInt(1,n);
		edge[i]=mkp(x,y);
	}
	for(i=1;i<=n;++i){
		an[i]=ouf.readInt(0,1);
	}
	for(i=1;i<=n;++i)fa[i]=i;
	for(i=1;i<=m;++i)if(an[edge[i].fi]==an[edge[i].se]){
		int u=edge[i].fi,v=edge[i].se;
		++deg[u];++deg[v];
		merg(u,v);
	}
	for(i=1;i<=n;++i)if(deg[i]&1)cnt[fd(i)]++;
	for(i=1;i<=n;++i)if(i==fd(i) && (cnt[i]!=0 && cnt[i]!=2)){
		quitf(_wa,"wa");break;
	}
	if(i>n)quitf(_ok,"ac");
	while(!ouf.seekEof())ouf.readToken();
	while(!inf.seekEof())inf.readToken();
	while(!ans.seekEof())ans.readToken();return 0;
}
