#include<stdio.h>
int main()
{
	int i,j,k,col,row;
	printf("\n Enter a row and col :");
	scanf("%d %d",&row,&col);
	if(row == col){

	for(i=1;i<=row;i++)
	{
		for(k=col;k>=i;k--){
			printf("  ");
		}
		for(j=1;j<=i;j++){
			printf("* ");
		}
		printf("\n");
	}
}
else
{
	printf("\n Enter a Valid num");
}
	return 0;
}