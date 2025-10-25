#include<bits/stdc++.h>
using namespace std;
#define ll long long
int A[100][100],B[100][100],M=8,N=8;
void print()
{
	for(ll i=0;i<M;i++)
	{
		for(ll j=0;j<N;j++) cout<<B[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
int main()
{
	for(ll i=0;i<M;i++)
	{
		for(ll j=0;j<N;j++) A[i][j]=i*N+j;
	}
        print();
        int x0,x1,x2,x3,x4,x5,x6,x7;
        for (int posi=0;posi<M;posi=posi+8) 
        {
            for(int posj=0;posj<N;posj=posj+8)
            {
                for(int x=posi;x<posi+4;x++)
                {
                    x0=A[x][posj],x1=A[x][posj+1];
                    x2=A[x][posj+2],x3=A[x][posj+3];
                    x4=A[x][posj+4],x5=A[x][posj+5];
                    x6=A[x][posj+6],x7=A[x][posj+7];
                    B[posj][x]=x0,B[posj+1][x]=x1;
                    B[posj+2][x]=x2,B[posj+3][x]=x3;
                    B[posj][x+4]=x4,B[posj+1][x+4]=x5;
                    B[posj+2][x+4]=x6,B[posj+3][x+4]=x7;
                }
                print();
                for(int y=posj;y<posj+4;y++)
                {
                    x0=A[posi+4][y];
                    x1=A[posi+5][y];
                    x2=A[posi+6][y];
                    x3=A[posi+7][y];
                    x4=B[y][posi+4];
                    x5=B[y][posi+5];
                    x6=B[y][posi+6];
                    x7=B[y][posi+7];
                    B[y][posi+4]=x0;
                    B[y][posi+5]=x1;
                    B[y][posi+6]=x2;
                    B[y][posi+7]=x3;
                    B[y+4][posi]=x4;
                    B[y+4][posi+1]=x5;
                    B[y+4][posi+2]=x6;
                    B[y+4][posi+3]=x7;
                }
                print();
                for (int x=posi+4;x<posi+8;x++)
                {
					x0=A[x][posj+4];
					x1=A[x][posj+5];
					x2=A[x][posj+6];
					x3=A[x][posj+7];
					B[posj+4][x]=x0;
					B[posj+5][x]=x1;
					B[posj+6][x]=x2;
					B[posj+7][x]=x3;
				}
            }
        }
        print();
    
 } 
