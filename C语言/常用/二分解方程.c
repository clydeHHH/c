#include<stdio.h>
#include<math.h>
#define EPS 1e-13
double cul(double x)//���ʽ�����㺯�� 
{
	return x*x;
}
int is0(double x)//�Ƿ�ӽ�0  �Ƿ���1���񷵻�0 
{
	x = fabs(x);
	return (x<EPS);
}
double erfenSolve(double high,double low, double key)//��������  
{
	double mid = (high+low)/2;
	double ans = cul(mid);
	if(is0(ans-key))	return mid;
	if(ans<key)	erfenSolve(high,mid,key);	//�����޸�Ϊ> 
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
