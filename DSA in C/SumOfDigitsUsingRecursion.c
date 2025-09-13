#include<stdio.h>

int sumOfDigits(int n1);

void main(){
    int n1;
    printf("Enter Number You want sum of digits for: ");
    scanf("%d", &n1);
    printf("%d",sumOfDigits(n1));
}

int sumOfDigits(int n1){
    static int sum = 0;
    if (n1>0){
        sum+=n1%10;
        sumOfDigits(n1/10);
    }
    else{
        return sum;
    }


}
