#include<stdio.h>
int main(){
	int x1,x2;
	printf("\n Enter x1 and x2:");
	scanf("\n %d %d",&x1,&x2);
	if(x1>x2){
		printf("\n x1 is largest");
	}
	else if(x2>x1){
		printf("\n x2 is largest");
	}
	else{
		printf("\n Equal");
	}
	return 0;
}