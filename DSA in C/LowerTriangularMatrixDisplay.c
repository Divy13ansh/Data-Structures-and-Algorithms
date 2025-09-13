#include<stdio.h>

void main(){
    int arr[10][10],n;

    printf("Input the size of matrix: ");
    scanf("%d",&n);

    printf("Input elements in the matrix:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("element [%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The matrix is: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            if(i<=j){
                printf("%4d",arr[i][j]);
            }
            else{
                printf("%4d",0);
            }
        }
    }


}

