#include<stdio.h>
#include<string.h>
int main(){
	char str[10]="omprasad";
	printf("\n len of str=%d",strlen("tops"));
	printf("\n str concat=%s",strcat(str," nayak"));
	strupr(str);
	printf("\n upper case=%s",str);
	strrev(str);
	printf("\n rev str=%s",str);
	// strlwr(str);
	printf("\n strcmp=%d",strcmp("abc","abc"));
}