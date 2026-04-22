#include<stdio.h>
/*
Nested if
if(condition){
if(condition){}
	}
*/

int main()
{
	int maths,che,phy,total,subtotal;
	printf("\n Enter the marks of all three subject:");
	scanf("%d %d %d",&maths,&che,&phy);
	
	if(maths>=65 && che>=60 && phy>=55)
	{
		total=maths + che + phy;
		subtotal=maths +phy;
		if(subtotal>=145 || total>=190)
		{
			printf(" \n Eligible for admission");
		}
		else
		{
			printf("\n Inner Loop Exits");
		}
	}
		else
		{
			printf("\n Outer Loop Exits");	
		}
	
}