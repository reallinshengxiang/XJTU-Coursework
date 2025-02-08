#include<bits/stdc++.h>
using namespace std;
struct node{
   long long id;
   long long banji;
   string name;
   double score1;
   double score2;
   double score3;
   double zongfen;
   node *next;
};
void print();
void input(node*);
node *del(node*);
void sel(node*);
node *ord(node*);
void output(node*);
int main()
{
	node *head,*phead;
	head=new node;
	head->next=NULL;
	long long n;
    print();
    cin>>n;
    while(n!=6)
    {
     if(n==1) 
	 {
	 	phead=head;
	 	input(phead);
	 }
     if(n==2) 
	 {
	 	phead=head;
	 	head=del(phead);
	 }
     if(n==3) 
	 {
	 	phead=head;
	 	sel(phead);
	 }
     if(n==4) 
	 {
	 	phead=head;
	 	head=ord(phead);
	 }
     if(n==5) 
	 {
	 	phead=head;
	 	output(phead);
		print();
	 }
     cin>>n;     	
    }
}
void print()
{
   cout<<"1.input"<<endl<<"2.delete"<<endl<<"3.select"<<endl<<"4.order"<<endl<<"5.output"<<endl<<"6.quit"<<endl<<"please input your option"<<endl;
}
void input(node*head)
{
	node *p,*r;
	long long flag=1;
	r=head;
	while(r->next!=NULL) r=r->next;
	while(flag)
	{
	  p=new node;
	  cout<<"Id ";
          cin>>p->id;
	  cout<<"class ";
	  cin>>p->banji;
	  cout<<"name ";
	  cin>>p->name;
	  cout<<"score1 ";
	  cin>>p->score1;
	  cout<<"score2 ";
	  cin>>p->score2;
	  cout<<"score3 ";
	  cin>>p->score3;
      p->zongfen=p->score1+p->score2+p->score3;
      p->next=NULL;
      r->next=p;
      r=p;
      cout<<"continue?"<<endl;
      string s;
      cin>>s;
      if(s=="yes") flag=1;
      else if(s=="no")
      {
           flag=0;
           print();
      }
	}
}
node* del(node *head)
{
	node *p;
	long long flag=1;
	while(flag)
    {
	  p=head;
	  string ss;
          cin>>ss;
          node *r;
          long long num=0,i;
          if(ss[0]>='0'&&ss[0]<='9')
          {
           for(i=0;i<=ss.size()-1;i++)  num=num*10+ss[i]-'0';
          }
	  while(p->next->next!=NULL) 
	  {
	  	 if(p->next->name==ss||p->next->id==num)
	  	 {
	  	 	r=p->next;
	  	 	p->next=p->next->next;
	  	 	delete(r);
		 }
		 else	p=p->next;
	  }
	  if(p->next->next==NULL)
	  {
	  	if(p->next->name==ss||p->next->id==num)
	  	{
	  		r=p->next;
	  		p->next=NULL;
	  		delete(r);
		}
	  }	
	  output(head);
	  cout<<"continue?"<<endl;
          string aa;
          cin>>aa;
          if(aa=="yes") flag=1;
          else if(aa=="no")
          {
           flag=0;
           print();
      	   return(head);
          }
	}
}
void sel(node *head)
{
	node *p;
	long long x,flag=1;
	while(flag)
	{
	   cin>>x;
	   p=head->next;
	   while(p->next!=NULL)
	   {
		if(p->banji==x||p->id==x) cout<<fixed<<setprecision(1)<<p->id<<","<<p->banji<<","<<p->name<<","<<p->score1<<","<<p->score2<<","<<p->score3<<","<<p->zongfen<<endl;
		p=p->next;
	   }
	   if(p->banji==x||p->id==x) cout<<fixed<<setprecision(1)<<p->id<<","<<p->banji<<","<<p->name<<","<<p->score1<<","<<p->score2<<","<<p->score3<<","<<p->zongfen<<endl;
	   	cout<<"continue?"<<endl;
        string s;
        cin>>s;
        if(s=="yes") flag=1;
        else if(s=="no")
        {
           flag=0;
           print();
        }
	 }
}
node *ord(node *head)
{
	node *p,*maxx,*q;
	p=head->next;
	q=head;
	while(q->next!=NULL)
	{
		maxx=q->next;
	   while(p->next!=NULL)
	  {
		if(p->banji<maxx->banji||(p->banji==maxx->banji&&p->zongfen>maxx->zongfen))  maxx=p;
		p=p->next;
		
	  }
	   if(p->banji<maxx->banji||(p->banji==maxx->banji&&p->zongfen>maxx->zongfen))  maxx=p;
	   maxx->next=q->next->next;
	   q->next=maxx;
	   q=q->next;		
	}
	output(head);
        return(head);	
}
void output(node *head)
{
	node *p;
	p=head->next;
	while(p!=NULL) 
	{
		cout<<fixed<<setprecision(1)<<p->id<<","<<p->banji<<","<<p->name<<","<<p->score1<<","<<p->score2<<","<<p->score3<<","<<p->zongfen<<endl;
		p=p->next;
	 } 
}


