#include<stdio.h>

int sumOfRange(int);
void main(){
    int n1,sum;
    printf("Input the last no. of range starting from 1: ");
    scanf("%d",&n1);
    sum = sumOfRange(n1);
    printf("\n The sum of numbers from 1 to %d is %d\n\n", n1,sum);
}

int sumOfRange(int n1){
    int res;
    if(n1==1){
        return(1);
    }
    else{
        res = n1 + sumOfRange(n1-1);
    }
    return res;
}
