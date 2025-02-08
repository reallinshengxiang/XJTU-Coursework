#include<bits/stdc++.h>
using namespace std;
struct student{
	   long long id;
	      long long banji;
	         string name;
		    double score1;
		       double score2;
		          double score3;
			     double zongfen;
};
student a[10];
void print();
void input();
void del();
void sel();
void ord();
void opt();
long long flag=1,sum,ii=0;;
int main()
{
	   long long n;
	      print();
	         cin>>n;
		    while(n!=6)
			       {
				          if(n==1) input();
					     if(n==2) del();
					        if(n==3) sel();
						   if(n==4) ord();
						      if(n==5) opt();
						         cin>>n;     	
							    }
		    	
}
void print()
{
	   cout<<"1.input"<<endl<<"2.delete"<<endl<<"3.select"<<endl<<"4.order"<<endl<<"5.output"<<endl<<"6.quit"<<endl<<"please input your option"<<endl;
}
void input()
{
	   string ss;
	      while(flag)
		         {
				       ii++;
				             cin>>ss>>a[ii].id>>ss>>a[ii].banji>>ss>>a[ii].name>>ss>>a[ii].score1>>ss>>a[ii].score2>>ss>>a[ii].score3;
					           a[ii].zongfen=a[ii].score1+a[ii].score2+a[ii].score3;
						          cout<<"continue?"<<endl;
							        string s;
								      cin>>s;
									    cout<<s;
								            if(s=="yes") flag=1;
									          else if(s=="no")
											        {
													           flag=0;
														              print();
															            }
										        sum=ii;
											   }
	         flag=1;
}
void del()
{
	    long long i,num=0,l;
	        string ss;
		    while(flag)
			       {
				             cin>>ss;
					           l=ss.size();
						         long long f=0,k=0;
							       if(ss[0]>='0'&&ss[0]<='9')
								             {
										                f=1;
												          for(i=0;i<=l-1;i++)  num=num*10+ss[i]-'0';
													        }

							              for(i=1;i<=sum;i++)
									            {
											             if(a[i].id==num||a[i].name==ss)
													              {
															                  k=i;
																	              break;
																		               }
												           }
								             if(k)
										            {
												               for(i=k+1;i<=sum;i++) a[i-1]=a[i];
													              }
									            sum--;
										           for(i=1;i<=sum;i++) cout<<fixed<<setprecision(1)<<a[i].id<<","<<a[i].banji<<","<<a[i].name<<","<<a[i].score1<<","<<a[i].score2<<","<<a[i].score3<<","<<a[i].zongfen<<endl;
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
		        flag=1;
}
void sel()
{
	    long long i,num=0,l;
	        while(flag)
			   {
				         cin>>num;
					       long long f=0,k=0;
					             long long q=0;
						            for(i=1;i<=sum;i++)
								           {
										            if(a[i].id==num||a[i].banji==num)  
												    		 {
															 		 cout<<fixed<<setprecision(1)<<a[i].id<<","<<a[i].banji<<","<<a[i].name<<","<<a[i].score1<<","<<a[i].score2<<","<<a[i].score3<<","<<a[i].zongfen<<endl;
																	          q++;
																		  		 }
											    	   }
							    	   if(q==0) cout<<"there is no eligible student"<<endl;
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
		    flag=1;	
}
void ord()
{
		long long i,j;
			for(i=1;i<=sum-1;i++)
					{
								for(j=1;j<=sum-1;j++)
											{
															if(a[j].banji>a[j+1].banji||(a[j].banji==a[j+1].banji&&a[j].zongfen<a[j+1].zongfen)) swap(a[j],a[j+1]);
																	}
									}
				for(i=1;i<=sum;i++)  cout<<fixed<<setprecision(1)<<a[i].id<<","<<a[i].banji<<","<<a[i].name<<","<<a[i].score1<<","<<a[i].score2<<","<<a[i].score3<<","<<a[i].zongfen<<endl;
				    print();
}
void opt()
{
		long long i;
			for(i=1;i<=sum;i++)  cout<<fixed<<setprecision(1)<<a[i].id<<","<<a[i].banji<<","<<a[i].name<<","<<a[i].score1<<","<<a[i].score2<<","<<a[i].score3<<","<<a[i].zongfen<<endl;
}

