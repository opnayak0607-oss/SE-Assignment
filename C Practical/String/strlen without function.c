#include<stdio.h>
/*

tops
t i=0 1
0 i=1 2
p i=2 3
s i=3 4
\0 i=4
}
*/
int main(){
	char str[10];
	int i=0,counter=0;
	printf("\n Enter string");
	scanf("%s",str);
//  gets(str);
while(str[i] != '\0'){
	counter++;
	i++;
}
printf("\n length of str=%d",counter);
}
	