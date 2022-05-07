#include<stdio.h>
#include<math.h>
#define EPS 1e-13
double cul(double x)//表达式，计算函数 
{
	return x*x;
}
int is0(double x)//是否接近0  是返回1，否返回0 
{
	x = fabs(x);
	return (x<EPS);
}
double erfenSolve(double high,double low, double key)//单增函数  
{
	double mid = (high+low)/2;
	double ans = cul(mid);
	if(is0(ans-key))	return mid;
	if(ans<key)	erfenSolve(high,mid,key);	//单减修改为> 
	else erfenSolve(mid,low,key);
}
int main()
{
	double key;
	double ans;
	scanf("%lf",&key);
	ans = erfenSolve(2000.0,0.0,key);
	printf("%f",ans);
	return 0;
}
