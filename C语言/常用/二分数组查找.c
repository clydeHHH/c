#include<stdio.h>
s
//���ֲ��ҵݹ�ʵ��
int count=0;//ȫ�ֱ�������¼���Ҵ���
int recBinFind(int b[],int key,int low, int high)
{
    int mid;
    if(low>high)
        return -1;//�ݹ���ڣ�û�п��Բ��ҵ�Ԫ��>?>=
    count++;//���Ҵ���
    mid = (low+high)/2;
    if(key == b[mid])
        return mid;//�ҵ��ˣ��˳�;����double���ͣ�fabs(key-b[mid])<eps
    else if(key > b[mid])
        return recBinFind(b,key,mid+1,high);//��midҲ�У�Ӧ�ò��� 
    else 
        return recBinFind(b,key,low,mid-1);
}
