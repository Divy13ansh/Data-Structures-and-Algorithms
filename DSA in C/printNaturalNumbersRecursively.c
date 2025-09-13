#include<stdio.h>

int numPrint(int);

void main(){
    int n = 1;
    printf("\n\n Recursion: print first 50 natural no.s\n");
    printf("The natural no.s are: \n");
    numPrint(n);
    printf("\n\n");
}

int numPrint(int n){
    if(n <= 50){
        printf(" %d ", n);
        numPrint(n+1);
    }
}
