#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct zhuanyeke{
	string kexuhao;          //����� 
	ll xuefen;               //ѧ�� 
	ll xxkcs;                //���޿γ��� 
	string xianxiuke[110];   //���޿γ� 
};
zhuanyeke zyk[110];          //�洢�γ���Ϣ 
ll xqzs,xfsx,kczs,n=0,fangan[1000000][110],daan1[13][110],daan2[13][110],xq[13][110];
map<string,ll> mp;                           
ll topo[110],vis[110],indegree[110],dir[110][110],ans=0;     //topo[]��¼��������     
void dfs(ll x,ll cnt)       //indegree��¼�ȣ�vis����Ƿ���ʣ�
{   
	topo[cnt]=x;                            
	if(cnt==n) 
	{      
	    ans++;                                        
		for(ll i=1;i<=n;i++) fangan[ans][i]=topo[i];
		return;
	}
	vis[x]=1;                                      
	for(ll i=1;i<=n;i++) 
	{
		if(!vis[i]&&dir[x][i])  indegree[i]--;     
	}
	for(ll i=1;i<=n;i++)
	{
		if(!indegree[i]&&!vis[i])     dfs(i,cnt+1);
	}
	for(ll i=1;i<=n;i++) 
	{
		if(!vis[i]&&dir[x][i])    indegree[i]++;
	}
	vis[x]=0;      
}
void shuru()
{
	cout<<"ѧ��������";
	cin>>xqzs;
	cout<<"һ��ѧ��ѧ�����ޣ�";
	cin>>xfsx;
	cout<<"��רҵ������γ�����";
	cin>>kczs;
	cout<<"      ��רҵ�γ�\n";
	for(ll i=1;i<=kczs;i++)
	{
		cout<<"����ţ�";
		cin>>zyk[i].kexuhao;
		cout<<"ѧ�֣�";
		cin>>zyk[i].xuefen;
		cout<<"���޿γ�����";
		cin>>zyk[i].xxkcs;
		if(zyk[i].xxkcs!=0)
		{
			cout<<"�������������޿γ̵Ŀ���ţ�\n";
			for(ll j=1;j<=zyk[i].xxkcs;j++)  
			{
				cout<<j<<"��    ";
				cin>>zyk[i].xianxiuke[j];
			}
		} 
	} 
}
void chulishuru()
{
	n=kczs;
	for(ll i=1;i<=kczs;i++)	 mp[zyk[i].kexuhao]=i;
	for(ll i=1;i<=kczs;i++)
	{
		for(ll j=1;j<=zyk[i].xxkcs;j++)   //�����ÿγ����е����޿� 
		{
			ll t;
			t=mp[zyk[i].xianxiuke[j]];
			dir[t][i]=1;                 //����֮�����һ���� 
			indegree[i]++;               //���ڸñ�������ߣ��ÿγ̶�Ӧ�Ľ�������1 
		}
	}
}
void shuchu()
{ 
	cout<<"                        ��רҵ�γ�\n";
	cout<<"   �����        ѧ��        ���޿���       ���޿�\n";
	for(ll i=1;i<=n;i++)
	{
		cout<<setw(8)<<zyk[i].kexuhao<<setw(12)<<zyk[i].xuefen<<setw(12)<<zyk[i].xxkcs<<"            ";
		for(ll j=1;j<=zyk[i].xxkcs;j++) 
		{
			cout<<zyk[i].xianxiuke[j];
			if(j!=zyk[i].xxkcs) cout<<"��";
		}
		cout<<"\n";
	}
}
void caozuo1()
{
	double pjxf=0;
	ll x=0,t,cnt,qq,minsum,sum,flag=0;
	for(ll i=1;i<=n;i++) pjxf=pjxf+zyk[i].xuefen;
	minsum=pjxf;
	pjxf=pjxf/xqzs;
	for(ll i=1;i<=ans;i++)
	{
		cnt=0;
		qq=1;
		x=0;
		memset(xq,0,sizeof(xq));
		for(ll j=1;j<=n;j++)
		{
			t=fangan[i][j];
			if(x+zyk[t].xuefen<=pjxf)
			{
				x=x+zyk[t].xuefen;
				cnt++;
				xq[qq][0]++;
				xq[qq][cnt]=t;
			}
			else if(x+zyk[t].xuefen>=pjxf&&x+zyk[t].xuefen<=xfsx&&x<=pjxf)
			{
				if((pjxf-x)>=(xfsx-x-zyk[t].xuefen))
				{
					x=x+zyk[t].xuefen;
				    cnt++;
				    xq[qq][0]++;
				    xq[qq][cnt]=t;
				}
				else
				{
					x=zyk[t].xuefen;
				    cnt=1;
				    qq++;
				    xq[qq][cnt]=t;
				    xq[qq][0]++;
				}
			}
			else
			{
				x=zyk[t].xuefen;
				cnt=1;
				qq++;
				xq[qq][cnt]=t;
				xq[qq][0]++;
			}
		}
		sum=0;
		if(qq<=xqzs)
		{
			flag=1;
			for(ll ii=1;ii<=qq;ii++)
		    {
			    ll s=0;
			    for(ll jj=1;jj<=xq[ii][0];jj++)   s=s+zyk[xq[ii][jj]].xuefen;
			    sum=sum+abs(s-pjxf);
		    }
		    if(sum<=minsum)
		    {
			    minsum=sum;
			    memset(daan1,0,sizeof(daan1));
		        for(ll ii=1;ii<=qq;ii++)
			    {
			 	   for(ll jj=0;jj<=xq[ii][0];jj++)  daan1[ii][jj]=xq[ii][jj];
			    }				
		    }	
	    }			
	}
	if(flag==0)
	{
		cout<<"�Ҳ������з���\n";
		return;
	}
	for(ll i=1;i<=xqzs;i++)
	{   
	    cout<<"��"<<i<<"ѧ��"<<":  "; 
		for(ll j=1;j<=daan1[i][0];j++) 
		{
			cout<<zyk[daan1[i][j]].kexuhao<<"  ";
		}
		if(daan1[i][0]==0)   cout<<"��������ȫ��ѧ��\n"; 
		cout<<"\n"; 
	}
}
void caozuo2()
{
	ll x=0,t,cnt,qq,minqq=13; 
	for(ll i=1;i<=ans;i++)
	{
		cnt=0;
		qq=1;
		x=0;
		memset(xq,0,sizeof(xq));
		for(ll j=1;j<=n;j++)
		{
			t=fangan[i][j];
			if(x+zyk[t].xuefen<=xfsx) 
			{
				x=x+zyk[t].xuefen;
				cnt++;
				xq[qq][0]++;
				xq[qq][cnt]=t;
			}
			else
			{
				x=zyk[t].xuefen;
				cnt=1;
				qq++;
				xq[qq][cnt]=t;
				xq[qq][0]++;
			}
		}
		if(qq<minqq)
		{
			 memset(daan2,0,sizeof(daan2));
		     for(ll ii=1;ii<=qq;ii++)
			 {
			 	for(ll jj=0;jj<=xq[ii][0];jj++)  daan2[ii][jj]=xq[ii][jj];
			 }	
			 minqq=qq;
		}
		else if(qq==minqq)
		{
			ll sum1,sum2;
			for(ll ii=1;ii<=xq[qq][0];ii++) sum1=sum1+xq[qq][ii];
			for(ll ii=1;ii<=daan2[qq][0];ii++) sum2=sum2+daan2[qq][ii];
			if(sum1<sum2)
			{
				memset(daan2,0,sizeof(daan2));
		        for(ll ii=1;ii<=qq;ii++)
			    {
			 	  for(ll jj=0;jj<=xq[ii][0];jj++) daan2[ii][jj]=xq[ii][jj];
			    }	
			}
		}
	}
	if(minqq>xqzs)
	{
		cout<<"�Ҳ������з���\n";
		return;
	}	
	for(ll i=1;i<=minqq;i++)
	{   
	    cout<<"��"<<i<<"ѧ��"<<":  "; 
		for(ll j=1;j<=daan2[i][0];j++) 
		{
			cout<<zyk[daan2[i][j]].kexuhao<<"  ";
		}
		cout<<"\n"; 
	}
	if(minqq<=xqzs)
	{
		for(ll i=minqq+1;i<=xqzs;i++)
	    {   
	        cout<<"��"<<i<<"ѧ��"<<":  ��������ȫ��ѧ��\n"; 
	    }
	}
}
int main()
{
	ios::sync_with_stdio(false);
    while(ans==0)  
	{
		memset(dir,0,sizeof(dir));
	    memset(vis,0,sizeof(vis));
	    memset(indegree,0,sizeof(indegree));
	    shuru();
	    chulishuru();	
	    for(ll i=1;i<=n;i++)
	    {
		     if(!indegree[i])    dfs(i,1);
	    }
		if(ans==0) cout<<"������� ���޸�רҵ�γ�����\n";		 
	}
	shuchu();
	ll flag=1;
	char ch;
	while(flag)
	{
		cout<<"ִ�в���һ��ʹѧ���ڸ�ѧ���е�ѧϰ�����������ȣ�       ������1\n";
		cout<<"ִ�в�������ʹ�γ̾����ܵؼ�����ǰ����ѧ���У�         ������2\n";
		cout<<"�˳����رճ���                                       ������q\n";
		cin>>ch;
		if(ch=='1')  caozuo1();
		else if(ch=='2')  caozuo2();
		else flag=0;
	}	
	return 0;
}
