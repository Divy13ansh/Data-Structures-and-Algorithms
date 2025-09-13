#include<stdio.h>

int findGCD(int n1,int n2, int ctr);

void main(){
    int n1,n2;
    printf("Enter no. 1: \n");
    scanf("%d",&n1);
    printf("Enter no. 2: \n");
    scanf("%d",&n2);
    if(n1 > n2){
        printf("%d",findGCD(n1,n2,n2));
    }
    else{
        printf("%d",findGCD(n2,n1,n1));
    }
}

int findGCD(int n1,int n2,int ctr){
    if(n1 % ctr == 0 && n2 % ctr == 0){
        return ctr;
    }
    else{
        findGCD(n1,n2,ctr-1);
    }

}
