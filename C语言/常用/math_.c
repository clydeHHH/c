#include<math.h>
{
	  double fabs(double);//��ʵ�͵ľ���ֵ
  double fmod(double,double);//�������������������
  double remainder(double,double);//���㸡���������Ĵ���������
  double fmax(double,double);//ȷ����������ֵ�Ľϴ���
  double fmin(double,double);//ȷ����������ֵ�Ľ�С��
  double fdim(double,double);//ȷ����������ֵ�ķǸ�����
  
    double exp(double);//��ȡ��Ȼ��e����
  double exp2(double);//��ȡ2����
  double log(double);//��eΪ�׵Ķ���
  double log10(double);//��10Ϊ�׵Ķ���
  double log2(double);//��2Ϊ�׵Ķ���
  
    double pow(double x,double y);//����x��y����
  double sqrt(double);//��ƽ����
  double cbrt(double);//��������
  double hypot(double x,double y);��ֱ֪������������ֱ�Ǳ߳��ȣ���б�߳���
  
  double sin(double);//����
  double cos(double);//����
  double tan(double);//����
  double asin(double);//�������[-PI/2,PI/2]
  double acos(double);//�������[0,PI]
  double atan(double);//�����У���ֵ�����������[-PI/2,PI/2]
  double atan2(double,double);//�����У���Բֵ�����������[-PI,PI]
  
    double sinh(double);
  double cosh(double);
  double tanh(double);
  double asinh(double);
  double acosh(double);
  double atanh(double);
  
    double erf(double);//��������
  double erfc(double);//���㲹����
  double tgamma(double);//����٤����
  double lgamma(double);//����٤��������Ȼ����
  
    double ceil(double);//ȡ���������ز���xС����С����
  double floor(double);//ȡ���������ز���x����������������˹����[x]
  double trunc(double);//ȡ��������ֵ�����ڸ���ֵ����ӽ�����
  double round(double);//ȡ������ӽ����������������������м�ʱȡԶ�������
  
    double frexp(double value,int *exponent);//��׼����������value=x*2^exponent����֪ value �� x,exponent
  //�Ѹ������ֽ��β����ָ��������ֵ��β��������ָ������ exponent �С�
  //����β�� x ȡֵ�� (-1, -0.5] �� [0.5, 1) �� 0��
  double ldexp(double x,int exponent);//����x��2��ָ���ݣ�����֪ x,exponent ��f
  //��������պø������Ǹ�frexp���������෴�����ķ���ֵ��x����2��ָ����
  double modf(double value,double *iptr);//���valueֵ����������С�����֣�iptrָ���������֡�
}
