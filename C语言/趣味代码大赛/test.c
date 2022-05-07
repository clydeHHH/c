/*
 * @姓名：任浩祺
 * @学号：21375321
 * @作品名称：飞机大战（单/双人）
 * @版本：1.0
 * @提交日期：2022-04-28
 * 
 * @输入：1/2选择模式，然后根据简介进行控制
 * 
 * @输出：胜利或失败
 * 
 * @功能说明：一个小游戏
 * 
 * @补充说明：代码运行结果展示图片、其他附加的投稿资料，可上传至北航云盘将分享链接放至此处
 * 
 * @参考来源：借鉴了《c语言课程设计与游戏开发实践教程》  改编增加了一些其他功能
 * 
 */

/*********************在上面补充你的个人和代码信息*********************/
/***********************在下面编写你的趣味代码************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// 全局变量
int position_x,position_y; // 飞机位置
int position_x2,position_y2; // 飞机位置
int bullet_x,bullet_y; // 子弹位置
int laster_y; // 激光位置 
int enemy_x,enemy_y; // 敌机位置
int enemy_x2,enemy_y2; // 敌机位置
int high,width; //  游戏画面尺寸 //  游戏画面尺寸
int score=0; // 得分
int score2=0; // 得分2
int esc=1; //暂停 

void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor() // 用于隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup() // 数据初始化
{
	high = 20;
	width = 50;
	position_x = high/2;
	position_y = width/2-10;
	position_y2 = width/2+10;
	bullet_x = -1;
	bullet_y = position_y;
	enemy_x = 0;
	enemy_y = position_y;
	enemy_x2 = 0;
	enemy_y2 = position_y2+5;
	laster_y = -1;
}
	void show()  // 显示画面
	{
		gotoxy(0,0);  // 光标移动到原点位置，以下重画清屏
		int i,j,k;
		for (i=0;i<high;i++)
		{
			for (j=0;j<width;j++)
			{
				if ((i==position_x-1) && (j==position_y))
				{	
					printf("*");
				}
				if ((i==position_x) && (j==position_y-2))
				{
					printf("*****");
				}
				if ((i==position_x+1) && (j==position_y-1))
				{
					printf("* * ");
				}
				else if ((i==enemy_x) && (j==enemy_y))
					printf("@");  //   输出敌机@
				else if ((i==bullet_x) && (j==bullet_y-1))
					printf("|||");  //   输出子弹|
				else if (j==laster_y && i<position_x-1)
					printf("|");  //   输出激光|
				else
					printf(" ");  //   输出空格
			}
			printf("\n");
		}
		if (laster_y!=enemy_y) laster_y = -1;
		printf("得分：%d\n",score);
	} 

	void updateWithoutInput()  // 与用户输入无关的更新
	{	
		if(esc==1)
		{
			if (bullet_x>-1)
				bullet_x--;   //子弹向上发射 	
			if ((bullet_x==enemy_x) && (bullet_y==enemy_y||bullet_y-1==enemy_y||bullet_y+1==enemy_y))  // 子弹击中敌机
			{
				score++;                // 分数加1
				enemy_x = -1;           // 产生新的飞机
				enemy_y = rand()%width;
				bullet_x = -2;          // 子弹无效
			}
			if (laster_y==enemy_y)  // 激光击中敌机
			{
				score++;                // 分数加1
				enemy_x = -1;           // 产生新的飞机
				enemy_y = rand()%width;
				laster_y = -1;
			}
			if (enemy_x>high)   // 敌机跑出显示屏幕
			{
				enemy_x = -1;           // 产生新的飞机
				enemy_y = rand()%width;
				score-=5; 
			}	
			// 用来控制敌机向下移动的速度。每隔几次循环，才移动一次敌机
			// 这样修改的话，用户按键交互速度还是保持很快，但我们NPC的移动显示可以降速
			static int speed = 0;     //static 全局变量 
			if (speed<20)
				speed++;
			if (speed == 20)
			{
				enemy_x++;			
				speed = 0;
			}
		}
	} 

	void updateWithInput()  // 与用户输入有关的更新
	{
		char input;
		if(kbhit())  // 判断是否有输入
		{	
			input = getch();  // 根据用户的不同输入来移动，不必输入回车
			if (input == 'a')   
				position_y--;  // 位置左移
			if (input == 'd')
				position_y++;  // 位置右移
			if (input == 'w')
				position_x--;  // 位置上移
			if (input == 's')
				position_x++;  // 位置下移
			if (input == ' ')  // 发射子弹
			{
				bullet_x = position_x-2;  // 发射子弹的初始位置在飞机的正上方
				bullet_y = position_y;
			}
			if (input == '0')  //发射激光 
			{
				laster_y = position_y;
			} 
			if (input == 27)
			{
				if(esc==0) esc=1;
				else esc=0;
			}
		}
	}




	void show2()  // 显示画面
	{
		gotoxy(0,0);  // 光标移动到原点位置，以下重画清屏
		int i,j,k;
		for (i=0;i<high;i++)
		{
			for (j=0;j<width;j++)
			{
				if ((i==position_x-1) && (j==position_y-2))
				{	
					printf("  *  ");
				}
				if ((i==position_x) && (j==position_y-2))
				{
					printf("*****");
				}
				if ((i==position_x+1) && (j==position_y-2))
				{
					printf(" * * ");
				}
				if ((i==position_x-1) && (j==position_y2-2))
				{	
					printf("  *  ");
				}
				if ((i==position_x) && (j==position_y2-2))
				{
					printf(" * * ");
				}
				if ((i==position_x+1) && (j==position_y2-2))
				{
					printf("** **");
				}
				else if ((i==enemy_x) && (j==enemy_y))
					printf("@");  //   输出敌机@
				else if ((i==enemy_x2) && (j==enemy_y2))
					printf("@");  //   输出敌机@2
				else if ((i==bullet_x) && (j==bullet_y-1))
					printf("|||");  //   输出子弹|
				else if (j==laster_y && i<position_x-1)
					printf("|");  //   输出激光|
				else
					printf(" ");  //   输出空格
			}
			printf("\n");
		}
		if (laster_y!=enemy_y&&laster_y!=enemy_y2) laster_y = -1;
		printf("Player1得分：%d\n",score);
		printf("Player2得分：%d\n",score2);
	} 

	void updateWithoutInput2()  // 与用户输入无关的更新
	{	
		if(esc==1)
		{
			if (bullet_x>-1)
				bullet_x--;   //子弹向上发射 	
			if ((bullet_x==enemy_x) && (bullet_y==enemy_y||bullet_y-1==enemy_y||bullet_y+1==enemy_y))  // 子弹击中敌机
			{
				score++;                // 分数加1
				enemy_x = -1;           // 产生新的飞机
				enemy_y = rand()%(width/2);
				bullet_x = -2;          // 子弹无效
			}
			if ((bullet_x==enemy_x2) && (bullet_y==enemy_y2||bullet_y-1==enemy_y2||bullet_y+1==enemy_y2))  // 子弹击中敌机
			{
				score++;                // 分数加1
				enemy_x2 = -1;           // 产生新的飞机
				enemy_y2 = rand()%(width/2+1)+width/2;
				bullet_x = -2;          // 子弹无效
			}
			if (laster_y==enemy_y)  // 激光击中敌机
			{
				score2++;                // 分数加1
				enemy_x = -1;           // 产生新的飞机
				enemy_y = rand()%width;
				laster_y = -1;
			}
			if (laster_y==enemy_y2)  // 激光击中敌机
			{
				score2++;                // 分数加1
				enemy_x2 = -1;           // 产生新的飞机
				enemy_y2 = rand()%width;
				laster_y = -1;
			}
			if (enemy_x>high)   // 敌机跑出显示屏幕
			{
				enemy_x = -1;           // 产生新的飞机
				enemy_y = rand()%width;
				score-=5; 
				score2-=5;
			}	
			if (enemy_x2>high)   // 敌机跑出显示屏幕
			{
				enemy_x2 = -1;           // 产生新的飞机
				enemy_y2 = rand()%width;
				score-=5; 
				score2-=5;
			}
			// 用来控制敌机向下移动的速度。每隔几次循环，才移动一次敌机
			// 这样修改的话，用户按键交互速度还是保持很快，但我们NPC的移动显示可以降速
			static int speed = 0;     //static 全局变量 
			if (speed<20)
				speed++;
			if (speed == 20)
			{
				enemy_x++;
				enemy_x2++;			
				speed = 0;
			}
		}
	} 

	void updateWithInput2()  // 与用户输入有关的更新
	{
		char input;
		if(kbhit())  // 判断是否有输入
		{	
			input = getch();  // 根据用户的不同输入来移动，不必输入回车
			if (input == 'a')   
				position_y--;  // 位置左移
			if (input == 'd')
				position_y++;  // 位置右移
			if (input == 'w')
				position_x--;  // 位置上移
			if (input == 's')
				position_x++;  // 位置下移
			if(position_y>=position_y2-2) position_y--;
			if (input == '4')   
				position_y2--;  // 位置左移
			if (input == '6')
				position_y2++;  // 位置右移
			if (input == '8')
				position_x--;  // 位置上移
			if (input == '2')
				position_x++;  // 位置下移
			if(position_y2<=position_y+2) position_y2++;
			if (input == ' ')  // 发射子弹
			{
				bullet_x = position_x-2;  // 发射子弹的初始位置在飞机的正上方
				bullet_y = position_y;
			}
			if (input == '0')  //发射激光 
			{
				laster_y = position_y2+5;
			} 
			if (input == 27)
			{
				if(esc==0) esc=1;
				else esc=0;
			}
		}
	}





int main()
{
	int moShi;
	printf("输入1/2选择单/双人模式\n单人模式wsad控制移动，空格发射子弹，\"0\"发射激光\n双人模式wsad 8246控制移动，空格 \"0\"发射\n");
	scanf("%d",&moShi); 
	system("cls");
	HideCursor(); 
	startup();  // 数据初始化	
	while (moShi==1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
		if(score>=66){
			printf("YOU WIN");
			break;
		}
		if(score<-5){
			printf("YOU LOSE");
			break;
		}
	}
	while (moShi==2) //  游戏循环执行
	{
		show2();  // 显示画面
		updateWithoutInput2();  // 与用户输入无关的更新
		updateWithInput2();  // 与用户输入有关的更新
		if(score>=66){
			printf("YOU WIN");
			break;
		}
		if(score<-5){
			printf("YOU LOSE");
			break;
		}
	}
	return 0;
}
