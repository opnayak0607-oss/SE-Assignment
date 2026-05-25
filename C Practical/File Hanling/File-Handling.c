#include<stdio.h>
int main(){
	FILE *fp;
	char data[10];
	fp= fopen("hello.txt","w");
	fprintf(fp,"%s","hello world");
	fclose(fp);
	
	fp = fopen("hello.txt","r");
	fgets(data,13,fp);
	printf("\n reading data from file=%s",data);
	fclose(fp);
}