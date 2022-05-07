#include<stdio.h>
s
//二分查找递归实现
int count=0;//全局变量，记录查找次数
int recBinFind(int b[],int key,int low, int high)
{
    int mid;
    if(low>high)
        return -1;//递归出口，没有可以查找的元素>?>=
    count++;//查找次数
    mid = (low+high)/2;
    if(key == b[mid])
        return mid;//找到了，退出;对于double类型，fabs(key-b[mid])<eps
    else if(key > b[mid])
        return recBinFind(b,key,mid+1,high);//用mid也行，应该不行 
    else 
        return recBinFind(b,key,low,mid-1);
}
