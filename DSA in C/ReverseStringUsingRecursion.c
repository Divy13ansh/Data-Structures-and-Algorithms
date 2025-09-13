#include<stdio.h>
#define MAX 100

char* ReverseofString(char[]);

void main(){
    char str1[MAX], *revstr;
    printf("Input any string: ");
    scanf("%s",str1);
    revstr = ReverseofString(str1);
    printf("The reversed string is: %s\n\n",revstr);
}

char* ReverseofString(char str1[]){
    static int i = 0;
    static char revstr[MAX];
    if(*str1){
        ReverseofString(str1+1);
        revstr[i++] = *str1;
    }
    return revstr;
}
