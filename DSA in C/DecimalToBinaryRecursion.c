#include<stdio.h>

long convertBinary(int);

void main(){
    long biNo;
    int decNo;

    printf("Enter any decimal no.: ");
    scanf("%d",&decNo);
    biNo = convertBinary(decNo);
    printf("The Binary value of decimal no. %d is: %ld\n\n", decNo, biNo);

}

long convertBinary(int decNo){
    static long biNo, r, fctor = 1;

    if(decNo != 0){
        r = decNo % 2;
        biNo = biNo + r*fctor;
        fctor = fctor * 10;
        convertBinary(decNo/2);
    }
    return biNo;
}