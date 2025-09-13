#include<stdio.h>
#define MAX 10
void multiplyMatrix(int[MAX][MAX], int[MAX][MAX]);
int rone, cone, rtwo, ctwo;
int crm[MAX][MAX];
int sum,i=0,j=0,k=0;

void main(){
    int arm[MAX][MAX], brm[MAX][MAX],k;
    printf("No. of rows for 1st matrix: ");
    scanf("%d",&rone);
    printf("No. of cols for 1st matrix: ");
    scanf("%d",&cone);
    printf("No. of rows for the 2nd matrix: ");
    scanf("%d",&rtwo);
    printf("No. of cols for the 2nd matrix: ");
    scanf("%d",&ctwo);

    if(cone != rtwo)
        printf("The no. columns of 1st and rows of 2nd matrix are different.");
    else{
        printf("Input elements in the first matrix: \n");
        for(int i = 0;i<rone;i++){
            for(int j = 0;j<cone;j++){
                printf("Enter element [%d][%d]: ",i,j);
                scanf("%d",&arm[i][j]);
            }
        }

        printf("Input elements in the second matrix: \n");
        for(int i = 0;i<rtwo;i++){
            for(int j = 0;j<ctwo;j++){
                printf("Enter element [%d][%d]: ",i,j);
                scanf("%d",&brm[i][j]);
            }
        }

        printf("The elements of first matrix are: \n");
        for(int i = 0;i<rone;i++){
            for(int j = 0;j<cone;j++){
                printf("%d\t",arm[i][j]);
            }
            printf("\n");
        }

        printf("The elements of second matrix are: \n");
        for(i = 0;i<rtwo;i++){
            for(j = 0;j<ctwo;j++){
                printf("%d\t",brm[i][j]);
            }
            printf("\n");
        }

        printf("%d\t%d\n",i,j);
        multiplyMatrix(arm,brm);
    }
    printf("Multiplied Matrix: \n");

    for(int i = 0;i<rone;i++){
        for(int j = 0;j<ctwo;j++){
            printf("%d\t",crm[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int arm[MAX][MAX],int brm[MAX][MAX]){
    if(i<rone){
        if(j<ctwo){
            if(k<cone){
                sum = sum + arm[i][k]*brm[k][j];
                k++;
                multiplyMatrix(arm,brm);
            }
            crm[i][j] = sum;
            sum = 0;
            k = 0;
            j++;
            multiplyMatrix(arm,brm);
        }
        j=0;
        i++;
        multiplyMatrix(arm,brm);
    }
}


