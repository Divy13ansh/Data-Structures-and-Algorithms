#include<stdio.h>
long int power(int x,int y){
    long int result = 1;
    if(y==0) return result;
    result = x*(power(x,y-1));
}
void main(){
    int bNum, pwr;
    long int result;

    printf("Input the base value: ");
    scanf("%d",&bNum);
    printf("Input the power: ");
    scanf("%d", &pwr);

    result = power(bNum,pwr);
    printf("the value of %d to the power %d is %d", bNum, pwr, result);
}
