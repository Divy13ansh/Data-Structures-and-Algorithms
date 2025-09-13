#include<stdio.h>

void hailstone(int num){
    printf("%d\t",num);
    if(num == 1){
        return;
    }
    if(num % 2 == 0){
        num = num/2;
    }
    else{
        num = (3 * num) + 1;
    }
    hailstone(num);
}

void main(){
    int n;
    printf("Enter your no.: ");
    scanf("%d",&n);
    hailstone(n);
}
