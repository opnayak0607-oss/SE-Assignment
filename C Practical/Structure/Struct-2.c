#include<stdio.h>
struct Fruits{
	int fno;
	char fname[30];
	float price;
};
int main(){
	struct Fruits f[5];
	int i;
	for(i=0;i<3;i++){
	printf("\n Enter fruits no nmae price of fruits :%d",i+1);
	scanf("%d %s %f",&f[i].fno,f[i].fname,&f[i].price);
}
  printf("\n fruitno fruitname fruitprice");
     for(i=0;i<3;i++){
	printf("\n %d %s %f",f[i].fno,f[i].fname,f[i].price);
}
}