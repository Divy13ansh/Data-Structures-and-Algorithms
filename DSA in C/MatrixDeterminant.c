#include<stdio.h>

void main(){
    int arr[3][3];
    int det = 0;

    printf("Input elements in matrix: \n");
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            printf("Enter element - [%d][%d]: ",i,j);
            scanf("%d",%arr[i][j]);
        }
    }

    printf("The matrix is :\n");
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            printf("%4d",arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0;i<3;i++){
        det += arr[0][i] * arr[1]
    }





}

