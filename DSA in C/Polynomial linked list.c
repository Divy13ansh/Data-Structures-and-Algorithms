#include <stdio.h>
struct Term{
    int c,e;
};
struct poly{
    struct Term a[10];
    int not;
};
int main() {
    void create(struct poly *);
    void disp(struct poly);
    int solve1(struct poly);
    int solve2(struct poly);
    struct poly A,B,C,D;
    int i,j,k=1,ch;
    A.not = -1;
    B.not = -1;
    while(k){
        printf("Menu\n1.Create 1st polynomial\n2. Display 1st polynomial\n3. Solve 1\n4. Solve 2\n5. Solve 3\n6. Create 2nd polynomial\n7. Display 2nd polynomial\n8. Addition\n9. Display 3rd after addition\n10. Multiplication\n11. Display 4th after multiplication\n12. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                create(&A);
                break;
            case 2:
                disp(A);
                break;
            case 3:
                i=solve1(A);
                printf("Answer is %d\n",i);
                break;
            case 4:
                i=solve2(A);
                printf("Answer is %d\n",i);
                break;
            case 5:
                break;
            case 6:
                create(&B);
                break;
            case 7:
                disp(B);
                break;
            case 8:

    }

}
    return 0;
}
void create(struct poly *P){
    int i;
    printf("How many terms you want to input: ");
    scanf("%d",&P->not);
    for(i=0;i<P->not;i++){
        printf("Enter coefficient= ");
        scanf("%d",&P->a[i].c);
        printf("Enter exponent= ");
        scanf("%d",&P->a[i].e);
    }
}
void disp(struct poly X){
    int i;
    if(X.not==-1)
        printf("Polynomial is empty");
    else{
        for(i=0;i<X.not;i++){
            printf("%dx^%d+",X.a[i].c,X.a[i].e);
        }
        printf("\b\b\n");
    }
}
int solve1(struct poly X){
    int i,j,p,s=0;
    for(i=0;i<X.not;i++){
        p=1;
        for(j=0;j<X.a[i].e;j++){
            p = p * X.a[i].c;
        }
        s=s+p;
    }
    return s;
}
int solve2(struct poly X){
    int x,i,j,p,s=0;
    printf("Enter the value of variable: ");
    scanf("%d",&x);
    for(i=0;i<X.not;i++){
        p=1;
        for(j=0;j<X.a[i].e;j++){
            p = p * x;
        }
        p = p*X.a[i].c;
        s=s+p;
    }
    return s;
}
int solve3(struct poly X){

}
