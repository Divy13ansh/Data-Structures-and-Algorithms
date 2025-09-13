#include<stdio.h>

int findOddCountElem(int arr1[], int n){
    int i, resultXOR = 0;

    for(int i = 0;i<n;i++){
        resultXOR = resultXOR ^ arr1[i];
    }
    return resultXOR;

}

void main(){
    int i;
    int arr1[] = {8,3,8,5,4,3,4,3,5};
    int ctr = sizeof(arr1)/sizeof(arr1[0]);

    printf("Given array: \n");
    for(int i=0;i<ctr;i++){
        printf("%d\t",arr1[i]);
    }
    printf("\n");

    printf("Number of odd number occurs: %d times. \n", findOddCountElem(arr1,ctr));

}
