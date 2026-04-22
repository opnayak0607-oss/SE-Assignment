#include<stdio.h>
/*
	if(condition){
	//block
    }
    else{
	//block
	}
*/

// To find whether the num is odd or even
int main(){
	int age;
	printf("\n Enter the age:");
	scanf("\n %d",&age);
	if(age>=18){
		printf("\n Able to Vote");
	}
	else{
		printf("\n Not able to vote");
	}
	return 0;
}