/*#include<iostream>
#include<string>
#include<vector>

#include<graphics.h>
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
int main(int argc,char **argv)
{
	initgraph(400,480);
	loadimage(0,"4.jpg");
	setlinecolor(RED);
	setlinestyle(PS_SOLID,5);
	circle(200,200,100);	
	settextcolor(WHITE);
	settextstyle(20,0,"宋体");
	outtextxy(130,190,"无敌是多么寂寞");
	int x = 200, y = 200,m=130,n=190;
	while (1)
	{

		char a;
		a=_getch() ;
		switch (a)
		{
		case 'i': {loadimage(0, "4.jpg"); circle(x , y-= 20, 100); outtextxy(m, n-=20, "无敌是多么寂寞"); break; }
		case 'k': {	loadimage(0, "4.jpg"); circle(x , y+= 20, 100); outtextxy(m, n+=20, "无敌是多么寂寞"); break; }
		case 'j':{loadimage(0, "4.jpg"); circle(x-= 20, y , 100); outtextxy(m-=20, n, "无敌是多么寂寞"); break;}
		case 'l':{	loadimage(0, "4.jpg"); circle(x+= 20, y , 100); outtextxy(m+=20, n, "无敌是多么寂寞"); break;}
		}
		if (a == 'e')
			break;
	}closegraph();
	system("pause");
	

}
