#include<math.h>
{
	  double fabs(double);//求实型的绝对值
  double fmod(double,double);//返回两参数相除的余数
  double remainder(double,double);//计算浮点除法运算的带符号余数
  double fmax(double,double);//确定两个浮点值的较大者
  double fmin(double,double);//确定两个浮点值的较小者
  double fdim(double,double);//确定两个浮点值的非负数差
  
    double exp(double);//求取自然数e的幂
  double exp2(double);//求取2的幂
  double log(double);//以e为底的对数
  double log10(double);//以10为底的对数
  double log2(double);//以2为底的对数
  
    double pow(double x,double y);//计算x的y次幂
  double sqrt(double);//开平方根
  double cbrt(double);//开立方根
  double hypot(double x,double y);已知直角三角形两个直角边长度，求斜边长度
  
  double sin(double);//正弦
  double cos(double);//余弦
  double tan(double);//正切
  double asin(double);//结果介于[-PI/2,PI/2]
  double acos(double);//结果介于[0,PI]
  double atan(double);//反正切（主值），结果介于[-PI/2,PI/2]
  double atan2(double,double);//反正切（整圆值），结果介于[-PI,PI]
  
    double sinh(double);
  double cosh(double);
  double tanh(double);
  double asinh(double);
  double acosh(double);
  double atanh(double);
  
    double erf(double);//计算误差函数
  double erfc(double);//计算补误差函数
  double tgamma(double);//计算伽马函数
  double lgamma(double);//计算伽马函数的自然对数
  
    double ceil(double);//取上整，返回不比x小的最小整数
  double floor(double);//取下整，返回不比x大的最大整数，即高斯函数[x]
  double trunc(double);//取整到绝对值不大于给定值的最接近整数
  double round(double);//取整到最接近的整数，在相邻整数正中间时取远离零的数
  
    double frexp(double value,int *exponent);//标准化浮点数，value=x*2^exponent，已知 value 求 x,exponent
  //把浮点数分解成尾数和指数。返回值是尾数，并将指数存入 exponent 中。
  //其中尾数 x 取值在 (-1, -0.5] 或 [0.5, 1) 或 0。
  double ldexp(double x,int exponent);//计算x（2的指数幂），已知 x,exponent 求f
  //这个函数刚好跟上面那个frexp函数功能相反，它的返回值是x倍的2的指数幂
  double modf(double value,double *iptr);//拆分value值，返回它的小数部分，iptr指向整数部分。
}
