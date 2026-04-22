#include<stdio.h>
int main()
{
	int choice;
	do
	{
		printf("\n1.Say hello");
		printf("\n2.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			printf("Hello!\n");
		}
	}
	while(choice!=2);
	return 0;
}