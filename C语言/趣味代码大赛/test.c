/*
 * @�������κ���
 * @ѧ�ţ�21375321
 * @��Ʒ���ƣ��ɻ���ս����/˫�ˣ�
 * @�汾��1.0
 * @�ύ���ڣ�2022-04-28
 * 
 * @���룺1/2ѡ��ģʽ��Ȼ����ݼ����п���
 * 
 * @�����ʤ����ʧ��
 * 
 * @����˵����һ��С��Ϸ
 * 
 * @����˵�����������н��չʾͼƬ���������ӵ�Ͷ�����ϣ����ϴ����������̽��������ӷ����˴�
 * 
 * @�ο���Դ������ˡ�c���Կγ��������Ϸ����ʵ���̡̳�  �ı�������һЩ��������
 * 
 */

/*********************�����油����ĸ��˺ʹ�����Ϣ*********************/
/***********************�������д���Ȥζ����************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// ȫ�ֱ���
int position_x,position_y; // �ɻ�λ��
int position_x2,position_y2; // �ɻ�λ��
int bullet_x,bullet_y; // �ӵ�λ��
int laster_y; // ����λ�� 
int enemy_x,enemy_y; // �л�λ��
int enemy_x2,enemy_y2; // �л�λ��
int high,width; //  ��Ϸ����ߴ� //  ��Ϸ����ߴ�
int score=0; // �÷�
int score2=0; // �÷�2
int esc=1; //��ͣ 

void gotoxy(int x,int y)  //����ƶ���(x,y)λ��
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor() // �������ع��
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // �ڶ���ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup() // ���ݳ�ʼ��
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
	void show()  // ��ʾ����
	{
		gotoxy(0,0);  // ����ƶ���ԭ��λ�ã������ػ�����
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
					printf("@");  //   ����л�@
				else if ((i==bullet_x) && (j==bullet_y-1))
					printf("|||");  //   ����ӵ�|
				else if (j==laster_y && i<position_x-1)
					printf("|");  //   �������|
				else
					printf(" ");  //   ����ո�
			}
			printf("\n");
		}
		if (laster_y!=enemy_y) laster_y = -1;
		printf("�÷֣�%d\n",score);
	} 

	void updateWithoutInput()  // ���û������޹صĸ���
	{	
		if(esc==1)
		{
			if (bullet_x>-1)
				bullet_x--;   //�ӵ����Ϸ��� 	
			if ((bullet_x==enemy_x) && (bullet_y==enemy_y||bullet_y-1==enemy_y||bullet_y+1==enemy_y))  // �ӵ����ел�
			{
				score++;                // ������1
				enemy_x = -1;           // �����µķɻ�
				enemy_y = rand()%width;
				bullet_x = -2;          // �ӵ���Ч
			}
			if (laster_y==enemy_y)  // ������ел�
			{
				score++;                // ������1
				enemy_x = -1;           // �����µķɻ�
				enemy_y = rand()%width;
				laster_y = -1;
			}
			if (enemy_x>high)   // �л��ܳ���ʾ��Ļ
			{
				enemy_x = -1;           // �����µķɻ�
				enemy_y = rand()%width;
				score-=5; 
			}	
			// �������Ƶл������ƶ����ٶȡ�ÿ������ѭ�������ƶ�һ�εл�
			// �����޸ĵĻ����û����������ٶȻ��Ǳ��ֺܿ죬������NPC���ƶ���ʾ���Խ���
			static int speed = 0;     //static ȫ�ֱ��� 
			if (speed<20)
				speed++;
			if (speed == 20)
			{
				enemy_x++;			
				speed = 0;
			}
		}
	} 

	void updateWithInput()  // ���û������йصĸ���
	{
		char input;
		if(kbhit())  // �ж��Ƿ�������
		{	
			input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
			if (input == 'a')   
				position_y--;  // λ������
			if (input == 'd')
				position_y++;  // λ������
			if (input == 'w')
				position_x--;  // λ������
			if (input == 's')
				position_x++;  // λ������
			if (input == ' ')  // �����ӵ�
			{
				bullet_x = position_x-2;  // �����ӵ��ĳ�ʼλ���ڷɻ������Ϸ�
				bullet_y = position_y;
			}
			if (input == '0')  //���伤�� 
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




	void show2()  // ��ʾ����
	{
		gotoxy(0,0);  // ����ƶ���ԭ��λ�ã������ػ�����
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
					printf("@");  //   ����л�@
				else if ((i==enemy_x2) && (j==enemy_y2))
					printf("@");  //   ����л�@2
				else if ((i==bullet_x) && (j==bullet_y-1))
					printf("|||");  //   ����ӵ�|
				else if (j==laster_y && i<position_x-1)
					printf("|");  //   �������|
				else
					printf(" ");  //   ����ո�
			}
			printf("\n");
		}
		if (laster_y!=enemy_y&&laster_y!=enemy_y2) laster_y = -1;
		printf("Player1�÷֣�%d\n",score);
		printf("Player2�÷֣�%d\n",score2);
	} 

	void updateWithoutInput2()  // ���û������޹صĸ���
	{	
		if(esc==1)
		{
			if (bullet_x>-1)
				bullet_x--;   //�ӵ����Ϸ��� 	
			if ((bullet_x==enemy_x) && (bullet_y==enemy_y||bullet_y-1==enemy_y||bullet_y+1==enemy_y))  // �ӵ����ел�
			{
				score++;                // ������1
				enemy_x = -1;           // �����µķɻ�
				enemy_y = rand()%(width/2);
				bullet_x = -2;          // �ӵ���Ч
			}
			if ((bullet_x==enemy_x2) && (bullet_y==enemy_y2||bullet_y-1==enemy_y2||bullet_y+1==enemy_y2))  // �ӵ����ел�
			{
				score++;                // ������1
				enemy_x2 = -1;           // �����µķɻ�
				enemy_y2 = rand()%(width/2+1)+width/2;
				bullet_x = -2;          // �ӵ���Ч
			}
			if (laster_y==enemy_y)  // ������ел�
			{
				score2++;                // ������1
				enemy_x = -1;           // �����µķɻ�
				enemy_y = rand()%width;
				laster_y = -1;
			}
			if (laster_y==enemy_y2)  // ������ел�
			{
				score2++;                // ������1
				enemy_x2 = -1;           // �����µķɻ�
				enemy_y2 = rand()%width;
				laster_y = -1;
			}
			if (enemy_x>high)   // �л��ܳ���ʾ��Ļ
			{
				enemy_x = -1;           // �����µķɻ�
				enemy_y = rand()%width;
				score-=5; 
				score2-=5;
			}	
			if (enemy_x2>high)   // �л��ܳ���ʾ��Ļ
			{
				enemy_x2 = -1;           // �����µķɻ�
				enemy_y2 = rand()%width;
				score-=5; 
				score2-=5;
			}
			// �������Ƶл������ƶ����ٶȡ�ÿ������ѭ�������ƶ�һ�εл�
			// �����޸ĵĻ����û����������ٶȻ��Ǳ��ֺܿ죬������NPC���ƶ���ʾ���Խ���
			static int speed = 0;     //static ȫ�ֱ��� 
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

	void updateWithInput2()  // ���û������йصĸ���
	{
		char input;
		if(kbhit())  // �ж��Ƿ�������
		{	
			input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
			if (input == 'a')   
				position_y--;  // λ������
			if (input == 'd')
				position_y++;  // λ������
			if (input == 'w')
				position_x--;  // λ������
			if (input == 's')
				position_x++;  // λ������
			if(position_y>=position_y2-2) position_y--;
			if (input == '4')   
				position_y2--;  // λ������
			if (input == '6')
				position_y2++;  // λ������
			if (input == '8')
				position_x--;  // λ������
			if (input == '2')
				position_x++;  // λ������
			if(position_y2<=position_y+2) position_y2++;
			if (input == ' ')  // �����ӵ�
			{
				bullet_x = position_x-2;  // �����ӵ��ĳ�ʼλ���ڷɻ������Ϸ�
				bullet_y = position_y;
			}
			if (input == '0')  //���伤�� 
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
	printf("����1/2ѡ��/˫��ģʽ\n����ģʽwsad�����ƶ����ո����ӵ���\"0\"���伤��\n˫��ģʽwsad 8246�����ƶ����ո� \"0\"����\n");
	scanf("%d",&moShi); 
	system("cls");
	HideCursor(); 
	startup();  // ���ݳ�ʼ��	
	while (moShi==1) //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();  // ���û������йصĸ���
		if(score>=66){
			printf("YOU WIN");
			break;
		}
		if(score<-5){
			printf("YOU LOSE");
			break;
		}
	}
	while (moShi==2) //  ��Ϸѭ��ִ��
	{
		show2();  // ��ʾ����
		updateWithoutInput2();  // ���û������޹صĸ���
		updateWithInput2();  // ���û������йصĸ���
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
