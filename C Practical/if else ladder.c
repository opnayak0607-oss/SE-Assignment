#include<stdio.h>
int main(){
	int x1,x2;
	printf("\n Enter teh num x1 and x2:");
	scanf("%d %d",&x1,&x2);
	
	if(x1>0 && x2>0)
	{
		printf("\n First");	
	}
	else if(x1>0 && x2<0)
	{
		printf("\n sec");	
	}
	else if(x1<0 && x2<0)
	{
		printf("\n First");	
	}
	else if(x1<0 && x2>0)
	{
		printf("\n First");	
	}
	
	else
	{
		printf("\n Center");	
	}
}