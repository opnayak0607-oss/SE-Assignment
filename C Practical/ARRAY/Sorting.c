#include<stdio.h>
int main(){
	int arr[5],i,j,temp;
	printf("\n Enter num:");
	for(i=0;i<5;i++)
	{
	scanf("%d",&arr[i]);
	}
	for(i=0;i<5-1;i++)
{
		for(j=0;j<5-1-i;j++)
	{
		if(arr[j]>arr[j+1])
		{
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
		}
	}
}

	//printf("Sorting:\n);
	for(i=0;i<5;i++){
		printf("%d",arr[i]);
	}
	return 0;
}