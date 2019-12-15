#include<graphics.h>
#include<conio.h>
#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<windows.h> 
#include<string.h> 
#pragma comment(lib,"Winmm.lib")
using namespace std;
class bullet;
class Move{
public:
	Move(int x1,int y1)
	{
		x= 470 ; y =570;
		a =x1; b =  y1;
		a1 = 500; b1 = 150;
		dis = 0;
		ch ='t';
	}
	friend class bullet;
	void enemymove();
	void playermove();
	void clearit()
	{
		cleardevice();
		dis = 1;
	}
	void putpicture()
	{
		
		
		IMAGE img;
		IMAGE img1;
		IMAGE img2;
		loadimage(&img, L"E:\\vs的调用图片\\a.jpg", 100, 100);
		loadimage(&img1, L"E:\\vs的调用图片\\b.jpg", 100, 100);
		loadimage(&img2, L"E:\\vs的调用图片\\c.jpg", 30, 30);
		
		putimage(a, b, &img);
		putimage(a1, b1, &img1);
		putimage(x,y, &img2);
	}
	int x,y,a,b,a1,b1,dis;
	char ch;
};
void Move::enemymove()
{
	if (a < 990)
		a = a + 1;
	if (a1 > 10)
		a1 = a1 -1;
}
void Move::playermove()
{   
	
	ch=_getch();
	switch(ch)
	{
	case 'W':case 'w':
	{
		y = y -30;
		
		break;

	}
	case 'S':case 's':
	{
		y = y + 30;


		break;
	}

	case 'A':case 'a':
	{
		x = x-20;
		break;
	}
	case 'd':case 'D':
	{
		x = x+20;
		break;
	}
	
	}
	
}
class bullet{
public:
	bullet(Move &w)
	{
		bx = w.a + 40;
		by = w.b + 100;
		//k = int((w.b - w.y + 65) / (w.a - w.x + 35));
		k = 1;
		
	}
	int juct(Move &w)
	{
		if ((bx - 2) > w.x - 15 && (bx - 2) < w.x + 15 && (by - 2) > w.y - 15 && (by - 2) < w.y + 15)
			return 1;
		else return 0;


	}
	void enemyshoot()
	{
		
		IMAGE bullet1;
		loadimage(&bullet1, L"E:\\vs的调用图片\\bullet.jpg",30, 30);
		putimage(bx, by, &bullet1);
		by = by + 2;
		//bx = bx +int(by/k) ;
		bx = bx + 2;
	}
private:
	int bx, by,k;
	wchar_t s[5];
	char str[5];
};
int _tmain(int argc, _TCHAR* argv[])
{

	IMAGE back;
	loadimage(&back, L"E:\\vs的调用图片\\hehe.jpg",1000, 600);
	int ju=0;
	string t="p";
	initgraph(1000,600);
	Move player(0,0);
	bullet f(player);
	mciSendString(_T("open music1.mp3 alias mymusic"), NULL, 0, NULL);
	mciSendString(_T("play mymusic"), NULL, 0, NULL);
	BeginBatchDraw();
	while(t!="n")
	{
	putimage(0,0,&back);	
	player.putpicture();
	f.enemyshoot();
	FlushBatchDraw();
	player.enemymove();
	Sleep(30);
	player.clearit();
	if (_kbhit()) { player.playermove();}
	ju=f.juct(player);
	if (ju == 1)break;
	//clearrectangle(0, 0, 100, 100);
	//cleardevice();
	
	
	 }
	EndBatchDraw();
	closegraph();
	cout << "你已死亡！" << endl;
	return 0;
}
