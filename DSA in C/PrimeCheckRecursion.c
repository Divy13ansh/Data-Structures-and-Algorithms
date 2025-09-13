#include<stdio.h>

int checkForPrime(int);
int i;

void main(){
    int n1, primeNo;
    printf("Enter a positive no.: ");
    scanf("%d",&n1);
    i = n1/2;
    primeNo = checkForPrime(n1);
    if(primeNo==1){
        printf("The number %d is a prime no.\n",n1);
    }
    else{
        printf("The number %d is not a prime no. \n",n1);
    }
}

int checkForPrime(int n1){
    if(i==1){
        return 1;
    }
    else if(n1 % i == 0){
        return 0;
    }
    else{
        i = i-1;
        checkForPrime(n1);
    }
}
