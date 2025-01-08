#include<cstdio>
#include<cstring>
#include<algorithm>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
#define MAXN 35
#define MIDX 10
#define MIDY 40
#define CG 25
#define CK 80
int G,K,Lnum,Wnum;
int nx,ny;
bool QR=0,Lose=0,is_flag_true[MAXN][MAXN];
char map[MAXN][MAXN],tmap[MAXN][MAXN];
int map1[MAXN][MAXN],mapc[MAXN][MAXN];
int col[10]={240,249,242,252,241,244,243,240,248};
int d[10][4]={{0},{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool ZB;
void color(int);
void gto(int,int);
void make();
void print();
bool check(int,int);
bool is_win();
bool is_lose();
void dfs(int,int);
void st(int,int);
void flag(int,int);
void bj(int,int);
void swt();
void again();
void zb();
void mainmain();
void print_real_map();
void begin();
void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
void gto(int x,int y)
{
    COORD pos;pos.X=y;pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void make()
{
    for(int i=1;i<=G;i++)
    {
    	for(int j=1;j<=K;j++)  map[i][j]='#';
	}                   
    for(int i=1;i<=Lnum;i++)
    {
        int x=rand()%G+1;
		int y=rand()%K+1;
        while(map[x][y]=='O')
        {
        	x=rand()%G+1;
        	y=rand()%K+1;
		}          
        map[x][y]='O';
    }
    for(int i=1;i<=G;i++)
    {
    	for(int j=1;j<=K;j++)
        {
            if(map[i][j]=='O') 
			{
				map1[i][j]=-1;
				mapc[i][j]=240;
			}
            else
            {
                for(int k=1;k<=8;k++)
                {
                	if(map[i+d[k][0]][j+d[k][1]]=='O')   map1[i][j]++;
				}                       
                mapc[i][j]=col[map1[i][j]];
            }
        }
	}      
    for(int i=1;i<=G;i++)
    {
    	for(int j=1;j<=K;j++)
    	{
    		if(mapc[i][j]==0)  mapc[i][j]=240;
		}
	}              
}
void print()
{
    system("cls");
    gto(0,MIDY-4); 
	color(233); 
	printf("ɨ��");
    color(240);
    gto(1,MIDY);
    for(int i=2;i<=G+1;i++)
    {
        gto(i,0);
        for(int j=1;j<=K;j++)
        {
        	printf("#");
        	tmap[i-1][j]='#';
		}           
    }
    gto(2,0);
    nx=2,ny=0;
    color(15);
    printf("@");
    color(15);
    gto(2,2*K+5);
	cout<<"-----����-----";
    gto(3,2*K+5);
	cout<<"wasd��ѡ��λ��";
    gto(4,2*K+5);
	cout<<"�ո񣺴�";
    gto(5,2*K+5);
	cout<<"1������̽��Χ8�����飬������������򲻻�򿪣���";
    gto(6,2*K+5);
	cout<<"     �׻����ı������Ὣ��Χ���׵�λ�ô򿪣�";
    gto(7,2*K+5);
	cout<<"     �����̽ʱ��Χ�б������ģ������Ϸʧ��";
    gto(8,2*K+5);
	cout<<"     �������ȷ��һ�Σ��Ա�鿴��Χ����̽������";
    gto(9,2*K+5);
	cout<<"2��������/ȡ��С�죨F��";
    gto(10,2*K+5);
	cout<<"3��������/ȡ����ǣ�����";
    gto(11,2*K+5);
	cout<<"4������/�ر�ȷ��ģʽ����ÿ�β������ٰ�һ��ȷ��";
    gto(12,2*K+5);
	cout<<"5������/�ر�����ģʽ������ʾԭ����ͼ";
    gto(13,2*K+5);
	cout<<"0�������¿�ʼ";
    gto(G+4,0);
	cout<<"-----������ʾ-----\n";
    cout<<"��ѡ�񷽿���в���";
    gto(1,2*K+10);
	color(12);
	Wnum=Lnum;
	cout<<"ʣ��С������"<<Lnum;
}
bool check(int x,int y)
{
    return y>=0&&y<K&&x>=2&&x<G+2;
}
bool is_win()
{
    int cnt=0;
    for(int i=1;i<=G;i++)
    {
    	for(int j=1;j<=K;j++)
    	{
    		if(map[i][j]=='#'&&map1[i][j]==-1)  cnt++;
		}
	}     
    if(cnt==Lnum) return 1;
    for(int i=1;i<=G;i++)
    {
    	for(int j=1;j<=K;j++)
    	{
    		if((tmap[i][j]!='F'&&map1[i][j]==-1)||(tmap[i][j]=='F'&&map1[i][j]!=-1))  return 0;
		}
	}             
    return 1;
}
bool is_lose(){return Lose;}
void dfs(int x,int y)
{
    if(map1[x-1][y+1]>0)
    {
        gto(x,y);
		color(mapc[x-1][y+1]);
		cout<<map1[x-1][y+1];
        tmap[x-1][y+1]=map1[x-1][y+1]+'0';
        return;
    }
    gto(x,y);
	color(255);
    tmap[x-1][y+1]=' ';
    cout<<" ";
    for(int i=1;i<=8;i++)
    {
        int xx=x+d[i][0]-1,yy=y+d[i][1]+1;
        if(check(xx+1,yy-1)&&tmap[xx][yy]=='#'&&map1[xx][yy]!=-1)
            dfs(xx+1,yy-1);
    }
}
void st(int x,int y)
{
    for(int i=1;i<=8;i++)
    {
        int xx=x+d[i][0],yy=y+d[i][1];
        if(check(xx,yy))
        {
            gto(xx,yy);
            if(tmap[xx-1][yy+1]!='#')
                color(mapc[xx-1][yy+1]-128);
            else
                color(112);
            cout<<tmap[xx-1][yy+1];
        }
    }
    gto(G+5,0);
	color(15);
	cout<<"��ȷ��                                      ";
    char c=getch();
    if(c=='1')
    {
        for(int i=1;i<=8;i++)
        {
            int xx=x+d[i][0];
			int yy=y+d[i][1];
            if(check(xx,yy))
                if(tmap[xx-1][yy+1]=='F'&&map1[xx-1][yy+1]!=-1)
                {
                    Lose=1;
                    return;
                }
        }
        for(int i=1;i<=8;i++)
        {
            int xx=x+d[i][0];
			int yy=y+d[i][1];
            if(check(xx,yy))
                if(map1[xx-1][yy+1]==-1&&tmap[xx-1][yy+1]!='F')
                    return;
        }
        for(int i=1;i<=8;i++)
        {
            int xx=x+d[i][0];
			int yy=y+d[i][1];
            if(check(xx,yy)&&tmap[xx-1][yy+1]=='#')
                dfs(xx,yy);
        }
    }
}
void flag(int x,int y)
{
    x-=1,y+=1;
    if(tmap[x][y]=='F')
    {
        tmap[x][y]='#';
		mapc[x][y]=240;
        gto(x+1,y-1);
		color(240);
		cout<<"#";
        Wnum++;
    }
    else
    {
        is_flag_true[x][y]=map1[x][y]==-1;
        tmap[x][y]='F';
		mapc[x][y]=253;
        gto(x+1,y-1);
		color(253);
		cout<<"F";
        Wnum--;
    }
    gto(1,2*K+10);
	color(12);
	cout<<"ʣ��С������       ";
    gto(1,2*K+22);
	cout<<Wnum;
}
void bj(int x,int y)
{
    x-=1,y+=1;
    if(tmap[x][y]=='?')
    {
        gto(x+1,y-1);
		color(240);
		cout<<"#";
        tmap[x][y]='#';
		mapc[x][y]=240;
    }
    else
    {
        if(tmap[x][y]=='F')
        {
            Wnum++;
            gto(1,2*K+10);
			color(12);
			cout<<"ʣ��С������       ";
            gto(1,2*K+22);
			cout<<Wnum;
        }
        gto(x+1,y-1);
		color(240);
		cout<<"?";
        tmap[x][y]='?';
		mapc[x][y]=240;
    }
}
void swt(){QR=!QR;}
void zb()
{
    if(ZB)
    {
        for(int i=1;i<=G;i++)
        {
            gto(i+1,K+2);
            for(int j=1;j<=K;j++)
            {
            	color(15);
				cout<<" ";
			}
                
        }
        ZB=0;
    }
    else
    {
        for(int i=1;i<=G;i++)
        {
            gto(i+1,K+2);
            for(int j=1;j<=K;j++)
            {
                color(mapc[i][j]);
                if(map1[i][j]==-1) cout<<"O";
                else if(map1[i][j]>0) cout<<map1[i][j];
                else cout<<" ";
            }
        }
        ZB=1;
    }
}
void again()
{
    G=K=Lnum=nx=ny=Lose=ZB=0;
    QR=0;
    memset(is_flag_true,0,sizeof(is_flag_true));
    memset(map,0,sizeof(map));
    memset(tmap,0,sizeof(tmap));
    memset(map1,0,sizeof(map1));
    memset(mapc,0,sizeof(mapc));
    color(15);
    system("cls");
    mainmain();
}
void begin()
{
    char c=getch();
    gto(G+5,0);
	color(15);
	cout<<"��ѡ�񷽿���в���";
    color(240);
    if(c=='w'&&check(nx-1,ny))
    {
        gto(nx,ny);
        if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')   color(mapc[nx-1][ny+1]);
        cout<<tmap[nx-1][ny+1];
        gto(nx-=1,ny);
		color(15);
		cout<<"@";
    }
    else if(c=='s'&&check(nx+1,ny))
    {
        gto(nx,ny);
		if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')   color(mapc[nx-1][ny+1]);		
		cout<<tmap[nx-1][ny+1];
        gto(nx+=1,ny);
		color(15);
		cout<<"@";
    }
    else if(c=='a'&&check(nx,ny-1))
    {
        gto(nx,ny);
		if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')  color(mapc[nx-1][ny+1]);
		cout<<tmap[nx-1][ny+1];
        gto(nx,ny-=1);
		color(15);
		cout<<"@";
    }
    else if(c=='d'&&check(nx,ny+1))
    {
        gto(nx,ny);
		if(tmap[nx-1][ny+1]!='#'||tmap[nx-1][ny+1]==' ')  color(mapc[nx-1][ny+1]);
		cout<<tmap[nx-1][ny+1];
        gto(nx,ny+=1);
		color(15);
		cout<<"@";
   }
    else
    {
        if(c==' '&&(!(tmap[nx-1][ny+1]<='9'&&tmap[nx-1][ny+1]>='0'))&&tmap[nx-1][ny+1]!='F')
        {
            mapc[nx-1][ny+1]=col[map1[nx-1][ny+1]];
            if(QR)
            {
                gto(G+5,0);
				color(15);
				cout<<"��ȷ��                                      ";
                if(getch()==' ')
                {
                    if(map1[nx-1][ny+1]==-1) 
					{  Lose=1;
					   return;
					}
                    dfs(nx,ny);
                }
            }
            else
            {
                if(map1[nx-1][ny+1]==-1) 
				{
				    Lose=1;
					return;
				}
                dfs(nx,ny);
            }
        }
        else if(c=='1')
        {
            if(QR)
            {
                gto(G+5,0);
				color(15);
				cout<<"��ȷ��                                      ";
                if(getch()=='1') st(nx,ny);
            }
            else st(nx,ny);
            for(int i=1;i<=8;i++)
            {
                int xx=nx+d[i][0];
				int yy=ny+d[i][1];
                if(check(xx,yy))
                {
                    gto(xx,yy);
                    if(tmap[xx-1][yy+1]!='#') color(mapc[xx-1][yy+1]);
                    else color(240);
                    cout<<tmap[xx-1][yy+1];
                }
            }
        }
        else if(c=='2'&&(tmap[nx-1][ny+1]>'9'||tmap[nx-1][ny+1]<'1'))
        {
            if(QR)
            {
                gto(G+5,0);
				color(15);
				cout<<"��ȷ��                                      ";
                if(getch()=='2') flag(nx,ny);
            }
            else flag(nx,ny);
        }
        else if(c=='3'&&(tmap[nx-1][ny+1]>'9'||tmap[nx-1][ny+1]<'1'))
        {
            if(QR)
            {
                gto(G+5,0);
				color(15);
				cout<<"��ȷ��                                      ";
                if(getch()=='3') bj(nx,ny);
            }
            else bj(nx,ny);
        }
        else if(c=='4')
        {
            if(QR)
            {
                gto(G+5,0);
				color(15);
				cout<<"��ȷ��                                      ";
                if(getch()=='4') swt();
            }
            else swt();
        }
        else if(c=='5')
        {
            if(QR)
            {
                gto(G+5,0);
				color(15);
				cout<<"��ȷ��                                      ";
                if(getch()=='5') zb();
            }
            else zb();
        }
        else if(c=='0')
        {
            if(QR)
            {
                gto(G+5,0);
				color(15);
				cout<<"��ȷ��                                      ";
                if(getch()=='0') again();
            }
            else again();
        }
    }
}
void print_real_map()
{
    color(240);
    for(int i=1;i<=G;i++)
    {
        gto(i+1,0);
        for(int j=1;j<=K;j++)
        {
            if(tmap[i][j]=='F'&&is_flag_true[i][j]==0)
            {
            	color(252);
				cout<<"X";
			}               
            else if(map1[i][j]==-1)
            {
            	color(240);
				cout<<"O";
			}               
            else if(map1[i][j]==0)
            {
            	color(240);
				cout<<" ";
			}               
            else
            {
            	color(mapc[i][j]);
            	cout<<map1[i][j];
			}
        }
    }
}
typedef struct Frame
{
	COORD position[2];
	int flag;
}Frame;
void SetPos(COORD a)
{
	HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}
void SetPos(int i, int j)
{
	COORD pos={i, j};
	SetPos(pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void drawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1,y);
	for(int i = 0; i <= (x2-x1); i++)
		cout<<ch;
}
void drawRow(COORD a, COORD b, char ch)
{
	if(a.Y == b.Y)
		drawRow(a.Y, a.X, b.X, ch);
	else
	{
		SetPos(0, 25);
		cout<<"error code 01���޷�����У���Ϊ���������������(x)�����";
		system("pause");
	}
}
void drawCol(int x, int y1, int y2, char ch)
{
	int y=y1;
	while(y!=y2+1)
	{
		SetPos(x, y);
		cout<<ch;
		y++;
	}
}
void drawCol(COORD a, COORD b, char ch)
{
	if(a.X == b.X)
		drawCol(a.X, a.Y, b.Y, ch);
	else
	{
		SetPos(0, 25);
		cout<<"error code 02���޷�����У���Ϊ��������ĺ�����(y)�����";
		system("pause");
	}
}
void drawFrame(COORD a, COORD  b, char row, char col)
{
	drawRow(a.Y, a.X+1, b.X-1, row);
	drawRow(b.Y, a.X+1, b.X-1, row);
	drawCol(a.X, a.Y+1, b.Y-1, col);
	drawCol(b.X, a.Y+1, b.Y-1, col);
}
void drawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
	COORD a={x1, y1};
	COORD b={x2, y2};
	drawFrame(a, b, row, col);
}
void drawFrame(Frame frame, char row, char col)
{
	COORD a = frame.position[0];
	COORD b = frame.position[1];
	drawFrame(a, b, row, col);
}
void drawPlaying()
{
	drawFrame(0, 0, 48, 24, '=', '|');
	drawFrame(49, 0, 79, 4, '-', '|');
	drawFrame(49, 4, 79, 9, '-', '|');
	drawFrame(49, 9, 79, 20, '-', '|');
	drawFrame(49, 20, 79, 24, '-', '|');
	SetPos(52, 6);
	cout<<"�÷֣�";
	SetPos(52, 7);
	cout<<"�ƺţ�";
	SetPos(52,10);
	cout<<"������ʽ��";
	SetPos(52,12);
	cout<<"  a,s,d,w ����ս���ƶ���";
	SetPos(52,14);
	cout<<"  p ��ͣ��Ϸ��";
	SetPos(52,16);
	cout<<"  e �˳���Ϸ��";
}
int random(int a, int b)
{
	int c=(rand() % (a-b))+ a;
	return c;
}
COORD random(COORD a, COORD b)
{
	int x=random(a.X, b.X);
	int y=random(a.Y, b.Y);
	COORD c={x, y};
	return c;
}
bool  judgeCoordInFrame(Frame frame, COORD spot)
{
	if(spot.X>=frame.position[0].X)
	{
		if(spot.X<=frame.position[1].X)
		{
			if(spot.Y>=frame.position[0].Y)
			{
				if(spot.Y<=frame.position[0].Y)   return true;
			}				
		}
	}		
	return false;
}
void printCoord(COORD a)
{
	cout	<<"( "<<a.X<<" , "<<a.Y<<" )";
}
void printFrameCoord(Frame a)
{
	printCoord(a.position[0]);
	cout	<<" - ";
	printCoord(a.position[1]);
}
int drawMenu()
{
	SetPos(30, 1);
	cout<<"P l a n e  W a r";
	drawRow(3, 0, 79, '-');
	drawRow(5, 0, 79, '-');
	SetPos(28, 4);
	cout<<"w �� s ѡ�� k ȷ��";
	SetPos(15, 11);
	cout<<"1. �򵥵ĵ���";
	SetPos(15, 13);
	cout<<"2. ���ĵ���";
	drawRow(20, 0, 79, '-');
	drawRow(22, 0, 79, '-');
	SetPos(47, 11);
	cout<<"�򵥵ĵ��ˣ�";
	SetPos(51, 13);
	cout<<"�򵥵������Ž������ƶ��ٶȡ�";
	int j=11;
	SetPos(12, j);
	cout<<">>";
	while(1)
	{	if( _kbhit() )
		{
			char x=_getch();
			switch (x)
			{
			case 'w' :
					{
						if( j == 13)
						{
							SetPos(12, j);
							cout<<"��";
							j = 11;
							SetPos(12, j);
							cout<<">>";
							SetPos(51, 13);
							cout<<"������������������������";
							SetPos(47, 11);
							cout<<"�򵥵ĵ��ˣ�";
							SetPos(51, 13);
							cout<<"�򵥵����н������ƶ��ٶȣ��Ƚ����׶Ը�";
						}
						break;
					}
			case 's' :
					{
						if( j == 11 )
						{
							SetPos(12, j);
							cout<<"��";
							j = 13;
							SetPos(12, j);
							cout<<">>";
							SetPos(51, 13);
							cout<<"����������������������������";
							SetPos(47, 11);
							cout<<"���ĵ��ˣ�";
							SetPos(51, 13);
							cout<<"���ĵ����ƶ��ٶȽϿ죬���ǺܺöԸ�Ӵ��";
						}
						break;
					}
			case 'k' :
					{
						if (j == 8)	return 1;
						else return 2;
					}
			}
		}
	}
}
class Game
{
public:
	COORD position[10];
	COORD bullet[10];
	Frame enemy[8];
	int score;
	int rank;
	int rankf;
	string title;
	int flag_rank;
	Game ();
	void initPlane();
	void initBullet();
	void initEnemy();
	void planeMove(char);
	void bulletMove();
	void enemyMove();
	void drawPlane();
	void drawPlaneToNull();
	void drawBullet();
	void drawBulletToNull();
	void drawEnemy();
	void drawEnemyToNull();
	void drawThisBulletToNull( COORD );
	void drawThisEnemyToNull( Frame );
	void Pause();
	void Playing();
	void judgePlane();
	void judgeEnemy();
	void Shoot();
	void GameOver();
	void printScore();
};
Game::Game()
{
	initPlane();
	initBullet();
	initEnemy();
	score=0;
	rank=25;
	rankf=0;
	flag_rank = 0;
}
void Game::initPlane()
{
	COORD centren={39, 22};
	position[0].X=position[5].X=position[7].X=position[9].X=centren.X;
	position[1].X=centren.X-2;
	position[2].X=position[6].X=centren.X-1;
	position[3].X=position[8].X=centren.X+1;
	position[4].X=centren.X+2;
	for(int i=0; i<=4; i++)
		position[i].Y=centren.Y;
	for(int i=6; i<=8; i++)
		position[i].Y=centren.Y+1;
	position[5].Y=centren.Y-1;
	position[9].Y=centren.Y-2;
}
void Game::drawPlane()
{
	for(int i=0; i<9; i++)
	{
		SetPos(position[i]);
		if(i!=5)
			cout<<"O";
		else if(i==5)
			cout<<"|";
	}
}
void Game::drawPlaneToNull()
{
	for(int i=0; i<9; i++)
	{
		SetPos(position[i]);
		cout<<" ";
	}
}
void Game::initBullet()
{
	for(int i=0; i<10; i++)
		bullet[i].Y = 30;
}
void Game::drawBullet()
{
	for(int i=0; i<10; i++)
	{
		if( bullet[i].Y != 30)
		{
			SetPos(bullet[i]);
			cout<<"^";
		}
	}
}
void Game::drawBulletToNull()
{
	for(int i=0; i<10; i++)
		if( bullet[i].Y != 30 )
			{
				COORD pos={bullet[i].X, bullet[i].Y+1};
				SetPos(pos);
				cout<<" ";
			}
}
void Game::initEnemy()
{
	COORD a={1, 1};
	COORD b={45, 15};
	for(int i=0; i<8; i++)
	{
		enemy[i].position[0] = random(a, b);
		enemy[i].position[1].X = enemy[i].position[0].X + 3;
		enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
	}
}
void Game::drawEnemy()
{
	for(int i=0; i<8; i++)
		drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');
}
void Game::drawEnemyToNull()
{
	for(int i=0; i<8; i++)
	{
		drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');
	}
}
void Game::Pause()
{
	SetPos(61,2);
	cout<<"               ";
	SetPos(61,2);
	cout<<"��ͣ��...";
	char c=_getch();
	while(c!='p')
		c=_getch();
	SetPos(61,2);
	cout<<"         ";
}
void Game::planeMove(char x)
{
	if(x == 'a')
		if(position[1].X != 1)
			for(int i=0; i<=9; i++)
				position[i].X -= 2;

	if(x == 's')
		if(position[7].Y != 23)
			for(int i=0; i<=9; i++)
				position[i].Y += 1;

	if(x == 'd')
		if(position[4].X != 47)
			for(int i=0; i<=9; i++)
				position[i].X += 2;

	if(x == 'w')
		if(position[5].Y != 3)
			for(int i=0; i<=9; i++)
				position[i].Y -= 1;
}
void Game::bulletMove()
{
	for(int i=0; i<10; i++)
	{
		if( bullet[i].Y != 30)
		{
			bullet[i].Y -= 1;
			if( bullet[i].Y == 1 )
			{
				COORD pos={bullet[i].X, bullet[i].Y+1};
				drawThisBulletToNull( pos );
				bullet[i].Y=30;
			}

		}
	}
}
void Game::enemyMove()
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<2; j++)
			enemy[i].position[j].Y++;

		if(24 == enemy[i].position[1].Y)
		{
			COORD a={1, 1};
			COORD b={45, 3};
			enemy[i].position[0] = random(a, b);
			enemy[i].position[1].X = enemy[i].position[0].X + 3;
			enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
		}
	}
}
void Game::judgePlane()
{
	for(int i = 0; i < 8; i++)
		for(int j=0; j<9; j++)
			if(judgeCoordInFrame(enemy[i], position[j]))
			{
				SetPos(62, 1);
				cout<<"׹��";
				drawFrame(enemy[i], '+', '+');
				Sleep(1000);
				GameOver();
				break;
			}
}
void Game::drawThisBulletToNull( COORD c)
{
	SetPos(c);
	cout<<" ";
}
void Game::drawThisEnemyToNull( Frame f )
{
	drawFrame(f, ' ', ' ');
}
void Game::judgeEnemy()
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 10; j++)
			if( judgeCoordInFrame(enemy[i], bullet[j]) )
			{
				score += 5;
				drawThisEnemyToNull( enemy[i] );
				COORD a={1, 1};
				COORD b={45, 3};
				enemy[i].position[0] = random(a, b);
				enemy[i].position[1].X = enemy[i].position[0].X + 3;
				enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
				drawThisBulletToNull( bullet[j] );
				bullet[j].Y = 30;
			}
}
void Game::Shoot()
{
	for(int i=0; i<10; i++)
		if(bullet[i].Y == 30)
		{
			bullet[i].X = position[5].X;
			bullet[i].Y = position[5].Y-1;
			break;
		}
}
void Game::printScore()
{
	if(score == 120 && flag_rank == 0)
	{
		rank -= 3;
		flag_rank = 1;
	}

	else if( score == 360 && flag_rank == 1)
	{
		rank -= 5;
		flag_rank = 2;
	}
	else if( score == 480 && flag_rank == 2)
	{
		rank -= 5;
		flag_rank = 3;
	}
	int x=rank/5;
	SetPos(60, 6);
	cout<<score;

	if( rank!=rankf )
	{
		SetPos(60, 7);
		if( x == 5)
			title="��������Ա";
		else if( x == 4)
			title="�м�����Ա";
		else if( x == 3)
			title="�߼�����Ա";
		else if( x == 2 )
			title="���Ʒ���Ա";
		cout<<title;
	}
	rankf = rank;
}
void Game::Playing()
{
	drawEnemy();
	drawPlane();
	int flag_bullet = 0;
	int flag_enemy = 0;
	while(1)
	{
		Sleep(8);
		if(_kbhit())
		{
			char x = _getch();
			if ('a' == x || 's' == x || 'd' == x || 'w' == x)
			{
				drawPlaneToNull();
				planeMove(x);
				drawPlane();
				judgePlane();
			}
			else if ('p' == x)
				Pause();
			else if( 'k' == x)
				Shoot();
			else if( 'e' == x)
			{
				GameOver();
				break;
			}
		}
		if( 0 == flag_bullet )
		{
			bulletMove();
			drawBulletToNull();
			drawBullet();
			judgeEnemy();
		}
		flag_bullet++;
		if( 5 == flag_bullet )
			flag_bullet = 0;
		if( 0 == flag_enemy )
		{
			drawEnemyToNull();
			enemyMove();
			drawEnemy();
			judgePlane();
		}
		flag_enemy++;
		if( flag_enemy >= rank )
			flag_enemy = 0;
		printScore();
	}
}
void Game::GameOver()
{
	system("cls");
	COORD p1={28,9};
	COORD p2={53,15};
	drawFrame(p1, p2, '=', '|');
	SetPos(36,12);
	string str="Game Over!";
	for(int i=0; i<str.size(); i++)
	{
		Sleep(80);
		cout<<str[i];
	}
	Sleep(1000);
	system("cls");
	drawFrame(p1, p2, '=', '|');
	SetPos(31, 11);
	cout<<"����л���"<<score/5<<" ��";
	SetPos(31, 12);
	cout<<"�á����֣�"<<score;
	SetPos(31, 13);
	cout<<"��óƺţ�"<<title;
	SetPos(30, 16);
	Sleep(1000);
	cout<<"������ �ǣ�y��| ��n��"<<"\n";
	char x=_getch();
	if (x=='n')
	{
		system("cls");
		cout<<"goodbye\n";
		exit(0);
	}		
	else if (x == 'y')
	{
		system("cls");
		Game game;
		int a = drawMenu();
		if(a == 2)	game.rank = 20;
		system("cls");
		drawPlaying();
		game.Playing();
	}
}
void dafeiji()
{
	srand((int)time(0));
	HideCursor();
	Game game;
	int a = drawMenu();
	if(a == 2)  game.rank = 20;
	system("cls");
	drawPlaying();
	game.Playing();
}
void mainmain()
{
    system("mode con cols=120 lines=35");
    srand((unsigned)time(NULL));
    int mode;
    printf("1.����\n2.�м�\n3.�߼�\n4.�Զ���\n");
    scanf("%d",&mode);if(mode>4) mode=4;
    if(mode==1) G=9,K=9,Lnum=10;
    else if(mode==2) G=16,K=16,Lnum=40;
    else if(mode==3) G=16,K=30,Lnum=99;
    else
    {
        printf("�����������߶ȣ�");scanf("%d",&G);
        printf("������������ȣ�");scanf("%d",&K);
        printf("�������׸��������鲻�����ܴ�С������֮һ����");scanf("%d",&Lnum);
        if(G>24) G=24;if(K>30) K=30;
        if(G<9) G=9;if(K<9) K=9;
        if(Lnum<10) Lnum=10;if(Lnum>G*K*9/10) Lnum=G*K*9/10;
    }
    make();
    print();
    while(1)
    {
        begin();
        bool f1=is_win(),f2=is_lose();
        if(f1||f2)
        {
            gto(0,0);
            if(f1)
                color(202),gto(0,0),printf("�� Ӯ �ˣ����Ƿ�������(y/n)");
            if(f2)
                color(137),gto(0,0),printf("�� �� �ˣ����Ƿ�������(y/n)");
            print_real_map();
            char c=getch();
            if(c=='y'||c=='Y') again();
            else
            {
		        system("cls");
		        cout<<"goodbye\n";
				exit(0);
            }
        }
    }
}
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;
 
void locate(int x,int y)
{
    coord.X=y;
    coord.Y=x;
    SetConsoleCursorPosition(hout,coord);
};
void hide()
{
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(hout, &cursor_info);
}
double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

int m,n;
struct node
{
    int x,y;
}snake[1000];
 
int snake_length,dir;
node food;
int direct[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void print_wall()
{
    cout << " ";
    for (int i=1;i<=n;i++)
        cout << "-";
    cout << endl;
    for (int j=0;j<=m-1;j++)
    {
        cout << "|";
        for (int i=1;i<=n;i++) cout << " ";
        cout << "|" << endl;
    }
    cout << " ";
    for (int i=1;i<=n;i++)
        cout << "-";
}
void print_snake()
{
    locate(snake[0].x,snake[0].y);
    cout << "@";
    for (int i=1;i<=snake_length-1;i++)
    {
        locate(snake[i].x,snake[i].y);
        cout << "*";
    }
}
bool is_correct()
{
    if (snake[0].x==0 || snake[0].y==0 || snake[0].x==m+1 || snake[0].y==n+1) return false;
    for (int i=1;i<=snake_length-1;i++)
    {
        if (snake[0].x==snake[i].x && snake[0].y==snake[i].y) return false;
    }
    return true;
}
bool print_food()
{
    srand((unsigned)time(0));
    bool e;
    while (1)
    {
        e=true;
        int i=(int) random(0,m)+1,j=(int) random(0,n)+1;
        food.x=i;food.y=j;
        for (int k=0;k<=snake_length-1;k++)
        {
            if (snake[k].x==food.x && snake[k].y==food.y)
            {
                e=false;break;
            }
        }
        if (e) break;
    }
    locate(food.x,food.y);
    cout << "$";
    return true;
}
bool go_ahead()
{
    node temp;
    bool e=false;
    temp=snake[snake_length-1];
    for (int i=snake_length-1;i>=1;i--)
        snake[i]=snake[i-1];
    snake[0].x+=direct[dir][0];
    snake[0].y+=direct[dir][1];
    locate(snake[1].x,snake[1].y);
    cout << "*";
    if (snake[0].x==food.x && snake[0].y==food.y)
    {
        snake_length++;
        e=true;
        snake[snake_length-1]=temp;
    }
    if (!e)
    {
        locate(temp.x,temp.y);
        cout << " ";
    }
    else
        print_food();
    locate(snake[0].x,snake[0].y);
    cout << "@";
    if (!is_correct())
    {
        system("cls");
        cout << "You lose!" << endl << "Length: " << snake_length << endl;
        return false;
    }
    return true;
}
void tanchishe()
{
	cout << "--------------------̰����---------------------" << endl;
    cout << "��ע�ⴰ�ڴ�С,���ⷢ����λ.���齫���ڵ�Ϊ���." << endl;
    cout << "��ѡ���Ѷ�.����1-10������1����,1���,10������" << endl;
    cout << "Ȼ�������Ϸ����,�Է�������Ʒ���.ף����Ϸ���!" << endl;
    cout << "-----------------------------------------------" << endl;
    m=25;
    n=40; 
    if (m<10 || n<10 || m>25 || n>40)
    {
        cout << "ERROR" << endl;
        system("pause");
        return ;
    }
    int hard;
    cin >> hard;
    if (hard<=0 || hard>100)
    {
        cout << "ERROR" << endl;
        system("pause");
        return ;
    }
    snake_length=5;
    clock_t a,b;
    char ch;
    double hard_len;
    for (int i=0;i<=4;i++)
    {
        snake[i].x=1;
        snake[i].y=5-i;
    }
    dir=3;
    system("cls");
    hide();
    print_wall();
    print_food();
    print_snake();
    locate(m+2,0);
    cout << "Now length: ";
    while (1)
    {
        hard_len=(double)snake_length/(double) (m*n);
        a=clock();
        while (1)
        {
            b=clock();
            if (b-a>=(int)(400-30*hard)*(1-sqrt(hard_len))) break;
        }
        if (kbhit())
        {
            ch=getch();
            if (ch==-32)
            {
                ch=getch();
                switch(ch)
                {
                case 72:
                    if (dir==2 || dir==3)
                        dir=0;
                    break;
                case 80:
                    if (dir==2 || dir==3)
                        dir=1;
                    break;
                case 75:
                    if (dir==0 || dir==1)
                        dir=2;
                    break;
                case 77:
                    if (dir==0 || dir==1)
                        dir=3;
                    break;
                }
            }
        }
        if (!go_ahead()) break;
        locate(m+2,12);
        cout << snake_length;
    }
} 
struct Player { //��ҽṹ�壬����ʼ��player
	char name[21];
	int attack;
	int defense;
	int health;
	long int max_health;
	int level;
	int exp;
	int range_exp;
	long int max_exp;
} player= {"����",50,40,100,100,1,0,0,100};
struct Enemy { //�ֵĽṹ��,����ʼ�����ֹ�
	char name[20];
	char wupin[12];
	int attack;
	int defense;
	int health;
	int money;
	long int exp;
	int wupin_sign;
	int wupinpro;
	int double_attack;
	int miss;
} strongman= {"ɭ�־���","�ƽ�ʥ��",40,50,350,200,100,1,2,1,0},
  witch= {"ɭ��Ů��","����",25,15,100,50,50,2,2,1,1},
  xiyi= {"ɭ������","����",18,10,50,30,35,3,3,2,2},
  big_strongman= {"ɭ�־�����","���˾�ʯ",40*5,50*5,200*5,200*5,100*5,4,4,2,0},
  lion= {"��ԭ��ʨ","�����ý�",60,30,280,200,100,5,2,1,0},
  horse= {"��ԭҰ��","��Ѫ��",28,12,90,50,50,6,2,1,1},
  bee= {"��ԭ�Ʒ�","����",17,11,60,30,35,7,3,2,2},
  shitu= {"ʹͽ","\0",60*8,30*8,280*8,200*8,100*8,9,1,1,0},
  guai= {"\0","\0",0,0,0,0,0,0,0,0,0};
struct Place {
	int bar,hotel,forest1,forest2,forest3,grass1,grass2,grass3;
} place= {1,2,3,4,5,6,7,8};

int max_exp=0;
int choose_number=0,s=0,strongman_arm=0,battle=0,money=500,place_sign=9;
int cao=3,jijiubao=2,baiyao=2,superbaiyao=1,boom=3,dubiao=2,atom_boom=1;
int fang=0,fang1=10,fang1n=0,fang2=20,fang2n=0,fang3=40,fang3n=0,fang4=100,fang4n=0;
int gong=0,gong1=8,gong1n=0,gong2=15,gong2n=0,gong3=25,gong3n=0,gong4=60,gong4n=0;
int jingyancao=0,jingyanbao=0,jingyanshi=0;
char gongname[20]="��",fangname[20]="��";
char proof;

void AddWupin(int);
int AttackResult();
void BattleAct();
void ChooseWupin();
void DisplayState();
void OrdinaryAct();
int SuiJi();
int SuiJi100();
void WhetherLevelUp();
void SlowDisplay(char *);

int SuiJi()
{
	srand((unsigned)time(NULL));
	return rand()%10;
}

int SuiJi100()
{
	srand((unsigned)time(NULL));
	return rand()%100;
}

void ChooseWupin()
{
	printf("��Ʒ: 1,ֹѪ��%d�� 2,���Ȱ�%d�� 3,���ϰ�ҩ%d�� 4,�������ϰ�ҩ%d�� 5,����%d�� 6,����%d�� 7,����ʽԭ�ӵ�%d�� 8,�����%d�� 9,�����%d�� 10,����ʯ%d�� 11,���˾�ʯ%d�� 0,����\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom,jingyancao,jingyanbao,jingyanshi,strongman_arm);
	switch(scanf("%d",&choose_number),choose_number) {
		case 1:
			if(cao>0) {
				printf("ʹ��ֹѪ��,HP����60\n\n\n");
				cao--;
				if(player.health+60>player.max_health)player.health=player.max_health;
				else player.health+=60;
			} else printf("û��ֹѪ����\n\n\n");
			break;
		case 2:
			if(jijiubao>0) {
				printf("ʹ�ü��Ȱ�,HP����80\n\n\n");
				jijiubao--;
				if(player.health+80>player.max_health)player.health=player.max_health;
				else player.health+=80;
			} else printf("û�м��Ȱ���\n\n\n");
			break;
		case 3:
			if(baiyao>0) {
				printf("ʹ�����ϰ�ҩ,HP����120\nz\n\n");
				baiyao--;
				if(player.health+120>player.max_health)player.health=player.max_health;
				else player.health+=120;
			} else printf("û�����ϰ�ҩ��\n\n\n");
			break;
		case 4:
			if(superbaiyao>0) {
				printf("ʹ�ó������ϰ�ҩ,HP����200\n\n\n");
				superbaiyao--;
				if(player.health+200>player.max_health)player.health=player.max_health;
				else player.health+=200;
			} else printf("û�г������ϰ�ҩ��\n\n\n");
			break;
		case 5:
			if(battle) { 
				if(boom>0) {
					printf("ʹ������,����HP����100\n\n\n");
					boom--;
					guai.health-=100;
					AttackResult();
				}
			} else printf("��ս��״̬,����ʹ������!\n\n\n");
			break;
		case 6:
			if(battle) { 
				if(dubiao>0) {
					printf("ʹ�ö���,����HP����200\n\n\n");
					dubiao--;
					guai.health-=200;
					AttackResult();
				}
			} else printf("��ս��״̬,����ʹ�ö���!\n\n\n");
			break;
		case 7:
			if(battle) { 
				if(atom_boom>0) {
					printf("ʹ������ʽԭ�ӵ�,����HP����666666666\n\n\n");
					atom_boom--;
					guai.health-=666666666;
					AttackResult();
				}
			} else printf("��ս��״̬,����ʹ������ʽԭ�ӵ�!\n\n\n");
			break;
		case 8:
			if(jingyancao>0 && player.level<1000) {

				printf("ʹ�þ����,�ȼ�����10��\n\n\n");
				jingyancao--;
				player.level+=10;
				printf("�ȼ���%d\n",player.level);
			} else    if(jingyancao<1) {
				printf("û�о������\n\n\n");
			} else printf("�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n");
			break;
		case 9:
			if(jingyanbao>0 && player.level<1000) {
				if(player.level>44&&player.level<1000) {
					int sheng;
					sheng=45-player.level;
					player.level+=sheng;
					printf("ʹ�þ����,�ȼ�����%d��",sheng);
					printf("�ȼ���%d\n",player.level);
				} else {

					printf("ʹ�þ����,�ȼ�����2��\n\n\n");
					jingyanbao--;
					player.level+=2;
					printf("�ȼ���%d\n",player.level);
				}
			} else if(jingyanbao<1) {
				printf("û�о������");
			} else printf("�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n");
			break;
		case 10:
			if(jingyanshi>0 && player.level<1000) {
				if(player.level>42&&player.level<1000) {
					int sheng;
					sheng=45-player.level;
					player.level+=sheng;
					printf("ʹ�þ���ʯ,�ȼ�����%d��\n",sheng);
					printf("�ȼ���%d\n",player.level);
				} else {
					printf("ʹ�þ���ʯ,�ȼ�����10��\n");
					jingyanshi--;
					player.level+=10;
				}
			} else if(jingyanshi<1) {
				printf("û�о���ʯ��\n\n\n");
			} else printf("�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n");
			break;
		case 11:
			if(strongman_arm>0 && player.level<10000) {
				if(player.level>29&&player.level<10000) {
					int sheng;
					sheng=45-player.level;
					player.level+=sheng;
					printf("ʹ�þ��˾�ʯ,�ȼ�����%d��",sheng);
					printf("�ȼ���%d\n",player.level);
				} else {
					printf("ʹ�þ��˾�ʯ,�ȼ�����16��\n\n\n");
					strongman_arm--;
					player.level+=16;
					printf("�ȼ���%d\n",player.level);
				}
			} else if(strongman_arm<1) {
				printf("û�о��˾�ʯ�ˡ�\n\n\n");
			} else printf("�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n");
			break;
		case 0:
			break;
		default:
			printf("ChooseWupin error!\n\n\n");
	}
}

int AttackResult() 
{
	if(guai.health<=0) {
		battle=0;
		printf("ս��ʤ��!��ý��%d,����%d\n\n\n",guai.money,guai.exp);
		player.exp+=guai.exp;
		player.range_exp+=guai.exp;
		money+=guai.money;
		s=SuiJi();
		if(s<guai.wupinpro) {
			printf("�ӵ���ʬ���з���");
			printf("%s\n\n\n",guai.wupin);
			AddWupin(guai.wupin_sign);
		}
		WhetherLevelUp();
		if(strcmp(guai.name,"ʹͽ")==0) {
			printf("ս��ʤ�����ȳ�����������");
			getchar();
			getchar();
			exit(0);
		}
		return 1;
	} else {
		int s=SuiJi();

		if((guai.attack+s-player.defense/3)<0) {
			player.health-=1;
			printf("%s����,���HP������ 1\n\n",guai.name);
		} else {
			player.health-=guai.attack+s-player.defense/3;
			printf("%s����,���HP������%d\n\n",guai.name,guai.attack+s-player.defense/3);
		}
		if(player.health<0) {
			battle=0;
			printf("%sս��!��ҵ���%d\n\n\n",player.name,player.level*500);
			money-=player.level*500;
			player.health=player.max_health/5;
			OrdinaryAct();
			return 1;
		}
	}
	return 0;
}
void AddWupin(int wupin_sign)
{

	switch(wupin_sign) {
		case 1:
			fang4n++;
			break;
		case 2:
			fang3n++;
			break;
		case 3:
			fang2n++;
			break;
		case 4:
			strongman_arm=1;
			break;
		case 5:
			gong4n++;
			break;
		case 6:
			gong3n++;
			break;
		case 7:
			gong2n++;
			break;
		default:
			printf("AddWupin error\n\n\n");
	}

}
void WhetherLevelUp()
{
	int i=0,j=0;
	int l1=player.range_exp/100;
	int l2=player.range_exp/300;
	int l3=player.range_exp/600;
	if(player.level<=15&&l1>0) { 
		if(l1==1) {
			printf("%s",player.name);
			printf(" ����!\n\n\n������+3, ������+2, HP����+20\n\n\n");
			player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
			player.attack+=3;
			player.defense+=2;
			player.max_health+=20;
			player.health=player.max_health;
			player.level++;
			player.range_exp=0;
			player.exp=player.max_exp;
			player.max_exp+=100;
		} else {
			printf("������!����%d��!",l1);
			printf("������+%d, ������+%d, HP����+%d\n\n\n",3*l1,2*l1,20*l1);
			player.exp=(player.exp+guai.exp) || player.exp-((player.exp+guai.exp) || player.exp)%100;
			player.attack+=3*l1;
			player.defense+=2*l1;
			player.max_health+=20*l1;
			player.health=player.max_health;
			player.level+=l1;
			player.range_exp=0;
			player.exp=player.max_exp;
			player.max_exp+=100*l1;
		}
	} else if(player.level<=40&&l2>0) {
		if(l2==1) {
			printf("%s",player.name);
			printf(" ����!\n\n\n������+3, ������+2, HP����+20\n\n\n");
			player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
			player.attack+=3;
			player.defense+=2;
			player.max_health+=20;
			player.health=player.max_health;
			player.level++;
			player.range_exp=0;
			player.exp=player.max_exp;
			player.max_exp+=300;
		} else {
			printf("������!����%d��!",l1);
			printf("������+%d, ������+%d, HP����+%d\n\n\n",3*l2,2*l2,20*l2);
			player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
			player.attack+=3*l2;
			player.defense+=2*l2;
			player.max_health+=20*l2;
			player.health=player.max_health;
			player.level+=l2;
			player.range_exp=0;
			player.exp=player.max_exp;
			player.max_exp+=300*l2;
		}
	} else if(l3>0) {
		if(l3==1) {
			printf("%s",player.name);
			printf(" ����!\n\n\n������+3, ������+2, HP����+20\n\n\n");
			player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
			player.attack+=3;
			player.defense+=2;
			player.max_health+=20;
			player.health=player.max_health;
			player.level++;
			player.range_exp=0;
			player.exp=player.max_exp;
			player.max_exp+=600;
		} else {
			printf("������!����%d��!",l1);
			printf("������+%d, ������+%d, HP����+%d\n\n\n",3*l3,2*l3,20*l3);
			player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
			player.attack+=3*l3;
			player.defense+=2*l3;
			player.max_health+=20*l3;
			player.health=player.max_health;
			player.level+=l3;
			player.range_exp=0;
			player.exp=player.max_exp;
			player.max_exp+=600*l3;
		}
	}
}
void OrdinaryAct() 
{

	while(1) {
		cout<<"=============================================================================\n";
		printf("Ҫ��ʲô?\n\n\n 1,�ƶ� 2,���� 3,�Ի� 4,�鿴״̬ 5,װ�� 6,������Ϸ 0,�˳���Ϸ\n\n\n");
		puts("=============================================================================");
		switch(scanf("%d",&choose_number),choose_number) {
			case 1: //��ʾ�ƶ��˵�
				printf("Ҫȥ����?\n\n\n");
				printf("1,happy�ư� 2,ŵ�Ƿ��۾Ƶ� 3,�����̻� 4������������ 5��ð�ջ�Ұ\n\n\n");
				switch(scanf("%d",&choose_number),choose_number) {
					case 1:
						place_sign=place.bar; //��¼Ŀǰλ��-�ư�
// OrdinaryAct();
						break;
					case 2:
						place_sign=place.hotel; //�����õ�
						printf("��ң�%d",money);
						printf("Ҫ������? 200����� 1,�� 0,��\n\n\n");
						choose_number=1;
						switch(scanf("%d",&choose_number),choose_number) {
							case 1:
								if(money-200<0) { //�ж�Ǯ�Ƿ�
									printf("Sorry,���Ǯ����~\n\n\n");
									printf("��ң�%d",money);
								} else {
									printf("�ú���Ϣ\nHP��\n�ڶ�����\n\n");
									printf("��ң�%d\n",money);
									money-=200; //����200ס���
									player.health=player.max_health; //������
								}
								break;
							case 0:
								printf("�´�����!\n\n\n");
								break;
							default:
								printf("hotel talk error!\n\n\n");
						}
						place_sign=0;
						break;
					case 3:
						int yongju,gong,fang;
						printf("������Ҫ����ʲô���͵���Ʒ��\n\n\n 1,����װ�� 2������װ�� 3,һ�����˺�����\n\n\n");
						scanf("%d",&yongju);
						switch(yongju) {
							case 1:
								printf("������Ҫ����ʲô����?\n\n\n 1,ذ�ף�300 2��������500 3����Ѫ����1000\n\n\n");
								scanf("%d",&gong);
								switch(gong) {
									case 1:
										if(money>=300) {
											gong1n++;
											money=money-300;
											printf ("ذ��+1\n");
											printf("ذ��:%d��\n",gong1n);
											printf("��ң�%d\n",money);
											break;
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d\n",money);
											break;
										}
									case 2:
										if(money>=500) {
											gong2n++;
											money=money-500;
											printf ("����+1\n");
											printf("����:%d��\n",gong2n);
											printf("��ң�%d\n",money);
											break;
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d\n",money);
											break;
										}
									case 3:
										if(money>=1000) {
											gong3n++;
											money=money-1000;
											printf ("��Ѫ��+1\n");
											printf("��Ѫ��:%d��\n",gong3n);
											printf("��ң�%d\n",money);
											break;
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d\n",money);
											break;
										}
									default:
										printf("�Բ�������ֻ���������������");
										break;

								}
								break;
							case 2:
								int fang;
								printf("������Ҫ����ʲô����?\n\n\n 1,���£�300 2�����ף�500 3�����ף�1000\n\n\n");
								scanf("%d",&fang);
								switch(fang) {
									case 1:
										if(money>=300) {
											fang1n++;
											money=money-300;
											printf ("����+1\n");
											printf("����:%d��\n",fang1n);
											printf("��ң�%d\n",money);
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d\n",money);
										}

										break;
									case 2:
										if(money>=500) {
											fang2n++;
											money=money-500;
											printf ("����+1\n");
											printf("����:%d��\n",fang2n);
											printf("��ң�%d\n",money);
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d",money);
										}
										break;
									case 3:
										if(money>=1000) {
											fang3n++;
											money=money-1000;
											printf ("����+1\n");
											printf("����:%d��\n",fang3n);
											printf("��ң�%d\n",money);
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d\n",money);
										}
									default:
										printf("�Բ�������ֻ��������Ϸ��ߡ�");
										break;

								}
								printf("��ң�%d\n",money);
								break;
							case 3:
								printf("������Ҫ����ʲôһ�����˺�������\n 1,���� 2������ 3������ʽԭ�ӵ�\n\n\n");
								int yi;
								scanf("%d",&yi);
								switch(yi) {
									case 1:
										if(money>=300 && boom<5) {
											boom++;
											money=money-300;
											printf("����+1\n");
											printf("���ף�%d\n",boom);
											printf("��ң�%d\n",money);
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d",money);
										}
										break;
									case 2:
										if(money>=600 && dubiao<4) {
											dubiao++;
											money=money-600;
											printf("����+1\n");
											printf("���ڣ�%d\n",dubiao);
											printf("��ң�%d\n",money);
										} else {
											printf("Ǯ����!\n");
											printf("��ң�%d\n",money);
										}
										break;
									case 3:
										if(money>=0 && atom_boom<23333333333) {
											atom_boom=atom_boom+233;
											money=money+1500;
											printf("����ʽԭ�ӵ�+2\n");
											printf("����ʽԭ�ӵ���%d\n",atom_boom);
											printf("��ң�%d\n",money);
										} else {
											printf("Ǯ����!\n\n\n");
											printf("��ң�%d\n",money);
										}

										break;
								}
						}
						break;
					case 4:
						printf ("��ӭ�����ٱ������У�������Ҫ��ʲô������\n\n");
						printf("����װ��: 1,ذ��:%d�� 2,����:%d�� 3,��Ѫ��:%d�� 4,�����ý�:%d��\n",gong1n,gong2n,gong3n,gong4n);
						printf("����װ��: 5,����:%d�� 6,����:%d�� 7,����:%d�� 8,�ƽ�ʥ��:%d��\n9�����˾�ʯ:%d�� 0,����\n\n\n",fang1n,fang2n,fang3n,fang4n,strongman_arm);
						int pai,shu,i;
						scanf("%d",&pai);
						switch(pai) {
							case 1:
								printf("������Ҫ���ۼ�����");
								scanf("%d",&shu);
								if(gong1n>=shu) {
									gong1n=gong1n-shu;
									money=money+shu*240;
									printf("ذ�ף�%d\n",gong1n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
								break;
							case 2:
								printf("������Ҫ���ۼ�����\n");
								scanf("%d",&shu);
								if(gong2n>=shu) {
									gong2n=gong2n-shu;
									money=money+shu*400;
									printf("������%d\n",gong2n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
							case 3:
								printf("������Ҫ���ۼ�����\n");
								scanf("%d",&shu);
								if(gong3n>=shu) {
									gong3n=gong3n-shu;
									money=money+shu*800;
									printf("��Ѫ����%d\n",gong3n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
							case 4:
								printf("������Ҫ���ۼ�����\n");
								scanf("%d",&shu);
								if(gong4n>=shu) {
									gong4n=gong4n-shu;
									money=money+shu*1500;
									printf("�����ý���%d\n",gong4n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
							case 5:
								printf("������Ҫ���ۼ�����\n");
								scanf("%d",&shu);
								if(fang1n>=shu) {
									fang1n=fang1n-shu;
									money=money+shu*240;
									printf("���£�%d\n",fang1n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
							case 6:
								printf("������Ҫ���ۼ�����\n");
								scanf("%d",&shu);
								if(fang2n>=shu) {
									fang2n=fang2n-shu;
									money=money+shu*500;
									printf("���ף�%d\n",fang2n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
							case 7:
								printf("������Ҫ���ۼ�����\n");
								scanf("%d",&shu);
								if(fang3n>=shu) {
									fang3n=fang3n-shu;
									money=money+shu*800;
									printf("���ף�%d\n",fang3n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
								break;
							case 8:
								printf("������Ҫ���ۼ�����\n");
								scanf("%d",&shu);
								if(fang1n>=shu) {
									fang4n=fang4n-shu;
									money=money+shu*1500;
									printf("�ƽ�ʥ�£�%d\n",fang4n);
									printf("��ң�%d\n",money);
									break;
								} else {
									printf("װ�����������޷����ۣ�\n");
									break;
								}
							case 9:
								printf("������Ҫ���ۼ��ţ�");
								scanf("%d",&shu);
								if(strongman_arm>=shu) {
									strongman_arm=strongman_arm-shu;
									money=money+shu*2000;
									printf("���˾�ʯ��%d\n",strongman_arm);
									printf("��ң�%d\n",money);
								} else {
									printf("��ʯ���������޷����ۣ�\n");
									break;
								}
								break;
							case 0:
								break;
								break;
							default:
								printf("û�и�װ�����޷����ۣ�\n");
								break;
						}

						break;
					case 5:
						int yewai;
						while(1) {
							puts("=============================================================================");
							printf("Ҫȥ��ð���أ�");
							printf("\n\n 1,�������� Σ�ճ̶ȣ���\n\n 2,��ҫ��ԭ Σ�ճ̶ȣ���\n\n 3,����ɭ�� Σ�ճ̶ȣ�����\n\n 4,��Į�� Σ�ճ̶ȣ�����\n\n 5,�����׶� Σ�ճ̶ȣ������\n\n 6,���乬�� Σ�ճ̶ȣ�������\n\n 0,�뿪\n");
							puts("=============================================================================");
							scanf("%d",&yewai);
							switch(yewai) {
								case 1:
									place_sign=place.forest1;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=xiyi;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=witch;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("���ﰲȫ\n\n\n");
//���õ���OAct����,���Զ�ִ��OAct����;
									}
									break;
								case 3:
									place_sign=place.forest2;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=witch;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=strongman;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("���ﰲȫ\n\n\n");
									}
									break;
								case 5:
									place_sign=place.forest3;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=strongman;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=big_strongman;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("���ﰲȫ\n\n\n");
									}
									break;
								case 2:
									place_sign=place.grass1;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=bee;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=horse;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("���ﰲȫ\n\n\n");
									}
									break;
								case 4:
									place_sign=place.grass2;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=horse;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=lion;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("���ﰲȫ\n\n\n");
									}
									break;
								case 6:
									place_sign=place.grass3;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=lion;
										printf("%s���˹���!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										if(strongman_arm) {
											printf("��������:\n\n\n ����,������,���Ĳ���,����...�ٺ�,���ϵ���!���˾�ʯ��Ҫ��,������Ҳ�������!\n\n\n");
											guai=shitu;
											printf("%s���˹���!\n\n\n",guai.name);
											BattleAct();
										} else printf("��������:\n\n\n ������,��ð�.������о��˾�ʯ,�ҿ��Ը����㹫��������Ŷ~\n\n\n");
									} else {
										printf("���ﰲȫ\n\n\n");
									}
									break;
									if(yewai!=0) {
										printf("������Ϊδ֪�����޷����롣\n\n\n");
										break;
									}
							}
							if(yewai==0) {
								break;
								printf("���뿪��Ұ��");
							}
						}

				}
				break;

			case 2:
				ChooseWupin();
				break; //��ʾ����,������ʹ��.
			case 3: //�Ի�ѡ��
				if(place_sign==place.bar) {
					printf("Ҫ��˭˵��?\n\n\n1,�췢Ů�� 2,�ͽ����� 3,�ư��ϰ� 4,ҩƷ����\n\n\n"); //��ʾ�Ի�����
					switch(scanf("%d",&choose_number),choose_number) {
						case 1:
							printf("�췢Ů��:\n\n\n ��̨���Ǹ�Hunter��˧��!(~����~)\n\n\n��˵�������������,�����·��Ӧ�ú���Ϥ��!\n\n\n");
							break;
						case 2:
							if(fang1n<1&&gong1n<1) {
								printf("�ͽ�����:\n\n\n ��Ҫ�ȹ�����!�õ���!\n\n\n ���������������ն�,����Խ��ԽΣ��,����ذ�׺Ͳ���,�������Щ������,��ȥ��!\n\n\n");
								printf("%s����:��,��λ��������ð�!\n\n\n)",player.name);
								gong1n++;
								fang1n++;
							} else printf("�ͽ�����:\n\n\n ���Ͱ�,������!\n\n\n ��Ҫ�������������ŵ�!\n\n\n");
							break;
						case 3:
							printf("Ҫ�ȵ�ʲô?\n\n\n 1,����ͷ25��� HP+20 2,XO��80��� HP+50 3,��ͷ����150��� HP+100 0,����\n\n\n");
							choose_number=1;
							while(choose_number) {
								switch(scanf("%d",&choose_number),choose_number) {
									case 1:
										if(money<25) {
											printf("Ǯ����!");
										} else {
											if(player.health+20<=player.max_health) {
												printf("HP+20.");
												money-=25;
												player.health+=20;
											} else {
												printf("HP����");
												player.health=player.max_health;
											}
										}
										break;
									case 2:
										if(money<80) {
											printf("Ǯ����!");
										} else {
											if(player.health+50<=player.max_health) {
												printf("HP+50.");
												money-=80;
												player.health+=50;
											} else {
												printf("HP����");
												player.health=player.max_health;
											}
										}
										break;
									case 3:
										if(money<150) {
											printf("Ǯ����!");
										} else {
											if(player.health+100<=player.max_health) {
												printf("HP+100.");
												money-=150;
												player.health+=100;
											} else {
												printf("HP����");
												player.health=player.max_health;
											}
										}
										break;
									case 0:
										printf("�´�����!\n");
										break;
									default:
										printf("�������\n\n\n");
										break;
								}
								break;
							}
							break;
						case 4:
							printf("��Ҫ��ʲô��\n\n\n 1������ 2������ \n\n\n");
							int mai;
							scanf("%d",&mai);
							if(mai==1) {
								printf("���ʲô�أ�\n1,ֹѪ�ݣ�100 HP+60\n2�����Ȱ���150 HP+80 \n3�����ϰ�ҩ��250 HP+120\n4���������ϰ�ҩ��400 HP+200 \n5������ݣ�150 ����+300 \n6���������600 ����+600\n7������ʯ��500 ����+1000 \n0,�ݰ�\n");
								int dongxi;
								scanf("%d",&dongxi);
								switch(dongxi) {
									case 1:
										if(money>=100&&cao<6) {
											cao++;
											money=money-100;
											printf ("ֹѪ��+1\n");
										} else {
											printf("Ǯ����!\n");
										}
										break;
									case 2:
										if(money>=150&&jijiubao<5) {
											jijiubao++;
											money=money-150;
											printf ("���Ȱ�+1\n");
										} else {
											printf("Ǯ����!\n");
										}
										break;
									case 3:
										if(money>=250&&baiyao<4) {
											baiyao++;
											money=money-250;
											printf ("���ϰ�ҩ+1\n");
										} else {
											printf("Ǯ����!\n");
										}
										break;
									case 4:
										if(money>=400&&superbaiyao<3) {
											superbaiyao++;
											money=money-400;
											printf ("�������ϰ�ҩ+1\n");

										} else {
											printf("Ǯ����!\n");
										}
										break;
									case 5:
										if(money>=150) {
											jingyancao++;
											money=money-150;
											printf ("�����+1\n");
										} else {
											printf("Ǯ����!\n");
										}
										break;
									case 6:
										if(money>=300) {
											jingyanbao++;
											money=money-300;
											printf ("�����+1\n");
										} else {
											printf("Ǯ����!\n");
										}
										break;
									case 7:
										if(money>=500) {
											jingyanshi++;
											money=money+500;
											printf ("����ʯ+1\n");
										} else {
											printf("Ǯ����!\n");
										}
										break;
								}
							case 0:
								printf("��ң�%d\n",money);
								printf("�ټ�����ӭ�´�������\n");
								break;

							}
							if(mai==2) {
								printf("ҩƷ���ˣ�ȥȥȥ������ûʱ�������ġ�\n");
							}
					}
				} else if(place_sign==place.hotel)
					printf("���ϰ���!��...��\n\n\n����æ���أ�û������~��\n\n\n");
				else printf("�������û�˿�������\n\n\n");
				break;
			case 4:
				DisplayState();
				break; //��ʾ״̬
			case 5: //װ��
				printf("����װ��: 1,ذ��:%d�� 2,����:%d�� 3,��Ѫ��:%d�� 4,�����ý�:%d��\n\n\n",gong1n,gong2n,gong3n,gong4n);
				printf("����װ��: 5,����:%d�� 6,����:%d�� 7,����:%d�� 8,�ƽ�ʥ��:%d��\t\t0,����\n\n\n",fang1n,fang2n,fang3n,fang4n);
				printf("ѡ��Ҫװ�������������:\n\n\n");
				switch(scanf("%d",&choose_number),choose_number) {
					case 1:
						if(gong1n>=1) {
							printf("������ذ��\n\n\n");
							gong=gong1;
							strcpy(gongname,"ذ��");
						} else printf("��û��ذ�׿���װ��\n\n\n");
						break;
					case 2:
						if(gong2n>=1) {
							printf("�����˳���\n\n\n");
							gong=gong2;
							strcpy(gongname,"����");
						} else printf("��û�г�������װ��\n\n\n");
						break;
					case 3:
						if(gong3n>=1) {
							printf("�����˱�Ѫ��\n\n\n");
							gong=gong3;
							strcpy(gongname,"��Ѫ��");
						} else printf("��û�б�Ѫ������װ��\n\n\n");
						break;
					case 4:
						if(gong4n>=1) {
							printf("�����˾����ý�\n\n\n");
							gong=gong4;
							strcpy(gongname,"�����ý�");
						} else printf("��û�о����ý�����װ��\n\n\n");
						break;
					case 5:
						if(fang1n>=1) {
							printf("�����˲���\n\n\n");
							fang=fang1;
							strcpy(fangname,"����");
						} else printf("��û�в��¿���װ��\n\n\n");
						break;
					case 6:
						if(fang2>=1) {
							printf("����������\n\n\n");
							fang=fang2;
							strcpy(fangname,"����");
						} else printf("��û�����׿���װ��\n\n\n");
						break;
					case 7:
						if(fang3n>=1) {
							printf("����������\n\n\n");
							fang=fang3;
							strcpy(fangname,"����");
						} else printf("��û�����׿���װ��\n\n\n");
						break;
					case 8:
						if(fang4n>=1) {
							printf("�����˻ƽ�ʥ��\n\n\n");
							fang=fang4;
							strcpy(fangname,"�ƽ�ʥ��");
						} else printf("��û�лƽ�ʥ�¿���װ��\n\n\n");
						break;
					case 0:
						printf("δ����װ��\n\n\n");
						break;
					default:
						printf("change error!");
				}
				break;
			case 6:
				printf(" ���ã���ӭ���������硣Ϊ�˸������õ���Ϸ���飬���Ŷ�ʱ��ʱ���Ż�����Ϸ���Ż���ᾡ�췢�������ϡ�������ҷ��棬������ҵķ�ʽ���趨��������ʱ�����롰ʥս��ʿ ����������˫���ţ�������2.0�汾��buy��������2.0�Ļ����Ͻ����޸ģ����޸���buy�����������˾���ݵ������������ĵ��ߣ�ϣ�����ϲ����������Ҫ��л��İͬѧ��������������౦��Ľ��飬лл��\n");
				break;
			case 0:
				printf("ȷ���˳���Ϸ?(Y/N)\n\n\n");
				getchar();
				proof=getchar();
				if(proof=='y'||proof=='Y') {
					printf("���ݴ洢��...");
					getchar();
					printf("���س��˳�");
					getchar();
					return;
				} else if(proof=='n'||proof=='N')printf("������Ϸ!\n\n\n");
				else printf("����!\n\n\n");
				break;
			default:
				printf("�������!\n\n\n");
		}
	}
}
void DisplayState()
{
	printf("%s ������:%d+%d=%d ������:%d+%d=%d HP:%d/%d \n\n\n",player.name,player.attack,gong,player.attack+gong,player.defense,fang,player.defense+fang,player.health,player.max_health);
	printf("����: %s ����: %s \n\n\n",gongname,fangname);
	printf("�ȼ�:%d ����:%d/%d ����Ҫ%d�������� ���:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money);
}
void BattleAct()
{
	while(1) {
		puts("=============================================================================");
		printf("Ҫ��ô��?\n\n\n 1,���� 2,��Ʒ 3,�鿴״̬ 4,����\n\n\n");
		switch(scanf("%d",&choose_number),choose_number) {
			case 1:
				s=SuiJi();
				printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,player.attack+s+gong-guai.defense/3);
				guai.health-=player.attack+s+gong-guai.defense/3;
				if(AttackResult())return; //��������н��(���˻����ս��)�˳�����
				else continue;
			case 2:
				ChooseWupin();
				break; //ѡ����Ʒ,����ʹ��,ս��������ʹ�ù�������Ʒ
			case 3:
				DisplayState();
				break; //��ʾ״̬
			case 4:
				s=SuiJi();
				if(s<4) { //40%�ĸ��ʿ�������
					printf("%s������~\n\n\n",player.name);
					battle=0;
					return;
				} else printf("%s����ʧ��!\n\n\n",player.name);
				break;
			default:
				printf("�������,��������!\n\n\n");
		}
	}
}
void printf(char *p)
{
	while(1) 
	{
		if(*p!=0)
			printf("%c",*p++);
		else
			break;
		Sleep(100);
	}
}
void youxi4()
{

	int i=0,j=0,k=0;
	char player_name[21];
	Sleep(1000);
	printf("--------------------------��ӭ���� [�������] 2.2 ���԰�-----------------------\n\n\n");
	Sleep(1000);
	printf("�����ǲ������! ������˹�������繫����İ���˰����!\n\n\n ΰ������߰�~�������ǵ�����,Ӫ�ȹ���!\n\n\n�����������: (20���ַ�)\n\n\n");
	scanf("%s",player_name);
	strncpy(player.name,player_name,20);
	if(strcmp(player.name,"ʥս��ʿ")==0) 
	{
		printf("\n\n\n��ӡ�����ʥ��Ѫͳ��!�����ھ�����!\n\n\nʥս��ʿ�����Ϊ����ѡ֮�ˣ�����ȳ������ɣ�\n\n\n");
		player.attack=999;
		player.defense=999;
		player.health=9999;
		player.max_health=9999;
	}
	getchar();
	OrdinaryAct();
	return ;
}
int main()
{
	int x;
	cout<<"                ********\n";
	cout<<"               ************\n";
	cout<<"               ####....#.\n";
	cout<<"             #..###.....##....\n";
	cout<<"             ###.......######              ###            ###\n";
	cout<<"                ...........               #...#          #...#\n";
	cout<<"               ##*#######                 #.#.#          #.#.#\n";
	cout<<"            ####*******######             #.#.#          #.#.#\n";
	cout<<"           ...#***.****.*###....          #...#          #...#\n";
	cout<<"           ....**********##.....           ###            ###\n";
	cout<<"           ....****    *****....\n             ####        ####\n";
	cout<<"           ######        ######\n##############################################################\n";
	cout<<"#...#......#.##...#......#.##...#......#.##------------------#\n";
	cout<<"###########################################------------------#\n";
	cout<<"#..#....#....##..#....#....##..#....#....#####################\n";
	cout<<"##########################################    #----------#\n";
	cout<<"#.....#......##.....#......##.....#......#    #----------#\n";
	cout<<"##########################################    #----------#\n";
	cout<<"#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#\n";
	cout<<"##########################################    ############";
	while(1)
	{
		gto(22,0);
		cout<<"                   ��ӭ������Ϸ����                           �������Ŀͬ����Ϸ�������ڱ��������꽡������ֹ���\n"; 
		cout<<"       1��ɨ��                                            ÿ��ֻ��ѡ��һ����Ϸ����Ϊ����ǿ�����Ժ���ս�ԣ�ÿ����Ϸ\n";
		cout<<"       2���ɻ���ս                                        �в�ͬ���Ѷȵȼ����ҿ��Զ������\n";
		cout<<"       3��̰����\n";
		cout<<"       4���������\n"; 
		cout<<"                                        0���˳�\n";
		cin>>x;
		system("cls");
		if(x==0) break;
		if(x==2) dafeiji();
	    else if(x==1) mainmain();
	    else if(x==3) tanchishe(); 
	    else if(x==4) youxi4();
	}	
}

