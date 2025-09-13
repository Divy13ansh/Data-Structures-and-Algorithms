#include<stdio.h>

int fact(int);

void main(){
    int n;
    printf("Enter your no.: ");
    scanf("%d",&n);
    int z = fact(n);
    printf("%d",z);
}

/*int fact(int n){
    static int fac = 1;
    if(n>1){
        fac *= n;
        fact(n-1);
    }
    return fac;
}
*/

int fact(int n){
    if(n==1){
        return 1;
    }
    else
        return(n*fact(n-1));
}
