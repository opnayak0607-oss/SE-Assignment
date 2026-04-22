#include<stdio.h>
int main()
{
	char ch;
	printf("\n Enter Character : ");
	scanf("%c",&ch);
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
		printf("\n  Vowel");
	}
	else if(ch>='a' && ch<='z'){
		printf("\n Constant");
	}
	else{
		printf("\n Error");
	}
	return 0;
}
	