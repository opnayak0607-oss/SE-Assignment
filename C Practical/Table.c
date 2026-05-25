#include<stdio.h>
int main(){
	int num1,i,num2,j,k,num3;
	printf("\n enter Num ");
	scanf("%d",&num1);
	printf("\n enter Num ");
	scanf("%d",&num2);
	
		for(i=1;i<=10;i++)
		{
			for(j=1;j<=10;j++)
			{
				printf("\t %d  *%d  =  %d",j,i,j*i);
			}
			printf("\n");
		}
		
}