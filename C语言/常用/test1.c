#include<string.h>
#include<stdio.h>
int main(){
    
	long long a,b,d=0;
	long long a1[64]={0},b1[64]={0},c[64]={0},i=1;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		for(i=0;i<64;i++){
			a1[i]=(a&1);
			b1[i]=(b&1);
			a=(a>>1);
			b=(b>>1);
		}
		for(i=0;i<64;i++){
			if((a1[i]==0)&&(b1[i]==1))
			c[i]=0;
			else
			c[i]=1;
		}
		for(i=0;i<64;i++){
			d+=(c[i]<<i);
		}
		printf("%lld\n",d);
		d=0;
	}
	return 0;
}
