#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;
 
void print1(int *b,int (*g)[3]);
int move(int m,int (*g)[3],int*b,int*a);
void moveprint();
int print2(int f,int (*g)[3],int nullx,int nully);
 
void moveprint(){
	cout<<"\t\t————————————\n";
	cout<<"\n\n\t\t\t移动失败！\n\n\n";
	cout<<"\t\t————————————\n";
}
 
void print1(int *b,int (*g)[3]){
	int i,j,c=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==2&&j==2)
			{
			g[i][j]=9;	
			}else{
			
			g[i][j]=b[c];
		//	cout<<g[i][j]<<"检测="<<b[c]<<" "<<c<<endl;
			c++;
			
		}
		}
	}
	
            cout<<"\t\t\t得出随机拼图如下：\n";
            cout<<"\t\t——————————————\n";
	        cout<<"\t\t|\t┌──┬──┬──┐         |\n";
	        
			cout<<"\t\t|\t│ "<<b[0]<<"│ "<<b[1]<<"│ "<<b[2]<<"│         |\n";
			cout<<"\t\t|\t├──┼──┼──┤         |\n";
			cout<<"\t\t|\t│ "<<b[3]<<"│ "<<b[4]<<"│ "<<b[5]<<"│         |\n";
			cout<<"\t\t|\t├──┼──┼──┤         |\n";
			cout<<"\t\t|\t│ "<<b[6]<<"│ "<<b[7]<<"│ "<<" "<<"│         |\n";
			
			cout<<"\t\t|\t└──┴──┴──┘         |\n";
			cout<<"\t\t——————————————\n";
			
		
}
int print2(int f,int (*g)[3],int nullx,int nully){
	cout<<"\t\t————————————\n";
	cout<<"\t\t\t移动成功，拼图如下：\n";
	cout<<"\t\t\t┌──┬──┬──┐\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			
			if(j==0) {
				if(g[i][j]!=9) cout<<"\t\t\t│ "<<g[i][j];
				else cout<<"\t\t\t│ "<<" ";
			}
			else if(j==1){
				if(g[i][j]!=9) cout<<"│ "<<g[i][j];
				else cout<<"│ "<<" ";
			}
			else{
					if(g[i][j]!=9) cout<<"│ "<<g[i][j]<<"│ \n";
				else cout<<"│ "<<" "<<"│ \n";
			}
		}
		if(i==0) cout<<"\t\t\t├──┼──┼──┤\n";
		else if(i==1) cout<<"\t\t\t├──┼──┼──┤\n";	
		else  	cout<<"\t\t\t└──┴──┴──┘\n";
		
	}
	cout<<"\t\t————————————\n";
	if(f==0&&nullx==2&&nully==2) {
		cout<<"\t\t————————————\n";
	cout<<"\n\n\t\t\t拼图完成，恭喜通关！\n\n\n";
	cout<<"\t\t————————————\n";
	return 1;
	} else{
		return 0;
	}
}
 
int move(int m,int (*g)[3],int*b,int *a){
	int i=0,j=0,x=0,y=0,nullx=0,nully=0,flag=0;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(g[i][j]==m)
			{
				x=i;
				y=j;
				//cout<<"检测xy"<<x<<" "<<y;
				//cout<<"检gxy"<<g[i][j];
				//cout<<"检m"<<m;
				break;
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(g[i][j]==9)
			{
				nullx=i;
				nully=j;
			//	cout<<"检测nxy"<<nullx<<" "<<nullx;
			//	cout<<"检gnxy"<<g[i][j];
				
				break;
			}
		}
	}
	flag=0;
		if(nullx==0&&nully==0){
			if(x==0&&y==1) flag=1;
			if(x==1&&y==0) flag=1;
		}
		
		 else if(nullx==0&&nully==2){
			if(x==0&&y==1) flag=1;
			else if(x==1&&y==2) flag=1;
		}
		
		else if(nullx==2&&nully==0){
			if(x==1&&y==0) flag=1;
			else if(x==2&&y==1) flag=1;
		}
		
		else if(nullx==2&&nully==2){
			if(x==1&&y==2) flag=1;
			else if(x==2&&y==1) flag=1;
		}
			
		
	     else if(nullx==1&&nully==1){
		if(x==0&&y==1) flag=1;
		else if(x==1&&y==0) flag=1;
		else if(x==2&&y==1) flag=1;
		else if(x==1&&y==2) flag=1;
	//	cout<<"检flg"<<flag;
		//cout<<"检x"<<x;
		//cout<<"检y"<<y;
     	}
	    	else if((nullx==1&&nully==0)||(nullx==1&&nully==2))
	    	{
	    		if((x==nullx+1||x==nullx-1)&&y==nully) flag=1;
	    		if(x==1&&y==1) flag=1;
			}
			
			else if((nullx==0||nullx==2)&&nully==1) 
			{
				if((y==nully+1||y==nully-1)&&x==nullx) flag=1;
				if(x==1&&y==1) flag=1;
			}
			int X=x;
	int Y=y;
		
		
		//cout<<"检测"<<flag;
	if(flag==1){
		//cout<<"检X"<<X;
		//cout<<"检Y"<<Y;
	int T1=g[x][y];//8
		int T2=g[nullx][nully];//9
		//cout<<"检gxy"<<T1;
		//cout<<"检gnxny"<<T2;
int t1,t2;//g[x][y]=9,g[nx][ny]=8
 
t1=x;t2=y;
//cout<<"检t1"<<t1;
		//cout<<"检t2"<<t2;
x=nullx;y=nully;
nullx=t1;nully=t2;//交换下标 
//cout<<"检nx"<<nullx;
	//	cout<<"检ny"<<nully;
 g[x][y]=T1;//8
 g[nullx][nully]=T2;//9
 //cout<<"检gxy"<< g[x][y];
		//cout<<"检gnxy"<< g[nullx][nully];
int c=0;int C=0;
for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			//cout<<"检g"<<g[i][j];
			
		}
	}
	int f=0,v=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		if(g[i][j]!=a[v]&&g[i][j]!=9){//不相同 //
		//cout<<"检gij"<<g[i][j]<<" "<<a[v];
		f=1	;
		break;
	   }else if(g[i][j]!=9&&g[i][j]==a[v]){
	   //cout<<"检f"<<f<<" "<<v;
	v++;
}
	}
	}
	int z=print2(f,g,nullx,nully);
	return z;
}
else{
	moveprint();
}
}
 
 
int main(){
	int i,j;int flag=0,rc=0,count=0,r;
	
	srand((unsigned)time(NULL));
	
	int* a=new int[8];
	int (*g)[3]=new int[3][3];
	for(i=1;i<=8;i++)//数列a 
	{
		a[i-1]=i;
		//cout<<"检a"<<i-1<<" "<<i;
	}
 
	int* b=new int[8];
 
	while(count<8){//随机b 
		r=rand()%8+1;
		flag=0;
		for(j=0;j<8;j++){
			if(b[j]==r){//已存在 
				flag=1;
			}
		}
		if(flag!=1){
			b[count]=r;
			count++;	
		}
	} 
	int s;
	cout<<"\t\t\t请按①进入游戏\n";
	cin>>s;
	if(s==1) {
	
	print1(b,g);
}else{
	cout<<"\t\t\t已经退出!\n";
}
int m,n;
int Z=0;
 
	while(1) 
	{
 
if(Z!=1){
	cout<<"\t\t\t请输入需要移动的数字\n";
	cin>>m;
	 Z=move(m,g,b,a);
	 //cout<<"检Z"<<Z;
}else{
	break;
}
}
	
}
