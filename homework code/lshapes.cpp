#include<bits/stdc++.h>
using namespace std;
long long a[55][55];
int main()
{
	    long long t,m,n,i,j,k,jj,kk;
	        char tt;
		    scanf("%lld",&t);
		        for(i=1;i<=t;i++)
				    {
					            scanf("%lld%lld",&m,&n);
						            memset(a,0,sizeof(a));
							            for(j=1;j<=m;j++)
									            {
											               for(k=1;k<=n;k++)
													                  {
																                  cin>>tt;
																		                  if(tt=='*') a[j][k]=1;
																				                  else a[j][k]=0;
																						             }
												               }
								            long long flag=1;
									            for(j=1;j<=m&&flag;j++)
											            {   
													                for(k=1;k<=n&&flag;k++)
																           {
																		                 if(a[j][k]==1)
																					               {
																							                         if(a[j+1][k]==1&&a[j][k+1]==1)
																											                   {
																														                         for(jj=j-1;jj<=j+2&&flag;jj++)
																																		                      {
																																					                              for(kk=k-1;kk<=k+2&&flag;kk++)
																																									                              {
																																													                                 if(!((jj==j&&kk==k)||(jj==j&&kk==k+1)||(jj==j+1&&kk==k)||(jj==j+2&&kk==k+2)))
																																																		                            {
																																																						                                   if(a[jj][kk]!=0)
																																																											                                  {
																																																																                                     flag=0;
																																																																				                                         printf("NO\n");
																																																																									                                }
																																																										                              }
																																																	                         }
																																								                           }
																																	                      if(flag) a[j][k]=a[j+1][k]=a[j][k+1]=0;
																																			                        }
																										                   else if(a[j+1][k+1]==1&&a[j][k+1]==1)
																													                     {
																																                           for(jj=j-1;jj<=j+2&&flag;jj++)
																																				                        {
																																								                        for(kk=k-1;kk<=k+2&&flag;kk++)
																																												                        {
																																																                           if(!((jj==j&&kk==k)||(jj==j&&kk==k+1)||(jj==j+1&&kk==k+1)||(jj==j+2&&kk==k-1)))
																																																				                              {
																																																								                                     if(a[jj][kk]!=0)
																																																													                                    {
																																																																		                                       flag=0;
																																																																						                                           printf("NO\n");
																																																																											                                  }
																																																												                                }
																																																			                           }
																																											                     }
																																			                        if(flag) a[j][k]=a[j][k+1]=a[j+1][k+1]=0;
																																						                  }
																												                     else if(a[j+1][k+1]==1&&a[j+1][k]==1)
																															                       {
																																		                             for(jj=j-1;jj<=j+2&&flag;jj++)
																																						                          {
																																										                          for(kk=k-1;kk<=k+2&&flag;kk++)
																																														                          {
																																																		                             if(!((jj==j&&kk==k)||(jj==j+1&&kk==k+1)||(jj==j+1&&kk==k)||(jj==j-1&&kk==k+2)))
																																																						                                {
																																																											                               if(a[jj][kk]!=0)
																																																															                                      {
																																																																				                                         flag=0;
																																																																									                                     printf("NO\n");
																																																																													                                    }
																																																														                                  }
																																																					                             }
																																													                       }
																																					                          if(flag) a[j][k]=a[j+1][k]=a[j+1][k+1]=0;
																																								                    }
																														                       else if(a[j+1][k-1]==1&&a[j+1][k]==1)
																																	                         {
																																					                       for(jj=j-1;jj<=j+2&&flag;jj++)
																																								                            {
																																												                            for(kk=k-2;kk<=k+1&&flag;kk++)
																																																                            {
																																																				                               if(!((jj==j&&kk==k)||(jj==j+1&&kk==k-1)||(jj==j+1&&kk==k)||(jj==j-1&&kk==k+1)))
																																																								                                  {
																																																													                                 if(a[jj][kk]!=0)
																																																																		                                {
																																																																							                                   flag=0;
																																																																											                                       printf("NO\n");
																																																																															                                      }
																																																																	                            }
																																																							                               }
																																															                         }
																																							                            if(flag) a[j][k]=a[j+1][k]=a[j+1][k-1]=0;
																																										                      }
																																                         else
																																				                   {
																																							                     	    flag=0;
																																										                            printf("NO\n");
																																													    				  }
																																			              } 
																				          }
															       }
										           if(flag) printf("YES\n");
											      }
}

