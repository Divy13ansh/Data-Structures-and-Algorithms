#include<stdio.h>

void main(){
    int arr[10][10];
    int r,c;
    int ctr = 0;
    printf("Input no. of rows: ");
    scanf("%d",&r);

    printf("Input no. of cols: ");
    scanf("%d",&c);

    printf("Input elements in the matrix: \n");
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            printf("Enter element at - [%d][%d]\n",i,j);
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 0){
                ctr++;
            }
        }
    }

    if(ctr > r*c/2){
        printf("The given matrix is a sparse matrix\n");
    }
    else{
        printf("The given matrix is not a sparse matrix\n");
    }

    printf("There are %d zeros in the matrix\n", ctr);

}
