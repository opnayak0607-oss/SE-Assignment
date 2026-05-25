#include<stdio.h>
//without returntype without parameter
void printMsg(){
	printf("\n hello world");
}
//without returntype with parameter
void add(int a, int b){
	int c=a+b;
	printf("\n addition=%d",c);
}
//with returntype with parameter
int square(int num){
	int s;
	s=num*num;
	return s;
}
//with returntype without parameter
float areaOfCircle(){
	int r;
	float area;
	printf("\n Enter the value of r");
	scanf("%d",&r);
	area= 3.14*r*r;
	return area;
}
main(){
	printMsg();
	add(12,45);
	int s= square(12);
	printf("\n square =%d",s);
	float a= areaOfCircle();
	printf("\n area of circle =%f",a);
}