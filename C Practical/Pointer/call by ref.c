#include<stdio.h>
//call by ref
void swap(int *a,int *b){
	int temp=*a;//10
	*a=*b;
	*b=temp;

}
int main(){
	int a,b;
	printf("\n Enter a and b:");
	scanf("%d %d",&a,&b);
	swap(&a,&b);
	printf("\n a=%d and b=%d",a,b);	
}