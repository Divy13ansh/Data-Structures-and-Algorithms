#include<stdio.h>
#include<stdlib.h>
struct Term{
    int c,e;
};
struct Poly{
    struct Term a[10];
    int not;
};
void main(){
    void createPoly(struct Poly *);
    void dispPoly(struct Poly *);
    int solveI(struct Poly *);
    int solveII(struct Poly *, int);
    int solveIII(struct Poly *, int);
    void addPoly(struct Poly, struct Poly, struct Poly *);
    void multi(struct Poly, struct Poly, struct Poly *);
    struct Poly A, B, C, D;
    int i,j,k=1,ch,ele,s,n;
    while(k){
        printf("\nMenu\n1. Create 1st poly\n2. Display 1st Poly\n3. Solve I\n4. Solve II\n5. Solve III\n6. Create 2nd poly\n7. Display 2nd poly\n8. Addition\n9. Display 3rd poly after addition\n10. Multiplication\n11. Display 4th after multiplication\n12. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createPoly(&A);
                break;
            case 2:
                dispPoly(&A);
                break;
            case 3:
                s=solveI(&A);
                printf("solution is %d",s);
                break;
            case 4:
                printf("Enter the value of n: ");
                scanf("%d",&n);
                s=solveII(&A,n);
                printf("solution is %d",s);
                break;
            case 5:
                printf("Enter the value of n: ");
                scanf("%d",&n);
                s=solveIII(&A,n);
                printf("solution is %d",s);
                break;
            case 6:
                createPoly(&B);
                break;
            case 7:
                dispPoly(&B);
                break;
            case 8:
                addPoly(A, B,&C);
                break;
            case 9:
                dispPoly(&C);
                break;
            case 10:
                multi(A,B,&D);
                break;
            case 11:
                dispPoly(&D);
                break;
            case 12:
                k = 0;
                break;
        }
    }
}

void createPoly(struct Poly *p){
    int i;
    printf("Enter no. of terms: ");
    scanf("%d", &p->not);
    if(p->not>10){
        printf("Out of limit");
        return;
    }
    for(i=0;i<p->not;i++){
            printf("Enter coefficient: ");
            scanf("%d",&p->a[i].c);
            printf("Enter exponent: ");
            scanf("%d",&p->a[i].e);
    }
}

void dispPoly(struct Poly *p){
    int i;
    for(i=0;i<p->not;i++){
        printf("%dx^%d+",p->a[i].c,p->a[i].e);
    }
    printf("\b ");
}

int solveI(struct Poly *p){
    int s = 0,i,j,pr;
    for(i=0;i<p->not;i++){
        pr = 1;
        for(j=1;j<=p->a[i].e;j++){
            pr *= p->a[i].c;
        }
        s+=pr;
    }
    return s;
}

int solveII(struct Poly *p, int n){
    int s = 0,i,j,pr;
    for(i=0;i<p->not;i++){
        pr = 1;
        for(j=1;j<=p->a[i].e;j++){
            pr *= n;
        }
        s+=pr*p->a[i].c;
    }
    return s;
}

int solveIII(struct Poly *p,int n){
    int s = 0,i,j,pr,ch;
    for(i=0;i<p->not;i++){
        pr = 1;
        for(j=1;j<=p->a[i].e;j++){
            pr *= n;
        }
        printf("1 for +, 2 for -\nEnter Your choice: ");
        scanf("%d",&ch);
        if(ch== 1)
            s+=pr*p->a[i].c;
        else
            s-=pr*p->a[i].c;
    }
    return s;
}

void addPoly(struct Poly X, struct Poly Y, struct Poly *Z){
    if(X.not == -1 || Y.not == -1){
        printf("Poly is empty");
        return;
    }
    int i,j,k;
    for(i=0,j=0,k=0;i<X.not && j<Y.not;k++){
        if(X.a[i].e > Y.a[i].e){
            Z->a[k].c = X.a[i].c;
            Z->a[k].e = X.a[i].e;
            i++;
        }
        else{
            if(X.a[i].e < Y.a[j].e){
                Z->a[k].c = Y.a[j].c;
                Z->a[k].e = Y.a[j].e;
                j++;
            }
            else{
                Z->a[k].c = X.a[i].c + Y.a[j].c;
                Z->a[k].e = X.a[i].e;
                i++;
                j++;
            }
        }
    }
    if(i<X.not){
        while(i<X.not){
            Z->a[k].c = X.a[i].c;
            Z->a[k].e = X.a[i].e;
            i++;
            k++;
        }
    }
    else{
        while(j<Y.not){
            Z->a[k].c = Y.a[j].c;
            Z->a[k].e = Y.a[j].e;
            j++;
            k++;
        }
    }
    Z->not = k;
}

/*void multi(struct Poly X, struct Poly Y, struct Poly *Z){
    int i,j,f,l;
    Z->not = 0;
    for(i=0;i<X.not;i++){
        for(j=0;j<Y.not;j++){
            f = 0;
            for(l=0;l<Z->not;l++){
                if(X.a[i].e + Y.a[j].e == Z->a[l].e){
                    Z->a[l].c = Z->a[l].c + (X.a[i].c * Y.a[j].c);
                    f = 1;
                }
            }
            if(f == 0){
                Z->a[Z->not].c = X.a[i].c * Y.a[j].c;
                Z->a[Z->not].e = X.a[i].e + Y.a[j].e;
                Z->not++;
            }
        }
    }
}
*/
void multi(struct Poly X, struct Poly Y, struct Poly *Z){
    int i,j,k,f;
    Z->not = 0;
    for(j=0,k=0;j<Y.not;j++,k++){
        Z->a[k].c = X.a[0].c * Y.a[j].c;
        Z->a[k].e = X.a[0].e + Y.a[j].e;
    }
    Z->not = k;
    for(i = 1;i<X.not;i++){
        for(j=0;j<Y.not;j++){
            f = 0;
            for(k = 0;k<Z->not;k++){
                if((X.a[i].e + Y.a[j].e) == Z->a[k].e){
                    Z->a[k].c += (X.a[i].c * Y.a[j].c);
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                Z->a[k].c = X.a[i].c * Y.a[j].c;
                Z->a[k].e = X.a[i].e + Y.a[j].e;
                Z->not++;
            }

        }
    }
}

