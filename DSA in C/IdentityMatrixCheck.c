#include<stdio.h>

void main(){
    int arr[10][10];
    int r,c;
    int yn = 1;

    printf("Input the no. of rows in the matrix: \n");
    scanf("%d",&r);

    printf("Input the no. of cols in the matrix: \n");
    scanf("%d",&c);

    printf("Enter the elements in the matrix: \n");

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            printf("Enter element - [%d][%d]",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The matrix is: \n");
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
                printf("%4d",arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if((i == j && arr[i][j] != 1) || (i!=j && arr[i][j] != 0)){
                yn = 0;
                break;
            }
        }
    }
    if(yn == 1)
        printf("Matrix is identity matrix");
    else
        printf("Matrix is not identity matrix");

}

