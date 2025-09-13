#include<stdio.h>
int lcmCalculate(int a, int b);

void main(){
    int n1,n2,lcmOf;
    printf("Input 1st no. for LCM: ");
    scanf("%d",&n1);
    printf("Input 2nd no. for LCM: ");
    scanf("%d",&n2);
    if(n1>n2){
        lcmOf = lcmCalculate(n2,n1);
    }
    else{
        lcmOf = lcmCalculate(n1,n2);
    }
    printf("The LCM of %d and %d is %d\n\n",n1,n2,lcmOf);
}

int lcmCalculate(int a, int b){
    static int m = 0;
    m += b;
    if(m % a == 0 && m % b == 0){
        return m;
    }
    else{
        lcmCalculate(a,b);
    }

}
