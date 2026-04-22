#include<stdio.h>
int main(){
	int x,y;
	char choice;
	printf("\n Enter + for ADD");
	printf("\n Enter - for SUB");
	printf("\n Enter * for MUL");
	printf("\n Enter / for DIV");
	
	printf("\n Enter your choice : ");
	scanf(" %c",&choice);
	
	printf("\n Enter x & y:");
	scanf("%d %d",&x,&y);
	
	switch(choice){
		case '+':
		printf("\n ADD of %d and %d= %d",x,y,x+y);
		break;
		case '-':
		printf("\n SUB of %d and %d= %d",x,y,x-y);
		break;
		case '*':
		printf("\n MUL of %d and %d= %d",x,y,x*y);
		break;
		case '/':
		printf("\n DIV of %d and %d= %d",x,y,x/y);
		break;
		default:
			printf("\n Invalid choice");
			break;
	}	
}