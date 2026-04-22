#include<stdio.h>
int main()
{
	int num;
	printf("Enter a Num: \t");
	scanf("%d",&num);
	if(num%2==0){
		printf("\n Even");
	}
	else{
		printf("\n Odd");
	}
	return 0;
}