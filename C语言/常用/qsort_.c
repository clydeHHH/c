#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//using namespace std;
int cmp(const void* a,const void* b)//有溢出的风险 
{
	return *(int*)a-*(int*)b;
}
int cmp(const void* a,const void* b)
{
	*a1 = (int*)a;
	*b1 = (int*)b;
	if(*a1<*b1)	return -1;
	else return 1;
}
int cmp(const void* a,const void *b)//更简洁 !!!!
{
	return *(int * )a > *(int*)b ? 1:-1;
}
int cmp_char (const void* a,const void* b)
{
	return *(char*)a - *(char*)b;
}
int cmp_double (const void* a,const void* b)//不能用减法 
{
	return *(double*)a > *(double*)b ? 1: -1;
}
int cmp_string (const void* a,const void* b)
{
	return strcmp((int*)a,(int*)b);
}

int main()
{
	double a[]={20.5,8.4,5,5.7,2.0,-271};
	qsort(a,6,sizeof(a[0]),cmp_double);
	int i;
	for(i=0;i<6;i++)
		printf("%f ",a[i]);
}
