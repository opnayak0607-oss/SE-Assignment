#include<stdio.h>
main(){
int num=10;
int *ptr;
ptr=&num;
printf("Orignalvalueis%d.\n",num);
*ptr=50;
printf("Modifiedvalueis%d.\n",num);
}