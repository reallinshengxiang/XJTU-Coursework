#include<getopt.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cachelab.h"
#define ll long long
typedef unsigned long long int mem_addr_t;
typedef struct{
	int valid_bit,tag_bit;
}*Cache;
Cache cache;
char fp[22]="/traces/yi.trace";
ll s,S,E,b,hit_count,miss_count,eviction_count,mod,*que,cnt;
ll wz(ll x,ll y)
{
	return x*mod+y;
}
void delete(ll x)
{
	ll pos=0;
	for(ll i=1;i<=cnt;i++) 
	{
        if(que[i]==x)
		{	
			pos=i;
			break;
		}
	}
	if(pos==0) return;
	for(ll i=pos;i<=cnt-1;i++) que[i]=que[i+1];
	cnt--;
}
void chuli(ll x)
{
	delete(x);
	que[++cnt]=x;
}
void moni(mem_addr_t address)
{
	ll tag=(address>>(b+s));
    mem_addr_t mask=((1ull<<63)-1)>>(63-s);
	ll i=(address>>b)&mask;
	for(ll j=0;j<=E-1;j++)
	{
		if(cache[wz(i,j)].valid_bit&&cache[wz(i,j)].tag_bit==tag)
		{
			hit_count++;
			chuli(wz(i,j));
			return;
		}
	}
	miss_count++;
	for(ll j=0;j<=E-1;j++)
	{
		if(!cache[wz(i,j)].valid_bit)
		{
			cache[wz(i,j)].valid_bit=1;
			cache[wz(i,j)].tag_bit=tag;
			chuli(wz(i,j));
			return;
		}
	}
	eviction_count++;
    for(ll j=1;j<=cnt;j++)
	{
		if(que[j]/mod==i) 
		{
			ll pos=que[j];
			cache[que[j]].tag_bit=tag;
			chuli(pos);
			return;
		}
	}
}
int main(int argc, char** argv){
    ll opt;    
    while(-1!=(opt=getopt(argc, argv, "s:E:b:t:"))) 
	{   
		if(opt=='s') 
		{
			s=atoi(optarg);
			S=(1<<s);
		}
		if(opt=='E') E=atoi(optarg);
		if(opt=='b') b=atoi(optarg);
		if(opt=='t') strcpy(fp, optarg);
    }
	mod=S;
	if(mod<E) mod=E;
    cache=malloc(mod*mod*mod*sizeof(Cache));
	que=malloc((mod*mod*mod+1)*sizeof(ll));
	FILE *f; 
    f=fopen(fp, "r");
    char identifier;
    mem_addr_t address;
    ll size;
    while(fscanf(f," %c  %llx,%lld",  &identifier, &address, &size)>0) 
	{
        switch(identifier)
        {
        	case 'M': 
			    moni(address);
        	case 'L':
        	case 'S':
        		moni(address);
        		break;
		}
    }
    printSummary(hit_count,miss_count,eviction_count);
    return 0;
}
