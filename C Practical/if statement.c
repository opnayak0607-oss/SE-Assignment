#include<stdio.h>
/*
	if(condition){
	//block
    }
*/
// Square of positive num 
int main(){
	int num;
	printf("\n Enter a values of num:");
	scanf("%d",&num);
	if(num>0){
		printf("\n square of %d=%d",num,num*num);
	}
}