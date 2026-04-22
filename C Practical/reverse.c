#include<stdio.h>
int main(){
	int num,rem,rev;
	printf("\n Enter num:");
	scanf(" %d",&num);
	while(num !=0){
		
		rem=num%10;
		rev=rev*10+rem;
		//printf("\n rem=%d rev=%d",rem,rev);
		num = num/10;
	}
	printf("\n %d",rev);
	
	return 0;
}