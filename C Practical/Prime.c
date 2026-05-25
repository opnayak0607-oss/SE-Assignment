#include<stdio.h>
int main(){
	int num,i,flag=0;
	printf("\n Enter Num:");
	scanf("%d",&num);
	if(num<2){
	 printf("\n Enter a valid num");
	}
	else{	
	for(i=2;i<=num/2;i++){
		if(num % i==0){
			flag=1;
		}
	}
}
(flag==0)?printf("\n Prime"):printf("\n Not Prime");
	return 0;
}