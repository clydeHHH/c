#include<stdio.h>
void bubbleSort_double(double a[],int n)//ÉýÐò 
{
	int i,j,flag;
	double temp;
	for(i=1;i<n;i++)
	{
		flag = 0;
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		if(flag == 0)	break;
	}
}

void BubbleSort(int a[],int n)//ÉýÐò
{
    int i,j,temp,flag;
    for(i = 0;i<n-1;i++)
    {
       flag = 0;
       for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        if(flag==0)	break;
    }    
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	double x[20];
	for(i=0;i<n;i++)
		scanf("%lf",&x[i]);
	bubbleSort_double(x,n);
	for(i=0;i<n;i++)
		printf("%.4f\n",x[i]);
}
