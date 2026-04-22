#include<stdio.h>
int main(){
	int a[5];
	int i,sum=0;
	
	printf("\n Interger array\n");
	for(i=0;i<5;i++){
		printf("\n Enter a[%d]",i);
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	for(i=0;i<5;i++){
		printf("\n a[%d]=%d",i,a[i]);
	}
	printf("\n Addition of Array element =%d",sum);
}