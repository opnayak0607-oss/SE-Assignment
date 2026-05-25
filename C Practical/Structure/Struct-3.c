#include<stdio.h>
struct description{
	char mname[10];
};
struct Description{
	char color[10];
	char Brand[10];
	struct Materials m1;
};

struct Product{
	int pid;
	char pname[10];
	struct description d1;
};
int main(){
	struct Product p1;
	printf("\n Enter pid and pname");
	scanf("%d %s",&p1.pid,p1.pname);
	printf("\n enter color and brand mname");
	scanf("%s %s %s",p1.d1.color,p1.d1.Brand,p1.d1.m1.mname);
	
	printf("\n product details\n");
	printf("\n pid=%d productname=%s",pi.pid,p1.pname);
	printf("\n color=%s brand=%s",p1.d1.color,p1.d1.Brand);
	printf("\n mname=%s",p1.d1.m1.mname);
}