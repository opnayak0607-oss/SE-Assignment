#include<stdio.h>
int main(){
	int x1,x2,x3;
	printf("\n Enter value of x1 x2 x3 : ");
	scanf("\n %d %d %d",&x1,&x2,&x3);
	
	if(x1>x2 && x1>x3){
		printf("\n A is largest");
	}
	else if(x2>x3 && x2>x3){
		printf("\n B is Largest");
	}
	else if(x3>x1 && x3>x2)
	{
		printf("\n C is largest");
	}
	else{
		printf("\n All are same");
	}
	return 0;
}