#include<stdio.h>
int main(){
	int a[5];
	int i;
	char ch[5];
	float x[5];
	printf("\n char array");
	for(i=0;i<5;i++){
		printf("\n Enter char[%d]",i);
		scanf(" %c",&ch[i]);
	}
	for(i=0;i<5;i++){
		printf("\n ch[%d]=%c",i,ch[i]);
	}
}