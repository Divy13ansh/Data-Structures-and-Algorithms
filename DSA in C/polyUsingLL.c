#include<stdio.h>
#include<stdlib.h>
struct Node{
    int c,e;
    struct Node *next;
};
void main(){
    void createPoly(struct Node *);
    struct Node *Anode,*Bnode,*Cnode,*Dnode;
    int i,j,k=1,ch,ele,pos,s,n;
    Anode = (struct Node *)malloc(sizeof(struct Node));
    Bnode = (struct Node *)malloc(sizeof(struct Node));
    Cnode = (struct Node *)malloc(sizeof(struct Node));
    Dnode = (struct Node *)malloc(sizeof(struct Node));
    while(k){
        printf("\nMenu\n1. Create 1st poly\n2. Display 1st Poly\n3. Solve I\n4. Solve II\n5. Solve III\n6. Create 2nd poly\n7. Display 2nd poly\n8. Addition\n9. Display 3rd poly after addition\n10. Multiplication\n11. Display 4th after multiplication\n12. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createPoly(Anode);
                break;
            case 2:
                dispPoly(Anode);
                break;
            case 3:
                s=solveI(Anode);
                printf("solution is %d",s);
                break;
            case 4:
                printf("Enter the value of n: ");
                scanf("%d",&n);
                s=solveII(Anode,n);
                printf("solution is %d",s);
                break;
            case 5:
                printf("Enter the value of n: ");
                scanf("%d",&n);
                s=solveIII(Anode,n);
                printf("solution is %d",s);
                break;
            case 6:
                createPoly(Bnode);
                break;
            case 7:
                dispPoly(Bnode);
                break;
            case 8:
                addPoly(Anode, Bnode, Cnode);
                break;
            case 9:
                dispPoly(Cnode);
                break;
            case 10:
                multi(Anode,Bnode,Dnode);
                break;
            case 11:
                dispPoly(Dnode);
                break;
            case 12:
                k = 0;
                break;
        }
    }
}

void createPoly(struct Node *p){
    int c;
    printf("Enter coefficient: ");
    scanf("%d", &p->c);
    printf("Enter exponent: ");
    scanf("%d", &p->e);

    printf("Do you want to add more elements\n1 for YES\n2 for NO\nEnter Your choice: ");
    scanf("%d",&c);
    if(c == 1){
        p->next = (struct Node *)malloc(sizeof(struct Node));
        createPoly(p->next);
    }
    else{
        p->next = NULL;
    }
}

void dispPoly(struct Node *p){
    printf("%dx^%d+",p->c,p->e);
    if(p->next != NULL){
        dispPoly(p->next);
    }
    else
        printf("\b ");
}

int solveI(struct Node *p){
    int s = 0,i,j,pr;
    while(p!=NULL){
        pr = 1;
        for(j=1;j<=p->e;j++){
            pr *= p->c;
        }
        s+=pr;
        p = p->next;
    }
    return s;
}

int solveII(struct Node *p,int n){
    int s = 0,i,j,pr;
    while(p!=NULL){
        pr = 1;
        for(j=1;j<=p->e;j++){
            pr *= n;
        }
        pr *= p->c;
        s+=pr;
        p = p->next;
    }
    return s;
}

int solveIII(struct Node *p,int n){
    int s = 0,i,j,pr,ch;
    while(p!=NULL){
        pr = 1;
        for(j=1;j<=p->e;j++){
            pr *= n;
        }
        pr *= p->c;
        printf("1. +\n2. -\nEnter Your Choice: ");
        scanf("%d",&ch);
        if(ch == 1)
            s+=pr;
        else
            s-= pr;
        p = p->next;
    }
    return s;
}

void addPoly(struct Node *X,struct Node *Y,struct Node *Z){
    int c = 0;
    if(X == NULL || Y == NULL){
        printf("Poly is empty");
        return;
    }
    struct Node *t;
    int i,j,k;
    while(X!= NULL || Y!= NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        if(X->e > Y->e){
            t->c = X->c;
            t->e = X->e;
            X=X->next;
        }
        else{
            if(X->e < Y->e){
                t->c = Y->c;
                t->e = Y->e;
                Y=Y->next;
            }
            else{
                t->c = X->c + Y->c;
                t->e = X->e;
                X=X->next;
                Y=Y->next;
            }
        }
        if(c == 0){
            Z->c = t->c;
            Z->e = t->e;
        }
        else{
            Z->next = t;
            Z = Z->next;
        }

        c++;
    }
    if(X!=NULL){
        while(X != NULL){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->c = X->c;
            t->e = X->e;
            X=X->next;
            if(c == 0){
                Z->c = t->c;
                Z->e = t->e;
            }
            else{
                Z->next = t;
                Z = Z->next;
            }

            c++;
        }
    }
    else{
        while(Y != NULL){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->c = Y->c;
            t->e = Y->e;
            Y=Y->next;
            if(c == 0){
                Z->c = t->c;
                Z->e = t->e;
            }
            else{
                Z->next = t;
                Z = Z->next;
            }

            c++;
        }
    }
    Z->next = NULL;
}

void multi(struct Node *X, struct Node *Y, struct Node *Z){
    int i,j,f,l,count=0;
    struct Node *t;
    struct Node *C = Z;
    struct Node *M = Z;
    struct Node *A = X;
    struct Node *B = Y;
    C->next = NULL;
    for(A;A!=NULL;A=A->next){
        B = Y;
        for(B;B!=NULL;B=B->next){
            C = Z;
            f = 0;
            if(count != 0){
                for(C;C!=NULL;C=C->next){
                    if(C->e == A->e + B->e){
                        f = 1;
                        C->c += A->c * B->c;
                    }
                }
            }
            if(f == 0){
                t = (struct Node *)malloc(sizeof(struct Node));
                t->c = A->c * B->c;
                t->e = A->e + B->e;
                t->next = NULL;
                if(count == 0){
                    Z->c = t->c;
                    Z->e = t->e;
                    Z->next = t->next;
                }
                else{
                    while(Z->next!=NULL){
                        Z = Z->next;
                    }
                    Z->next = t;

                }
                Z = M;
                count++;
            }
        }
    }
}
