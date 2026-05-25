#include<stdio.h>
union Fruit{
	char name[10];
	float price;
	int qty;
}f;
main(){
	printf("\n Enter fruits qty name price");
	scanf(" %d %c %f",&f.qty,f.name,&f.price);
	scanf("%s",f.name);
	printf("\n fruits name=%s",f.name);
}