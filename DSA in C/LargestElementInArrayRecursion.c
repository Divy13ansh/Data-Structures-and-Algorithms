#include<stdio.h>

int max_no(int arr[],int n,int max){
    static int i=0;
    if(i<n){
        if(arr[i]>max){
            max = arr[i];
        }
        i++;
        max_no(arr,n,max);
    }
    else{
        return max;
    }
}

void main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",&arr[i]);
    }
    int z = max_no(arr,n,arr[0]);
    printf("%d",z);
}
