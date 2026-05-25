
#include<stdio.h>
int main(){
	char str[10],rev[10];
	int i=0,counter=0,j,l=0;
	printf("\n Enter string");
	scanf("%s",str);
//  gets(str);
while(str[i] != '\0')
	{
		counter++;
		i++;
	}
		printf("\n length of str=%d i=%d",counter,i);
			i--;
			j=i;
while(j >= 0)
	{
	rev[l]=str[j];
		printf("\n str[%d]=%c rev[%d]=%c",j,str[j],l,rev[l]);
		l++;
		 j--;
	
	}
}

	
