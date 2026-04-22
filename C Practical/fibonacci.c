#include<stdio.h>
int main(){
	int x1=0,x2=1,ans,i;
	printf("\n %d \t%d",x1,x2);
	for(i=1;i<=10;i++){
		ans=x1+x2;
		printf("\t %d",ans);
		x1=x2;
		x2=ans;
	}
	return 0;
}