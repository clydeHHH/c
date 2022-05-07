#include<stdio.h>

long long gcd(long long a,long long b)
{
	if(b==0)	return a;
	long long r;
	for(r = a%b;r!=0;r = a%b)
	{
		a = b;
		b = r;
	}
	return b < 0 ? -b : b;
}


long long lcm2(long long a,long long b)//两个数的 
{
	return a*b/gcd(a,b);
}

long long lcm(long long a,long long b,long long c)//三个数的 
{
	long long lcm_=lcm2(a,b);
	return lcm_*c/gcd(lcm_,c);
}
int main()
{
	long long a,b;
	
}
