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
	printf("扫雷");
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
	cout<<"-----规则-----";
    gto(3,2*K+5);
	cout<<"wasd：选择位置";
    gto(4,2*K+5);
	cout<<"空格：打开";
    gto(5,2*K+5);
	cout<<"1键：试探周围8个方块，如果其中有雷则不会打开，无";
    gto(6,2*K+5);
	cout<<"     雷或旗帜标对了则会将周围无雷的位置打开，";
    gto(7,2*K+5);
	cout<<"     如果试探时周围有标错的旗帜，则会游戏失败";
    gto(8,2*K+5);
	cout<<"     必须额外确认一次，以便查看周围被试探的区域";
    gto(9,2*K+5);
	cout<<"2键：放置/取消小旗（F）";
    gto(10,2*K+5);
	cout<<"3键：放置/取消标记（？）";
    gto(11,2*K+5);
	cout<<"4键：打开/关闭确认模式，即每次操作需再按一次确认";
    gto(12,2*K+5);
	cout<<"5键：打开/关闭作弊模式，即显示原本地图";
    gto(13,2*K+5);
	cout<<"0键：重新开始";
    gto(G+4,0);
	cout<<"-----操作提示-----\n";
    cout<<"请选择方块进行操作";
    gto(1,2*K+10);
	color(12);
	Wnum=Lnum;
	cout<<"剩余小旗数："<<Lnum;
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
	cout<<"请确认                                      ";
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
	cout<<"剩余小旗数：       ";
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
			cout<<"剩余小旗数：       ";
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
	cout<<"请选择方块进行操作";
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
				cout<<"请确认                                      ";
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
				cout<<"请确认                                      ";
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
				cout<<"请确认                                      ";
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
				cout<<"请确认                                      ";
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
				cout<<"请确认                                      ";
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
				cout<<"请确认                                      ";
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
				cout<<"请确认                                      ";
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
		cout<<"error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等";
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
		cout<<"error code 02：无法填充列，因为两个坐标的横坐标(y)不相等";
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
	cout<<"得分：";
	SetPos(52, 7);
	cout<<"称号：";
	SetPos(52,10);
	cout<<"操作方式：";
	SetPos(52,12);
	cout<<"  a,s,d,w 控制战机移动。";
	SetPos(52,14);
	cout<<"  p 暂停游戏。";
	SetPos(52,16);
	cout<<"  e 退出游戏。";
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
	cout<<"w 和 s 选择， k 确定";
	SetPos(15, 11);
	cout<<"1. 简单的敌人";
	SetPos(15, 13);
	cout<<"2. 冷酷的敌人";
	drawRow(20, 0, 79, '-');
	drawRow(22, 0, 79, '-');
	SetPos(47, 11);
	cout<<"简单的敌人：";
	SetPos(51, 13);
	cout<<"简单敌人有着较慢的移动速度。";
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
							cout<<"　";
							j = 11;
							SetPos(12, j);
							cout<<">>";
							SetPos(51, 13);
							cout<<"　　　　　　　　　　　　";
							SetPos(47, 11);
							cout<<"简单的敌人：";
							SetPos(51, 13);
							cout<<"简单敌人有较慢的移动速度，比较容易对付";
						}
						break;
					}
			case 's' :
					{
						if( j == 11 )
						{
							SetPos(12, j);
							cout<<"　";
							j = 13;
							SetPos(12, j);
							cout<<">>";
							SetPos(51, 13);
							cout<<"　　　　　　　　　　　　　　";
							SetPos(47, 11);
							cout<<"冷酷的敌人：";
							SetPos(51, 13);
							cout<<"冷酷的敌人移动速度较快，不是很好对付哟。";
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
	cout<<"暂停中...";
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
				cout<<"坠毁";
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
			title="初级飞行员";
		else if( x == 4)
			title="中级飞行员";
		else if( x == 3)
			title="高级飞行员";
		else if( x == 2 )
			title="王牌飞行员";
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
	cout<<"击落敌机："<<score/5<<" 架";
	SetPos(31, 12);
	cout<<"得　　分："<<score;
	SetPos(31, 13);
	cout<<"获得称号："<<title;
	SetPos(30, 16);
	Sleep(1000);
	cout<<"继续？ 是（y）| 否（n）"<<"\n";
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
    printf("1.初级\n2.中级\n3.高级\n4.自定义\n");
    scanf("%d",&mode);if(mode>4) mode=4;
    if(mode==1) G=9,K=9,Lnum=10;
    else if(mode==2) G=16,K=16,Lnum=40;
    else if(mode==3) G=16,K=30,Lnum=99;
    else
    {
        printf("请输入雷区高度：");scanf("%d",&G);
        printf("请输入雷区宽度：");scanf("%d",&K);
        printf("请输入雷个数（建议不超过总大小的三分之一）：");scanf("%d",&Lnum);
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
                color(202),gto(0,0),printf("你 赢 了！！是否重来？(y/n)");
            if(f2)
                color(137),gto(0,0),printf("你 输 了！！是否重来？(y/n)");
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
	cout << "--------------------贪吃蛇---------------------" << endl;
    cout << "请注意窗口大小,以免发生错位.建议将窗口调为最大." << endl;
    cout << "先选择难度.请在1-10中输入1个数,1最简单,10则最难" << endl;
    cout << "然后进入游戏画面,以方向键控制方向.祝你游戏愉快!" << endl;
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
struct Player { //玩家结构体，并初始化player
	char name[21];
	int attack;
	int defense;
	int health;
	long int max_health;
	int level;
	int exp;
	int range_exp;
	long int max_exp;
} player= {"勇者",50,40,100,100,1,0,0,100};
struct Enemy { //怪的结构体,并初始化各种怪
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
} strongman= {"森林巨人","黄金圣衣",40,50,350,200,100,1,2,1,0},
  witch= {"森林女巫","银甲",25,15,100,50,50,2,2,1,1},
  xiyi= {"森林蜥蜴","铁甲",18,10,50,30,35,3,3,2,2},
  big_strongman= {"森林巨人王","巨人晶石",40*5,50*5,200*5,200*5,100*5,4,4,2,0},
  lion= {"草原雄狮","绝世好剑",60,30,280,200,100,5,2,1,0},
  horse= {"草原野马","碧血剑",28,12,90,50,50,6,2,1,1},
  bee= {"草原黄蜂","长剑",17,11,60,30,35,7,3,2,2},
  shitu= {"使徒","\0",60*8,30*8,280*8,200*8,100*8,9,1,1,0},
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
char gongname[20]="无",fangname[20]="无";
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
	printf("物品: 1,止血草%d个 2,急救包%d个 3,云南白药%d个 4,超级云南白药%d个 5,手雷%d个 6,毒标%d个 7,手抛式原子弹%d个 8,经验草%d个 9,经验包%d个 10,经验石%d个 11,巨人晶石%d个 0,返回\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom,jingyancao,jingyanbao,jingyanshi,strongman_arm);
	switch(scanf("%d",&choose_number),choose_number) {
		case 1:
			if(cao>0) {
				printf("使用止血草,HP增加60\n\n\n");
				cao--;
				if(player.health+60>player.max_health)player.health=player.max_health;
				else player.health+=60;
			} else printf("没有止血草了\n\n\n");
			break;
		case 2:
			if(jijiubao>0) {
				printf("使用急救包,HP增加80\n\n\n");
				jijiubao--;
				if(player.health+80>player.max_health)player.health=player.max_health;
				else player.health+=80;
			} else printf("没有急救包了\n\n\n");
			break;
		case 3:
			if(baiyao>0) {
				printf("使用云南白药,HP增加120\nz\n\n");
				baiyao--;
				if(player.health+120>player.max_health)player.health=player.max_health;
				else player.health+=120;
			} else printf("没有云南白药了\n\n\n");
			break;
		case 4:
			if(superbaiyao>0) {
				printf("使用超级云南白药,HP增加200\n\n\n");
				superbaiyao--;
				if(player.health+200>player.max_health)player.health=player.max_health;
				else player.health+=200;
			} else printf("没有超级云南白药了\n\n\n");
			break;
		case 5:
			if(battle) { 
				if(boom>0) {
					printf("使用手雷,敌人HP减少100\n\n\n");
					boom--;
					guai.health-=100;
					AttackResult();
				}
			} else printf("非战斗状态,不能使用手雷!\n\n\n");
			break;
		case 6:
			if(battle) { 
				if(dubiao>0) {
					printf("使用毒标,敌人HP减少200\n\n\n");
					dubiao--;
					guai.health-=200;
					AttackResult();
				}
			} else printf("非战斗状态,不能使用毒标!\n\n\n");
			break;
		case 7:
			if(battle) { 
				if(atom_boom>0) {
					printf("使用手抛式原子弹,敌人HP减少666666666\n\n\n");
					atom_boom--;
					guai.health-=666666666;
					AttackResult();
				}
			} else printf("非战斗状态,不能使用手抛式原子弹!\n\n\n");
			break;
		case 8:
			if(jingyancao>0 && player.level<1000) {

				printf("使用经验草,等级增加10级\n\n\n");
				jingyancao--;
				player.level+=10;
				printf("等级：%d\n",player.level);
			} else    if(jingyancao<1) {
				printf("没有经验草了\n\n\n");
			} else printf("等级超过45级,修为太高，无法使用。\n\n\n");
			break;
		case 9:
			if(jingyanbao>0 && player.level<1000) {
				if(player.level>44&&player.level<1000) {
					int sheng;
					sheng=45-player.level;
					player.level+=sheng;
					printf("使用经验包,等级增加%d级",sheng);
					printf("等级：%d\n",player.level);
				} else {

					printf("使用经验包,等级增加2级\n\n\n");
					jingyanbao--;
					player.level+=2;
					printf("等级：%d\n",player.level);
				}
			} else if(jingyanbao<1) {
				printf("没有经验包了");
			} else printf("等级超过45级,修为太高，无法使用。\n\n\n");
			break;
		case 10:
			if(jingyanshi>0 && player.level<1000) {
				if(player.level>42&&player.level<1000) {
					int sheng;
					sheng=45-player.level;
					player.level+=sheng;
					printf("使用经验石,等级增加%d级\n",sheng);
					printf("等级：%d\n",player.level);
				} else {
					printf("使用经验石,等级增加10级\n");
					jingyanshi--;
					player.level+=10;
				}
			} else if(jingyanshi<1) {
				printf("没有经验石了\n\n\n");
			} else printf("等级超过45级,修为太高，无法使用。\n\n\n");
			break;
		case 11:
			if(strongman_arm>0 && player.level<10000) {
				if(player.level>29&&player.level<10000) {
					int sheng;
					sheng=45-player.level;
					player.level+=sheng;
					printf("使用巨人晶石,等级增加%d级",sheng);
					printf("等级：%d\n",player.level);
				} else {
					printf("使用巨人晶石,等级增加16级\n\n\n");
					strongman_arm--;
					player.level+=16;
					printf("等级：%d\n",player.level);
				}
			} else if(strongman_arm<1) {
				printf("没有巨人晶石了。\n\n\n");
			} else printf("等级超过45级,修为太高，无法使用。\n\n\n");
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
		printf("战斗胜利!获得金币%d,经验%d\n\n\n",guai.money,guai.exp);
		player.exp+=guai.exp;
		player.range_exp+=guai.exp;
		money+=guai.money;
		s=SuiJi();
		if(s<guai.wupinpro) {
			printf("从敌人尸骸中发现");
			printf("%s\n\n\n",guai.wupin);
			AddWupin(guai.wupin_sign);
		}
		WhetherLevelUp();
		if(strcmp(guai.name,"使徒")==0) {
			printf("战斗胜利，救出公主！！！");
			getchar();
			getchar();
			exit(0);
		}
		return 1;
	} else {
		int s=SuiJi();

		if((guai.attack+s-player.defense/3)<0) {
			player.health-=1;
			printf("%s反击,你的HP减少了 1\n\n",guai.name);
		} else {
			player.health-=guai.attack+s-player.defense/3;
			printf("%s反击,你的HP减少了%d\n\n",guai.name,guai.attack+s-player.defense/3);
		}
		if(player.health<0) {
			battle=0;
			printf("%s战死!金币掉落%d\n\n\n",player.name,player.level*500);
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
			printf(" 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20\n\n\n");
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
			printf("好厉害!连升%d级!",l1);
			printf("攻击力+%d, 防御力+%d, HP上限+%d\n\n\n",3*l1,2*l1,20*l1);
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
			printf(" 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20\n\n\n");
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
			printf("好厉害!连升%d级!",l1);
			printf("攻击力+%d, 防御力+%d, HP上限+%d\n\n\n",3*l2,2*l2,20*l2);
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
			printf(" 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20\n\n\n");
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
			printf("好厉害!连升%d级!",l1);
			printf("攻击力+%d, 防御力+%d, HP上限+%d\n\n\n",3*l3,2*l3,20*l3);
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
		printf("要做什么?\n\n\n 1,移动 2,道具 3,对话 4,查看状态 5,装备 6,关于游戏 0,退出游戏\n\n\n");
		puts("=============================================================================");
		switch(scanf("%d",&choose_number),choose_number) {
			case 1: //显示移动菜单
				printf("要去哪里?\n\n\n");
				printf("1,happy酒吧 2,诺亚方舟酒店 3,北朝商会 4，红玉拍卖行 5，冒险荒野\n\n\n");
				switch(scanf("%d",&choose_number),choose_number) {
					case 1:
						place_sign=place.bar; //记录目前位置-酒吧
// OrdinaryAct();
						break;
					case 2:
						place_sign=place.hotel; //进入旅店
						printf("金币：%d",money);
						printf("要开房吗? 200个金币 1,是 0,否\n\n\n");
						choose_number=1;
						switch(scanf("%d",&choose_number),choose_number) {
							case 1:
								if(money-200<0) { //判断钱是否够
									printf("Sorry,你的钱不够~\n\n\n");
									printf("金币：%d",money);
								} else {
									printf("好好休息\nHP满\n第二天了\n\n");
									printf("金币：%d\n",money);
									money-=200; //花费200住店费
									player.health=player.max_health; //体力满
								}
								break;
							case 0:
								printf("下次再来!\n\n\n");
								break;
							default:
								printf("hotel talk error!\n\n\n");
						}
						place_sign=0;
						break;
					case 3:
						int yongju,gong,fang;
						printf("请问您要购买什么类型的物品？\n\n\n 1,攻击装备 2，防御装备 3,一次性伤害武器\n\n\n");
						scanf("%d",&yongju);
						switch(yongju) {
							case 1:
								printf("请问您要购买什么武器?\n\n\n 1,匕首￥300 2，长剑￥500 3，碧血剑￥1000\n\n\n");
								scanf("%d",&gong);
								switch(gong) {
									case 1:
										if(money>=300) {
											gong1n++;
											money=money-300;
											printf ("匕首+1\n");
											printf("匕首:%d个\n",gong1n);
											printf("金币：%d\n",money);
											break;
										} else {
											printf("钱不够!\n");
											printf("金币：%d\n",money);
											break;
										}
									case 2:
										if(money>=500) {
											gong2n++;
											money=money-500;
											printf ("长剑+1\n");
											printf("长剑:%d个\n",gong2n);
											printf("金币：%d\n",money);
											break;
										} else {
											printf("钱不够!\n");
											printf("金币：%d\n",money);
											break;
										}
									case 3:
										if(money>=1000) {
											gong3n++;
											money=money-1000;
											printf ("碧血剑+1\n");
											printf("碧血剑:%d个\n",gong3n);
											printf("金币：%d\n",money);
											break;
										} else {
											printf("钱不够!\n");
											printf("金币：%d\n",money);
											break;
										}
									default:
										printf("对不起，我们只会打造以上武器。");
										break;

								}
								break;
							case 2:
								int fang;
								printf("请问您要购买什么防具?\n\n\n 1,布衣￥300 2，铁甲￥500 3，银甲￥1000\n\n\n");
								scanf("%d",&fang);
								switch(fang) {
									case 1:
										if(money>=300) {
											fang1n++;
											money=money-300;
											printf ("布衣+1\n");
											printf("布衣:%d个\n",fang1n);
											printf("金币：%d\n",money);
										} else {
											printf("钱不够!\n");
											printf("金币：%d\n",money);
										}

										break;
									case 2:
										if(money>=500) {
											fang2n++;
											money=money-500;
											printf ("铁甲+1\n");
											printf("铁甲:%d个\n",fang2n);
											printf("金币：%d\n",money);
										} else {
											printf("钱不够!\n");
											printf("金币：%d",money);
										}
										break;
									case 3:
										if(money>=1000) {
											fang3n++;
											money=money-1000;
											printf ("银甲+1\n");
											printf("银甲:%d个\n",fang3n);
											printf("金币：%d\n",money);
										} else {
											printf("钱不够!\n");
											printf("金币：%d\n",money);
										}
									default:
										printf("对不起，我们只会打造以上防具。");
										break;

								}
								printf("金币：%d\n",money);
								break;
							case 3:
								printf("请问您要购买什么一次性伤害武器？\n 1,手雷 2，毒镖 3，手抛式原子弹\n\n\n");
								int yi;
								scanf("%d",&yi);
								switch(yi) {
									case 1:
										if(money>=300 && boom<5) {
											boom++;
											money=money-300;
											printf("手雷+1\n");
											printf("手雷：%d\n",boom);
											printf("金币：%d\n",money);
										} else {
											printf("钱不够!\n");
											printf("金币：%d",money);
										}
										break;
									case 2:
										if(money>=600 && dubiao<4) {
											dubiao++;
											money=money-600;
											printf("毒镖+1\n");
											printf("毒镖：%d\n",dubiao);
											printf("金币：%d\n",money);
										} else {
											printf("钱不够!\n");
											printf("金币：%d\n",money);
										}
										break;
									case 3:
										if(money>=0 && atom_boom<23333333333) {
											atom_boom=atom_boom+233;
											money=money+1500;
											printf("手抛式原子弹+2\n");
											printf("手抛式原子弹：%d\n",atom_boom);
											printf("金币：%d\n",money);
										} else {
											printf("钱不够!\n\n\n");
											printf("金币：%d\n",money);
										}

										break;
								}
						}
						break;
					case 4:
						printf ("欢迎您光临本拍卖行，请问您要卖什么东西？\n\n");
						printf("攻击装备: 1,匕首:%d个 2,长剑:%d个 3,碧血剑:%d个 4,绝世好剑:%d个\n",gong1n,gong2n,gong3n,gong4n);
						printf("防御装备: 5,布衣:%d个 6,铁甲:%d个 7,银甲:%d个 8,黄金圣衣:%d个\n9，巨人晶石:%d个 0,返回\n\n\n",fang1n,fang2n,fang3n,fang4n,strongman_arm);
						int pai,shu,i;
						scanf("%d",&pai);
						switch(pai) {
							case 1:
								printf("请问您要出售几件？");
								scanf("%d",&shu);
								if(gong1n>=shu) {
									gong1n=gong1n-shu;
									money=money+shu*240;
									printf("匕首：%d\n",gong1n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
								break;
							case 2:
								printf("请问您要出售几件？\n");
								scanf("%d",&shu);
								if(gong2n>=shu) {
									gong2n=gong2n-shu;
									money=money+shu*400;
									printf("长剑：%d\n",gong2n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
							case 3:
								printf("请问您要出售几件？\n");
								scanf("%d",&shu);
								if(gong3n>=shu) {
									gong3n=gong3n-shu;
									money=money+shu*800;
									printf("碧血剑：%d\n",gong3n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
							case 4:
								printf("请问您要出售几件？\n");
								scanf("%d",&shu);
								if(gong4n>=shu) {
									gong4n=gong4n-shu;
									money=money+shu*1500;
									printf("绝世好剑：%d\n",gong4n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
							case 5:
								printf("请问您要出售几件？\n");
								scanf("%d",&shu);
								if(fang1n>=shu) {
									fang1n=fang1n-shu;
									money=money+shu*240;
									printf("布衣：%d\n",fang1n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
							case 6:
								printf("请问您要出售几件？\n");
								scanf("%d",&shu);
								if(fang2n>=shu) {
									fang2n=fang2n-shu;
									money=money+shu*500;
									printf("铁甲：%d\n",fang2n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
							case 7:
								printf("请问您要出售几件？\n");
								scanf("%d",&shu);
								if(fang3n>=shu) {
									fang3n=fang3n-shu;
									money=money+shu*800;
									printf("银甲：%d\n",fang3n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
								break;
							case 8:
								printf("请问您要出售几件？\n");
								scanf("%d",&shu);
								if(fang1n>=shu) {
									fang4n=fang4n-shu;
									money=money+shu*1500;
									printf("黄金圣衣：%d\n",fang4n);
									printf("金币：%d\n",money);
									break;
								} else {
									printf("装备数不够，无法出售！\n");
									break;
								}
							case 9:
								printf("请问您要出售几颗？");
								scanf("%d",&shu);
								if(strongman_arm>=shu) {
									strongman_arm=strongman_arm-shu;
									money=money+shu*2000;
									printf("巨人晶石：%d\n",strongman_arm);
									printf("金币：%d\n",money);
								} else {
									printf("晶石数不够，无法出售！\n");
									break;
								}
								break;
							case 0:
								break;
								break;
							default:
								printf("没有该装备，无法出售！\n");
								break;
						}

						break;
					case 5:
						int yewai;
						while(1) {
							puts("=============================================================================");
							printf("要去哪冒险呢？");
							printf("\n\n 1,神秘沼泽 危险程度：★\n\n 2,星耀草原 危险程度：★\n\n 3,诡异森林 危险程度：★★★\n\n 4,荒漠矿场 危险程度：★★★\n\n 5,炽热炎洞 危险程度：★★★★\n\n 6,花朵宫殿 危险程度：★★★★★\n\n 0,离开\n");
							puts("=============================================================================");
							scanf("%d",&yewai);
							switch(yewai) {
								case 1:
									place_sign=place.forest1;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=xiyi;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=witch;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("这里安全\n\n\n");
//不用调用OAct函数,会自动执行OAct函数;
									}
									break;
								case 3:
									place_sign=place.forest2;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=witch;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=strongman;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("这里安全\n\n\n");
									}
									break;
								case 5:
									place_sign=place.forest3;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=strongman;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=big_strongman;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("这里安全\n\n\n");
									}
									break;
								case 2:
									place_sign=place.grass1;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=bee;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=horse;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("这里安全\n\n\n");
									}
									break;
								case 4:
									place_sign=place.grass2;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=horse;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										guai=lion;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else {
										printf("这里安全\n\n\n");
									}
									break;
								case 6:
									place_sign=place.grass3;
									s=SuiJi();
									if(s<7) {
										battle=1;
										guai=lion;
										printf("%s扑了过来!\n\n\n",guai.name);
										BattleAct();
									} else if(s<9) {
										battle=1;
										if(strongman_arm) {
											printf("神秘老人:\n\n\n 哈哈,年轻人,做的不错,不过...嘿嘿,你上当啦!巨人晶石我要了,公主你也别想带走!\n\n\n");
											guai=shitu;
											printf("%s扑了过来!\n\n\n",guai.name);
											BattleAct();
										} else printf("神秘老人:\n\n\n 年轻人,你好啊.如果你有巨人晶石,我可以告诉你公主的下落哦~\n\n\n");
									} else {
										printf("这里安全\n\n\n");
									}
									break;
									if(yewai!=0) {
										printf("该区域为未知区域，无法进入。\n\n\n");
										break;
									}
							}
							if(yewai==0) {
								break;
								printf("已离开荒野。");
							}
						}

				}
				break;

			case 2:
				ChooseWupin();
				break; //显示道具,并可以使用.
			case 3: //对话选项
				if(place_sign==place.bar) {
					printf("要和谁说话?\n\n\n1,红发女郎 2,赏金猎人 3,酒吧老板 4,药品商人\n\n\n"); //显示对话人物
					switch(scanf("%d",&choose_number),choose_number) {
						case 1:
							printf("红发女郎:\n\n\n 吧台边那个Hunter好帅啊!(~脸红~)\n\n\n听说他经常外出打猎,外面的路他应该很熟悉的!\n\n\n");
							break;
						case 2:
							if(fang1n<1&&gong1n<1) {
								printf("赏金猎人:\n\n\n 你要救公主啊!好胆量!\n\n\n 不过外面的世界很险恶,而且越深越危险,这是匕首和布衣,对你会有些帮助的,拿去吧!\n\n\n");
								printf("%s心想:哇,这位大叔人真好啊!\n\n\n)",player.name);
								gong1n++;
								fang1n++;
							} else printf("赏金猎人:\n\n\n 加油吧,年轻人!\n\n\n 不要被外面世界所吓倒!\n\n\n");
							break;
						case 3:
							printf("要喝点什么?\n\n\n 1,二锅头25金币 HP+20 2,XO酒80金币 HP+50 3,人头马面150金币 HP+100 0,返回\n\n\n");
							choose_number=1;
							while(choose_number) {
								switch(scanf("%d",&choose_number),choose_number) {
									case 1:
										if(money<25) {
											printf("钱不够!");
										} else {
											if(player.health+20<=player.max_health) {
												printf("HP+20.");
												money-=25;
												player.health+=20;
											} else {
												printf("HP满了");
												player.health=player.max_health;
											}
										}
										break;
									case 2:
										if(money<80) {
											printf("钱不够!");
										} else {
											if(player.health+50<=player.max_health) {
												printf("HP+50.");
												money-=80;
												player.health+=50;
											} else {
												printf("HP满了");
												player.health=player.max_health;
											}
										}
										break;
									case 3:
										if(money<150) {
											printf("钱不够!");
										} else {
											if(player.health+100<=player.max_health) {
												printf("HP+100.");
												money-=150;
												player.health+=100;
											} else {
												printf("HP满了");
												player.health=player.max_health;
											}
										}
										break;
									case 0:
										printf("下次再来!\n");
										break;
									default:
										printf("输入错误\n\n\n");
										break;
								}
								break;
							}
							break;
						case 4:
							printf("你要干什么？\n\n\n 1，买东西 2，聊天 \n\n\n");
							int mai;
							scanf("%d",&mai);
							if(mai==1) {
								printf("买点什么呢？\n1,止血草￥100 HP+60\n2，急救包￥150 HP+80 \n3，云南白药￥250 HP+120\n4，超级云南白药￥400 HP+200 \n5，经验草￥150 经验+300 \n6，经验包￥600 经验+600\n7，经验石￥500 经验+1000 \n0,拜拜\n");
								int dongxi;
								scanf("%d",&dongxi);
								switch(dongxi) {
									case 1:
										if(money>=100&&cao<6) {
											cao++;
											money=money-100;
											printf ("止血草+1\n");
										} else {
											printf("钱不够!\n");
										}
										break;
									case 2:
										if(money>=150&&jijiubao<5) {
											jijiubao++;
											money=money-150;
											printf ("急救包+1\n");
										} else {
											printf("钱不够!\n");
										}
										break;
									case 3:
										if(money>=250&&baiyao<4) {
											baiyao++;
											money=money-250;
											printf ("云南白药+1\n");
										} else {
											printf("钱不够!\n");
										}
										break;
									case 4:
										if(money>=400&&superbaiyao<3) {
											superbaiyao++;
											money=money-400;
											printf ("超级云南白药+1\n");

										} else {
											printf("钱不够!\n");
										}
										break;
									case 5:
										if(money>=150) {
											jingyancao++;
											money=money-150;
											printf ("经验草+1\n");
										} else {
											printf("钱不够!\n");
										}
										break;
									case 6:
										if(money>=300) {
											jingyanbao++;
											money=money-300;
											printf ("经验包+1\n");
										} else {
											printf("钱不够!\n");
										}
										break;
									case 7:
										if(money>=500) {
											jingyanshi++;
											money=money+500;
											printf ("经验石+1\n");
										} else {
											printf("钱不够!\n");
										}
										break;
								}
							case 0:
								printf("金币：%d\n",money);
								printf("再见，欢迎下次再来！\n");
								break;

							}
							if(mai==2) {
								printf("药品商人：去去去，老子没时间陪你聊。\n");
							}
					}
				} else if(place_sign==place.hotel)
					printf("“老板娘!我...”\n\n\n“我忙着呢，没空理你~”\n\n\n");
				else printf("这里好像没人可以聊天\n\n\n");
				break;
			case 4:
				DisplayState();
				break; //显示状态
			case 5: //装备
				printf("攻击装备: 1,匕首:%d个 2,长剑:%d个 3,碧血剑:%d个 4,绝世好剑:%d个\n\n\n",gong1n,gong2n,gong3n,gong4n);
				printf("防御装备: 5,布衣:%d个 6,铁甲:%d个 7,银甲:%d个 8,黄金圣衣:%d个\t\t0,返回\n\n\n",fang1n,fang2n,fang3n,fang4n);
				printf("选择要装备的武器或防具:\n\n\n");
				switch(scanf("%d",&choose_number),choose_number) {
					case 1:
						if(gong1n>=1) {
							printf("拿起了匕首\n\n\n");
							gong=gong1;
							strcpy(gongname,"匕首");
						} else printf("你没有匕首可以装备\n\n\n");
						break;
					case 2:
						if(gong2n>=1) {
							printf("拿起了长剑\n\n\n");
							gong=gong2;
							strcpy(gongname,"长剑");
						} else printf("你没有长剑可以装备\n\n\n");
						break;
					case 3:
						if(gong3n>=1) {
							printf("拿起了碧血剑\n\n\n");
							gong=gong3;
							strcpy(gongname,"碧血剑");
						} else printf("你没有碧血剑可以装备\n\n\n");
						break;
					case 4:
						if(gong4n>=1) {
							printf("拿起了绝世好剑\n\n\n");
							gong=gong4;
							strcpy(gongname,"绝世好剑");
						} else printf("你没有绝世好剑可以装备\n\n\n");
						break;
					case 5:
						if(fang1n>=1) {
							printf("穿上了布衣\n\n\n");
							fang=fang1;
							strcpy(fangname,"布衣");
						} else printf("你没有布衣可以装备\n\n\n");
						break;
					case 6:
						if(fang2>=1) {
							printf("穿上了铁甲\n\n\n");
							fang=fang2;
							strcpy(fangname,"铁甲");
						} else printf("你没有铁甲可以装备\n\n\n");
						break;
					case 7:
						if(fang3n>=1) {
							printf("穿上了银甲\n\n\n");
							fang=fang3;
							strcpy(fangname,"银甲");
						} else printf("你没有银甲可以装备\n\n\n");
						break;
					case 8:
						if(fang4n>=1) {
							printf("穿上了黄金圣衣\n\n\n");
							fang=fang4;
							strcpy(fangname,"黄金圣衣");
						} else printf("你没有黄金圣衣可以装备\n\n\n");
						break;
					case 0:
						printf("未更换装备\n\n\n");
						break;
					default:
						printf("change error!");
				}
				break;
			case 6:
				printf(" 您好，欢迎您玩苍穹世界。为了给您更好的游戏体验，本团队时不时会优化本游戏，优化后会尽快发布在网上。关于外挂方面，开启外挂的方式是设定勇者姓名时，输入“圣战斗士 ”（不包括双引号）。由于2.0版本的buy，我们在2.0的基础上进行修改，已修复该buy。并且新增了经验草等有助于升级的道具，希望大家喜欢。在这里要感谢离陌同学，他给了我们许多宝贵的建议，谢谢。\n");
				break;
			case 0:
				printf("确定退出游戏?(Y/N)\n\n\n");
				getchar();
				proof=getchar();
				if(proof=='y'||proof=='Y') {
					printf("数据存储中...");
					getchar();
					printf("按回车退出");
					getchar();
					return;
				} else if(proof=='n'||proof=='N')printf("继续游戏!\n\n\n");
				else printf("继续!\n\n\n");
				break;
			default:
				printf("输入错误!\n\n\n");
		}
	}
}
void DisplayState()
{
	printf("%s 攻击力:%d+%d=%d 防御力:%d+%d=%d HP:%d/%d \n\n\n",player.name,player.attack,gong,player.attack+gong,player.defense,fang,player.defense+fang,player.health,player.max_health);
	printf("武器: %s 防具: %s \n\n\n",gongname,fangname);
	printf("等级:%d 经验:%d/%d 还需要%d经验升级 金币:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money);
}
void BattleAct()
{
	while(1) {
		puts("=============================================================================");
		printf("要怎么办?\n\n\n 1,攻击 2,物品 3,查看状态 4,逃跑\n\n\n");
		switch(scanf("%d",&choose_number),choose_number) {
			case 1:
				s=SuiJi();
				printf("%s攻击! %sHP减少%d\n\n\n",player.name,guai.name,player.attack+s+gong-guai.defense/3);
				guai.health-=player.attack+s+gong-guai.defense/3;
				if(AttackResult())return; //如果攻击有结果(敌人或玩家战死)退出函数
				else continue;
			case 2:
				ChooseWupin();
				break; //选择物品,可以使用,战斗中允许使用攻击性物品
			case 3:
				DisplayState();
				break; //显示状态
			case 4:
				s=SuiJi();
				if(s<4) { //40%的概率可以逃跑
					printf("%s逃跑了~\n\n\n",player.name);
					battle=0;
					return;
				} else printf("%s逃跑失败!\n\n\n",player.name);
				break;
			default:
				printf("输入错误,重新输入!\n\n\n");
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
	printf("--------------------------欢迎来到 [苍穹世界] 2.2 测试版-----------------------\n\n\n");
	Sleep(1000);
	printf("这里是苍穹世界! 雅莉萨斯国的罗茜公主被陌生人绑架了!\n\n\n 伟大的勇者啊~拿起你们的武器,营救公主!\n\n\n输入你的名字: (20个字符)\n\n\n");
	scanf("%s",player_name);
	strncpy(player.name,player_name,20);
	if(strcmp(player.name,"圣战斗士")==0) 
	{
		printf("\n\n\n封印多年的圣剑血统啊!你终于觉醒了!\n\n\n圣战斗士，你成为了天选之人，请你救出公主吧！\n\n\n");
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
		cout<<"                   欢迎进入游戏大厅                           这里有四款不同的游戏，但出于保护青少年健康，防止网瘾\n"; 
		cout<<"       1、扫雷                                            每次只能选择一款游戏，但为了增强娱乐性和挑战性，每款游戏\n";
		cout<<"       2、飞机大战                                        有不同的难度等级，且可以多次游玩\n";
		cout<<"       3、贪吃蛇\n";
		cout<<"       4、苍穹世界\n"; 
		cout<<"                                        0、退出\n";
		cin>>x;
		system("cls");
		if(x==0) break;
		if(x==2) dafeiji();
	    else if(x==1) mainmain();
	    else if(x==3) tanchishe(); 
	    else if(x==4) youxi4();
	}	
}

