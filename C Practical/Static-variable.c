#include<stdio.h>
void incre(){
	int a=0;
	static int s=0;
	a++;
	s++;
	printf("\n a=%d and s=%d",a,s);
}
int main(){
	int i;
	for(i=1;i<=3;i++){
		incre();
	}
}