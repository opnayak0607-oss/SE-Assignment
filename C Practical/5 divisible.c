#include<stdio.h>
int main()
{
	int num;
	printf("Enter a Num: \t");
	scanf("%d",&num);
	if(num%5==0){
		printf("\n Divisible");
	}
	else{
		printf("\n Not divisible");
	}
	return 0;
}