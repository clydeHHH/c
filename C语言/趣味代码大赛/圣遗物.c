/*
*@������
*@ѧ��114514
*@��Ʒ����
��ת����Ϊ��Ҷ�Ĺ� ����ǿ��ʥ���
*@�汾2.0   
*@�ύ���� 2022-4-29
*
*@����
����ʾ���뼴��
����ѡ��鿨 || ǿ��ʥ����

*@���
�鿨���鿨��������ַ������ַ���������С�ʵ�
ǿ��ʥ���ʥ�����ǿ�������(û�а��ĸ��ʣ�

*@����˵��
* �鿨��
ģ��ԭ��ĳ鿨��֧��봽�ȡ��ж��ֽ�������Զ��Լ���
*ǿ��
ģ��ǿ��ʥ����ģ�����ѡ���ʲôʥ���������������ټ�
*���˸о�ǿ��ʥ�������ú�һ�㣬�����ܻ���Сbugû������

*@����˵��
Ӧ�þ���final��

*@�ο���Դ
�����ַ����õ�python,�ο�https://blog.csdn.net/Wmayy_123/article/details/106376675
���ο���������ƪ���ӣ�ҪôЧ�����ã�Ҫôֻ�����ͼƬ������py���������

ǿ��ʥ����û�вο����룬һЩ�����ǲο��������������վ
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define min(a,b) (((a)<(b)) ? (a) : (b) )
//�鿨
int cost = 0;//��Щ������ƴ����
int fenqiu = 0;
int yuanshi = 0;
int jiejing = 0;
int exit0 = 0;
int baodi = 0;
int count = 0, count4 = 0;
void show_start();//�����������е���ң����ø���
void show_kucun();
int show_1_or_10();
int show_que(int);
int show_duihuan(int);
void show_kr();
void show_qrcode();
void come_on_wanye(int);
int grd_mhy(int, int);
void chouka();
void wanye();
void juese5();
void juese4();
void wuqi4();
void wuqi3();
void show_qrcode();
//ǿ��
int expe = 0, money = 0;
char Type0[6][30] = { "��֮��","��֮��","ʱ֮ɳ","��֮��","��֮��" };//5
char Name0[30][30] = { "���ȵ���֮ħŮ","�ɹ��һ������","������;����ʿ","����֮��","׷��֮ע��",
	"��Ե֮��ӡ","����֮Ӱ","����������Ů","ȾѪ����ʿ��","��������֮��","���˴�ص�����","�Ƕ�ʿ����Ļ��","ǧ���ι�",
	"�԰�֮��","���������κ���","��Ⱦ����","���׵�ʢŭ","ƽϢ���׵�����","��ɵ�����","�ƹŵ�����","�������","��ɰ����¼" };//22
char fu0[20][30] = { "�󹥻�","С����","������","С����","�����","С����","������","�����˺�","��ͨ","����" };//10
char zhu0[20][30] = { "С����","С����","������","�����˺�","����","��ͨ","�󹥻�","�����","������",
		"����","����","ˮ��","����","����","����","����","����" };//17

double zhu_num[20][21] = { 
717, 920, 1123, 1326, 1530, 1733, 1936, 2139, 2342, 2545, 2747, 2952, 3155, 3358, 3561, 3746, 3967, 4171, 4374, 4577, 4780,
47, 60, 73, 86, 100, 113, 126, 139, 152, 166, 179, 192, 205, 219, 232, 245, 258, 272, 285, 298, 311,
4.7, 6.0, 7.3, 8.6, 9.9, 11.3, 12.6, 13.9, 15.2, 16.6, 17.9, 19.2, 20.5, 21.8, 23.2, 24.5, 25.8, 27.1, 28.4, 29.8, 31.1,
9.3, 12.0, 14.6, 17.3, 19.9, 22.5, 25.2, 27.8, 30.5, 33.1, 35.7, 38.4, 41.0, 43.7, 46.3, 49.0, 51.6, 54.2, 56.9, 59.5, 62.2,
5.4, 6.9, 8.4, 10.0, 11.5, 13.0, 14.5, 16.1, 17.6, 19.1, 20.6, 22.1, 23.7, 25.2, 26.7, 28.2, 29.8, 31.3, 32.8, 34.3, 35.9,
28, 36, 44, 52, 60, 68, 76, 84, 91, 99, 107, 115, 123, 131, 139, 147, 155, 163, 171, 179, 187,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7, 9, 11, 12.9, 14.9, 16.9, 18.9, 20.9, 22.8, 24.8, 26.8, 28.8, 30.8, 32.8, 34.7, 36.7, 38.7, 40.7, 42.7, 44.6, 46.6,
7.8, 10.0, 12.2, 14.4, 16.6, 18.8, 21.0, 23.2, 25.4, 27.6, 29.8, 32.0, 34.2, 36.4, 38.6, 40.8, 43.0, 45.2, 47.4, 49.6, 51.8};
int expense[] = { 0,3000,3725,4425,5150,5900,6675,7500,8350,9225,10125,11050,12025,13025,15150,17600,20375,23500,27050,31050,35575 };
struct Syw
{
	char type[20];//����
	int type_num;//����  �� �� ɳ  ��  ͷ
	char name[20];//�ܶ���
	int level;
	int num_fu;
	double value[10][3];//��.   0,0���ȼ�   0,1����������  1,0������������  1,1����������ֵ  x,0����������  x,1��������ֵ
	int flag;
}syw[40];
void initial_source();
void initial_syw();
double fu_rand(int);
int not_in(int m, int a[], int len);
int cost_(int,int);
void grow_zhu(int,int,int);
void grow_fu(int,int,int);
void show_sourse();
void show_all();
void show_done();
void show_result(int );
//�鿨
int x1()
{
	int i, j;
	int result;
	srand(time((unsigned short)0));
	show_start();
	fenqiu = rand() % 89;//�������һЩ��Դ
	yuanshi = rand() % 1280;
	jiejing = rand() % 1280;
	show_kucun();
	while (exit0 == 0)
	{
		int n, flag;
		n = show_1_or_10();
		if (n == 1)
		{
			if (fenqiu == 0)	que(1);
			if (fenqiu > 0)	fenqiu--;
			chouka();
		}
		else if (n == 10)
		{
			if (fenqiu < 10)	que(10 - fenqiu);
			if (fenqiu >= 10)	fenqiu -= 10;
			for (i = 0;i < 10;i++)
			{
				chouka();
			}
		}
		show_kucun();
		printf("\nWant to continue? Input 0 to continue\n");
		scanf("%d", &flag);
		if (flag != 0)	break;
	}
	printf("You have payed %d RMB to MYH, thanks for your contribution\n�ʶ�봽𣬿��־ͺ�\n", cost);
}
void show_start()//��Ҷ�Ŀ��أ���ʲôʱ��������������
{
	printf("Ҷ�����\n");
	printf("\n");
	printf("                          ��ԭ��Ҷup\n");
	printf("                          ��Ҷ��Ĳ�\n\n\n");
}
void show_kucun()
{
	printf("You have %d ����֮Ե(������)\n\n", fenqiu);
	printf("You have %d ԭʯ\n\n", yuanshi);
	printf("You have %d �����ᾧ\n\n\n\n", jiejing);
	printf("�Ѿ�%d��δ����\n", count);
}
int show_1_or_10()
{
	printf("��Ըһ�� press 1 \n");
	printf("��Ը10�� press 10 \n");
	int a;
	scanf("%d", &a);
	if (a == 1 || a == 10) return a;
	else show_1_or_10;
}
void wanye()//����ַ��������ܿ�����������Ҷ����ȷʵ����Ҷ�ĳ鿨����
{
	printf("HE IS COMING!!!\n");
	system("pause");
	printf("                              89                                   \n");
	printf("                              :,78     5!;gc9 }5                   \n");
	printf("                              +[ui~  5.lztqo99oy)                  \n");
	printf("    899999999>           /b} 7fqqqq,biqr*$q/  'g(                  \n");
	printf("   )l[iooooopd6          dq'9%qqqqqqx;wq^,d9   6<^^&&&*nnczzx}     \n");
	printf("   >5[eqqqqqqqpaaaaaxmnnnkqkxyqqqqq[&iqg,g6  7#iqidqqqqjcjqqqe[[k9 \n");
	printf("     65#rqqqqqqqqqqqqqqqqqqqqqqqqqo]qqqtl8>+cyqs%2hqqqqqqqqqqa@%<  \n");
	printf("        +iqqqqqqwx&{+<.sqqqqqqqqqquuqqy.*boquc){niqqqqqqqqqi!>     \n");
	printf("         4aqqqqqi>      +jqqqqqqqqqqrip[qs,*:m]wqqqqqqqqqp.6       \n");
	printf("         4&wqqqqqs$<)8    zqqqqqqqqqqwuue<@jtqqqqqqqqqwf$8         \n");
	printf("        ~egd'b[wqqqqqi/6  dqqqqqqqqqqeyyqqqqqqqqqqqqs/2            \n");
	printf("        dq!   >:$;qqqqqi%8kqqqqqqqqqqqqqqqqqqqqqqqqt'mbc~}16       \n");
	printf("        nqx       ![qqqqqpwqqqqqqqqqqqqqqqqqqqqeuwqqec/bcpqyj+     \n");
	printf("        8'r`6      >!qqrqqrqqqqqqqqqqqqqqqyirqqqwuuui'   6sqqe<    \n");
	printf("          1+4       ^aeeqt`rqqqqqqqqqqqqwz31[qqqq.(<<&&!nliqqqo8   \n");
	printf("                      ;qqrpqqqqqqqqqqqqqthduqqqqqqqqqqqqqqqqqqq:   \n");
	printf("   855559       96:*`geqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqi8   \n");
	printf("   lrrtt`7{!ch]pyeqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqw^    \n");
	printf("  ^[qqqqtyqqufhjjkjoyrqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqy^     \n");
	printf("  }!eqqqqq,142111{$feqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq]l!5 <xc  \n");
	printf("   {qqqqpx/buwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqe;bblqqqqt!>   vqq,> \n");
	printf("   4rqqq].qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqo25dqqqf1    .qqqt` \n");
	printf("    !qqqqeqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq[iqqr/>    +qqqqc8 \n");
	printf("   2%rytqqqqqqqqqrqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqo%4 6+@hrqqcvp9 \n");
	printf("  >@qq(5$p[]ln*{:4+cwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqyp[]dyqqqqqql<:9 \n");
	printf("  5jqq)  999       vqqqqqqqqqqqqqqqqqqqqqwqqqqqqqqwqqqqqqqrgggdb   \n");
	printf("   8nz2        'ssawqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqejkkb    \n");
	printf("         >^```muqqqqqqqqqqwqqqqqqwwwwqqqqqqqqqqqqqqqqqqqqqqqqqq;   \n");
	printf("         8lfffgiqqqr]]hv'qwqqqqqqwwweqqqqqpic#^)))@^^^%een^^^^^*   \n");
	printf("              6pqwb3  :gqqqeqqqqqwwwwqqix(844         $[{          \n");
	printf("             7kqy)   {,!mj<2#rqqqqwwqqf6       >    >~z5           \n");
	printf("           :lpqu{    6       ]qqqqqqqe}     7(k'> 8(df9            \n");
	printf("          6pqqr*            (eqqqqqqqp5>4*`kuqqq]diq[7             \n");
	printf("          8)v],           >#eqqqqqquqyfietqqqqqqqqqq*              \n");
	printf("             57          6,kclqqqg`@awlgpiqqqqqqqqqw}              \n");
	printf("                            *gqqs>  #e7 >5&xrqqqqqqwkc3            \n");
	printf("                 >}&>    7$dqquqv  >^q<     1dqqqqqh78>            \n");
	printf("               *'[w& >2%'uqqu~{q,  lqqn      {qqqqq%               \n");
	printf("             7bqqqqghpeqqqi.5 :q,  (zu;     :jqqqtv47              \n");
	printf("             4~$lsa[wqqrh$7   *qv    66   {leqqqq&>f+              \n");
	printf("                81$.v,<5    3^dq]       +lwqqqqqk&dy5              \n");
	printf("                 >78 *(<&&&#yqqqe/^&$@#kwqqqqqqrowqj               \n");
	printf("  *****  ��ԭ��Ҷ                                                   \n");
}
int show_duihuan(int x)
{
	printf("�Ƿ���%d�����ᾧ�һ�����ԭʯ\n", x);
	printf("ȡ��(N)       ȷ��(Y)\n");
	char c;
	getchar();
	c = getchar();
	int a;
	if (c == 'n' || c == 'N')	return 0;
	else if (c == 'y' || c == 'Y')
	{
		if (jiejing < x)
			show_kr();
		if (jiejing >= x)
		{
			jiejing -= x;
			yuanshi += x;
			printf("�����ᾧ-%d\nԭʯ+%d\n", x, x);
		}
		else {
			printf("good bye");	exit0 = 1;
		}
	}
	else show_duihuan(x);
}
void show_kr()
{
	int x = 0;;
	char c;
	while (!(x == 6 || x == 30 || x == 98 || x == 198 || x == 328 || x == 648))
	{
		printf("�������ֵ���:(6,30,98,198,328,648)\n");
		scanf("%d", &x);
	}
	printf("ȷ�ϳ�ֵ%d?\nȡ��(N)       ȷ��(Y)\n", x);
	getchar();
	c = getchar();
	if (c == 'Y' || c == 'y')
	{
		system("cls");
		show_qrcode();
		system("pause");
		//		system("cls");
		cost += x;
		jiejing += x * 10;
	}
	else if (c == 'n' || c == 'N')
	{
		printf("good bye");exit0 = 1;
	}
	else show_kr();
}
int que(int x)
{
	printf("ȱ��%d������֮Ե���Ƿ�����%dԭʯ����\n", x, x * 160);
	printf("ȡ��(N)       ȷ��(Y)\n");
	char c;
	getchar();
	c = getchar();
	if (c == 'n' || c == 'N') {
		printf("good bye");exit0 = 1;
	}
	else if (c == 'y' || c == 'Y')
	{
		if (yuanshi < x * 160)
			show_duihuan(x * 160 - yuanshi);
		if (yuanshi >= x * 160)
		{
			yuanshi -= x * 160;
			fenqiu += x;
			printf("ԭʯ-%d\n", x * 160);
			return x;
		}
		return 1;
	}
	else que;
}
void come_on_wanye(int x)//������/����/��פ/�޶�
{
	if (x == 3)	wuqi3();
	int a = rand() % 2;
	if (x == 4)
	{
		if (a == 1)	wuqi4();
		else if (a == 0)	juese4();
	}
	if (x == 5)
		if (baodi == 0)
		{
			if (a == 1)
			{
				juese5();
				baodi = 1;
			}
			else
				wanye();
		}
		else
		{
			wanye();
			baodi = 0;
		}
}
int grd_mhy(int count, int count4)//5  5�ǣ�4   4�ǣ�3  3�� 
{
	int a, b;
	if (count4 == 10)
	{
		return 4;
	}
	if (count < 70)	a = rand() % 166;
	else a = rand() % (91 - count);
	b = rand() % 20;
	if (a == 0)	return 5;
	else	if (b == 0)	return 4;
	else return 3;
}//��randд�ĸ���
void chouka()
{
	int result;
	count4++;count++;
	result = grd_mhy(count, count4);
	come_on_wanye(result);
	system("pause");
	system("cls");
	if (result == 4)	count4 = 0;
	if (result == 5)	count = 0;
}
void juese5()
{
	printf("HE IS COMING!!!");
	system("pause");
	int a = rand() % 5;
	char s[100];
	switch (a)
	{
	case 0: strcpy(s, "ĳ��ͷ���󽣾ƹ��ϰ�");break;
	case 1: strcpy(s, "ĳ���������ռ��ʦ");break;
	case 2: strcpy(s, "ĳ������ǿ����������");break;
	case 3: strcpy(s, "ĳ��ϵ˫�ֽ����ǽ�ʬ");break;
	case 4: strcpy(s, "ĳ�ؿ�������ҵ��ų�");break;
	}
	printf("\n");
	puts(s);
	//	system("pause");
}
void juese4()//����
{
	printf("\nĳ���ǽ�ɫ\n");
}
void wuqi4()
{
	printf("\nĳ��������\n");
}
void wuqi3()
{
	printf("\nĳ��������\n");
}
void show_qrcode()//����ǲʵ�
{
	int a;
	a = rand() % 5;
	char s[100];
	switch (a)
	{
	case 0: strcpy(s, "BV1FX4y1g7u8");break;
	case 1: strcpy(s, "BV1kU4y1L7Bw");break;
	case 2: strcpy(s, "BV1f54y1j7X8");break;
	case 3: strcpy(s, "BV1PN411X7QW");break;
	case 4: strcpy(s, "BV1oo4y1X7Ca");break;
	}
	printf("please whatch the video below to ��ֵ\n------->>>  %s  <<<-------\n", s);
}




//syw
int x2()
{
	srand(time((unsigned int)0));
	initial_source();
	initial_syw();
	int i,j;
	show_all();
	while (expe > 0 && money > 0)
	{
		int num_syw,lev_up,op;
		show_sourse();
		printf("ѡһ��������\n");
		scanf("%d", &num_syw);
		printf("��ĿǰΪ %d ��,�����뽫Ҫ�����ļ���( %d ~ 20)\n", syw[num_syw].level, syw[num_syw].level + 1);
		scanf("%d", &lev_up);
		printf("\n");
		int cost0 = cost_(syw[num_syw].level, lev_up);
		expe -= cost0;
		money -= cost0;
		printf("ԭ���ģ�\n");
		show_result(num_syw);
		grow_zhu(syw[num_syw].level, lev_up, num_syw);
		grow_fu(syw[num_syw].level, lev_up, num_syw);
		syw[num_syw].level = lev_up;
		printf("������\n");
		show_result(num_syw);
		printf("����ǿ���Ѿ�ǿ������  ��0����\norǿ��û��ǿ������  ��1����\nor�˳�  ��2��\n");
		scanf("%d", &op);
		{
			if (op == 2)	break;
			else if (op == 1)	show_all();
			else if (op == 0)	show_done();
		}
	}
	if (expe < 0 )	puts("û��ʥ���ﹷ����");
	if (money < 0)	puts("û��Ħ����");
}
void initial_source()
{
//	printf("%d\n", RAND_MAX );
	srand(time(0));
	const int MAX_EXP = 270475;
	expe = MAX_EXP * (rand() % 5 + 5);//��ʼ�������Ħ�����ܸ�5~10��������
	money = MAX_EXP * (rand() % 5 + 5);
	printf("���ſ��Ը� %d ��ʥ������������\n��滮����Դ\n\n", min(expe / MAX_EXP, money / MAX_EXP));
}
void initial_syw()
{
	int i;
	srand(time(0));
	for (i = 0;i < 20;i++)//!!!!!!!40
	{

		syw[i].flag = 0;//not qianghua yet
		syw[i].level = 0;//level 0

		syw[i].type_num = rand() % 5;
		strcpy(syw[i].type,Type0[syw[i].type_num]);
		strcpy(syw[i].name, Name0[rand() % 22]);
		switch (syw[i].type_num)//������
		{
		case 0: syw[i].value[1][0] = 0;break;
		case 1: syw[i].value[1][0] = 1;break;
		case 2: syw[i].value[1][0] = rand() % 5 + 5;
			if (syw[i].value[1][0] == 9)	syw[i].value[1][0] = 16;break;
		case 3: syw[i].value[1][0] = rand() % 10 + 5;break;
		case 4: syw[i].value[1][0] = rand() % 7 + 2;break;
		}
		
		syw[i].value[1][1] = zhu_num[(int)syw[i].value[1][0]][0];

		//������
		int j=2, n = rand()%2+3;
		syw[i].num_fu = n;
		int a[5];
		memset(a, 0, sizeof(a));
		while (j < 2 + n)
		{
			int m = rand() % 10;//������ѡһ��
			char s0[30];
			strcpy(s0, zhu0[(int)syw[i].value[1][0]]);
			if (strcmp(s0, fu0[m]) != 0 && not_in(m, a, j - 2))
			{
				a[j - 2] = m;
				syw[i].value[j][0] = m;
				syw[i].value[j][1] = fu_rand((int)syw[i].value[j][0]);
				j++;
			}
		}
	}
}
double fu_rand(int a)
{
	double x;
	double a0[] = { 4.1, 4.7, 5.3, 5.8 };
	double a1[] = { 14, 16, 18, 19 };
	double a2[] = { 4.1, 4.7, 5.3, 5.8 };
	double a3[] = { 209, 239, 269, 299 };
	double a4[] = { 5.1, 5.8, 6.6, 7.3 };
	double a5[] = { 16, 19, 21, 23 };
	double a6[] = { 2.7, 3.1, 3.5, 3.9 };
	double a7[] = { 5.4, 6.2, 7.0, 7.8 };
	double a8[] = { 16, 19, 21, 23 };
	double a9[] = { 4.5, 5.2, 5.8, 6.5 };
	int m = rand() % 4;
	switch (a)
	{
		case 0: x = a0[m];break;
		case 1: x = a1[m];break;
		case 2: x = a2[m];break;
		case 3: x = a3[m];break;
		case 4: x = a4[m];break;
		case 5: x = a5[m];break;
		case 6: x = a6[m];break;
		case 7: x = a7[m];break;
		case 8: x = a8[m];break;
		case 9: x = a9[m];break;
	}
	return x;
}
int not_in(int m, int a[], int len)//1:����������     0��������
{
	int i;
	for (i = 0;i < len;i++)
		if (a[i] == m)
			return 0;
	return 1;
}
int cost_(int from, int to)
{
	int sum=0;
	int i;
	for (i = from ;i <= to-1;i++)
	{
		sum += expense[i];
	}
	return sum;
}
void grow_fu(int from, int to,int num)
{
	int i;
	for (i = from + 1;i <= to;i++)
	{
		if (i % 4 == 0)
		{
			int m[5], j;
			for (j = 0;j < syw[num].num_fu;j++)
				m[j] = (int)syw[num].value[j + 2][1];
			if (syw[num].num_fu == 3)
			{	
				syw[num].num_fu++;
				int x = rand() % 10;
				char s0[30];
				strcpy(s0, zhu0[(int)syw[num].value[1][0]]);
				while (!(strcmp(s0, fu0[x]) != 0 && not_in(x, m, 3)))
					x = rand() % 10;
				syw[num].value[5][0] = x;
				syw[num].value[5][1] = fu_rand(x);
				continue;
			}
			else
			{
				int x = rand() % 4+1;
				syw[num].value[x][1] += fu_rand((int)syw[num].value[x][0]);
				continue;
			}
		}
	}
}
void show_sourse()
{
	printf("�㻹�� %d ����\n", expe);
	printf("�㻹�� %d Ħ��\n", money);
}
void grow_zhu(int from, int to,int num)
{
	syw[num].flag = 1;
	syw[num].value[1][1] = zhu_num[(int)syw[num].value[1][0]][to];
}
void show_all()
{
	int i, j;
	for (i = 0;i < 20;i++)//�������
	{
		printf("%d: %s      ", i, syw[i].name);
		puts(syw[i].type);
		printf("�ȼ���%d:\n ", syw[i].level);
		printf("��������%s : %.1f\n������:\n", zhu0[(int)syw[i].value[1][0]], syw[i].value[1][1]);
		for (j = 2;j < syw[i].num_fu + 2;j++)
			printf("%s : %.1f\n", fu0[(int)syw[i].value[j][0]], syw[i].value[j][1]);
		puts("\n");
	}
}
void show_done()
{
	int i, j;
	for (i = 0;i < 20;i++)//�������
	{
		if (syw[i].flag == 0)	continue;
		printf("%d: %s      ", i, syw[i].name);
		puts(syw[i].type);
		printf("�ȼ���%d:\n ", syw[i].level);
		printf("��������%s : %.1f\n������:\n", zhu0[(int)syw[i].value[1][0]], syw[i].value[1][1]);
		for (j = 2;j < syw[i].num_fu + 2;j++)
			printf("%s : %.1f\n", fu0[(int)syw[i].value[j][0]], syw[i].value[j][1]);
		puts("\n");
	}
}
void show_result(int i)
{
	int j;
	printf("%d: %s      ", i, syw[i].name);
	puts(syw[i].type);
	printf("�ȼ���%d:\n ", syw[i].level);
	printf("��������%s : %.1f\n������:\n", zhu0[(int)syw[i].value[1][0]], syw[i].value[1][1]);
	for (j = 2;j < syw[i].num_fu + 2;j++)
		printf("%s : %.1f\n", fu0[(int)syw[i].value[j][0]], syw[i].value[j][1]);
	puts("\n");
}





//main
int main()
{
	int x0;
	printf("�鿨orǿ��ʥ���\n�鿨  press 1;\nǿ��ʥ����  press 2\n;");
	scanf("%d", &x0);
	if (x0 == 1)
		x1();
	if (x0 == 2)
		x2();
	return 0;
}