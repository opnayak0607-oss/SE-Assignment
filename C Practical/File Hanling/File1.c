#include<stdio.h>
struct fruit{
	char name[10];
	float price;
	int qty;
	float stotal;
}f[5];
int main(){
	int i;
	char ch;
	FILE *fp;
	fp = fopen("fruitlist.csv","a");
	for(i=0;i<=2;i++){
		printf("\n Enter fruits qty name price : ");
		scanf("%d %s %f",&f[i].qty,f[i].name,&f[i].price);
		f[i].stotal=f[i].qty*f[i].price;
		fprintf(fp,"%s %f %d %f",f[i].name,f[i].price,f[i].qty,f[i].stotal);
	}
	fclose(fp);
	fp = fopen("fruitlist.csv","r");
	while((ch = fgetc(fp))!=EOF){
		if(ch == ','){
			printf("\t");
			continue;
		}
		printf("%c",ch);
	}
	fclose(fp);
}