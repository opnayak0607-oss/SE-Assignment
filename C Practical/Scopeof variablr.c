#include<stdio.h>
float pi=3.14;
void test()
{
	printf("\n Global variable in function pi=%f",pi);
}
void add(int a,int b){
	int c=a+b;
	printf("\n addition=%d",c);
}
int main(){
	int x=10;
	
	{
		int y=90;
		printf("\n y=%d",y);
	}
	printf("\n Global variable pi=%f",pi);
	test();
	add(10,20);
}
