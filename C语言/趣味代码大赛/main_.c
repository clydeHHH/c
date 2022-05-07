/*
*@姓名：
*@学号114514
*@作品名称
《总有地上的生灵敢于直面雷霆的微光》    又名《我好想做万叶的狗》
*@版本1.0
*@提交日期 2022-4-24
* 
*@输入
按提示输入即可
*@输出
抽卡结果，有字符串，字符画，还有小彩蛋

*@功能说明
模拟原神的抽卡，支持氪金等。有多种结果，可以多试几次
给视频加一个bgm不过分吧（doge


*@补充说明
有可能会有更加完善的版本，也有可能没了
如果有冒犯到你喜欢的角色，见谅。

*@参考来源
生成字符画用的python,参考https://blog.csdn.net/Wmayy_123/article/details/106376675
还参考了其他几篇帖子，要么效果不好，要么只能输出图片，具体py代码见附件
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<windows.h>
int cost = 0;//有些变量是拼音的
int fenqiu = 0;
int yuanshi = 0;
int jiejing = 0;
int exit0 = 0;
int baodi = 0;
int count = 0, count4 = 0;
void show_start();//函数的命名有点混乱，懒得改了
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
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
int main()
{
	int i, j;
	int result;
	srand(time((unsigned short)0));
	show_start();
	fenqiu = rand() % 89;//随机给你一些资源
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
	printf("You have payed %d RMB to MYH, thanks for your contribution\n适度氪金，快乐就好\n", cost);
}
void show_start()//万叶的卡池，他什么时候来啊，呜呜呜
{
	printf("叶落风随\n");
	printf("\n");
	printf("                          枫原万叶up\n");
	printf("                          红叶逐荒波\n\n\n");
}
void show_kucun()
{
	printf("You have %d 纠缠之缘(粉球球)\n\n", fenqiu);
	printf("You have %d 原石\n\n", yuanshi);
	printf("You have %d 创世结晶\n\n\n\n", jiejing);
	printf("已经%d抽未出金\n", count);
}
int show_1_or_10()
{
	printf("祈愿一次 press 1 \n");
	printf("祈愿10次 press 10 \n");
	int a;
	scanf("%d", &a);
	if (a == 1 || a == 10) return a;
	else show_1_or_10;
}
void wanye()//输出字符画，可能看不出来是万叶，但确实是万叶的抽卡动画
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
	printf("  *****  枫原万叶                                                   \n");
}
int show_duihuan(int x)
{
	printf("是否用%d创世结晶兑换等量原石\n", x);
	printf("取消(N)       确认(Y)\n");
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
			printf("创世结晶-%d\n原石+%d\n", x, x);
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
		printf("请输入充值金额:(6,30,98,198,328,648)\n");
		scanf("%d", &x);
	}
	printf("确认充值%d?\n取消(N)       确认(Y)\n", x);
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
	printf("缺少%d个纠缠之缘，是否消耗%d原石购买\n", x, x * 160);
	printf("取消(N)       确认(Y)\n");
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
			printf("原石-%d\n", x * 160);
			return x;
		}
		return 1;
	}
	else que;
}
void come_on_wanye(int x)//出人物/武器/常驻/限定
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
int grd_mhy(int count, int count4)//5  5星，4   4星，3  3星 
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
}//用rand写的概率
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
	case 0: strcpy(s, "某红头发大剑酒馆老板");break;
	case 1: strcpy(s, "某交不起房租的占星师");break;
	case 2: strcpy(s, "某即将加强的璃月雷神");break;
	case 3: strcpy(s, "某冰系双手剑但是僵尸");break;
	case 4: strcpy(s, "某关可莉禁闭室的团长");break;
	}
	printf("\n");
	puts(s);
//	system("pause");
}
void juese4()//摆了
{
	printf("\n某四星角色\n");
}
void wuqi4()
{
	printf("\n某四星武器\n");
}
void wuqi3()
{
	printf("\n某三星武器\n");
}
void show_qrcode()//这就是彩蛋
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
	printf("please whatch the video below to 充值\n------->>>  %s  <<<-------\n", s);
}
