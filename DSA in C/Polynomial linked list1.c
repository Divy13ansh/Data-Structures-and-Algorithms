#include<stdio.h>
struct poly{
    int c,e;
    struct poly *next;
    };
void main(){
    struct poly *A,*B,*C,*D;
    void create(struct poly*);
    void disp(struct poly*);
    void add(struct poly*,struct poly*,struct poly**);
    int ch,k=1;
    A=B=C=D=NULL;
    A= (struct poly*)malloc(sizeof(struct poly));
    B = (struct poly*)malloc(sizeof(struct poly));
    C= (struct poly*)malloc(sizeof(struct poly));
    while(k){
        printf("Menu\n1. Create 1st polynomial\n2. Display\n3. Create 2nd polynomial\n4.display\n5.add\n6.display dum\nEnter Your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                create(A);
                break;
            case 2:
                disp(A);
                break;
            case 3:
                create(B);
                break;
            case 4:
                disp(B);
                break;
            case 5:
                add(A,B,&C);
                break;
            case 6:
                disp(C);
                break;


        }
    }

}
void create(struct poly *p){
    int ch;
    printf("Enter coefficient: ");
    scanf("%d",&p->c);
    printf("Enter exponent: ");
    scanf("%d",&p->e);
    printf("Do you want to enter more?\n1 for yes\n2 for no: ");
    scanf("%d",&ch);
    if(ch==1){
        p->next=(struct poly*)malloc(sizeof(struct poly));
        if (p->next == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        create(p->next);
    }
    else{
        p->next = NULL;
    }
}
void disp(struct poly *p){
    printf("%dx^%d",p->c,p->e);
    if(p->next !=NULL){
        printf("+");
        disp(p->next);
    }
    else
        printf("\n");
        return;

}
void add(struct poly*X,struct poly*Y,struct poly**Z){
    struct poly *t,*q;

    t=(struct poly*)malloc(sizeof(struct poly));
    t->next=NULL;

    *Z=t;
    q=*Z;
    if(t==NULL){
        printf("MEMORY IS FULL");
        return;
    }
    for(;X!=NULL&&Y!=NULL;){
        if(X->e>Y->e){
            q->c=X->c;
            q->e=X->e;
            X=X->next;
        }
        else{
            if(Y->e>X->e){
                q->c=Y->c;
                q->e=Y->e;
                Y=Y->next;
            }
            else{
                q->c=X->c+Y->c;
                q->e=X->e;
                X=X->next;
                Y=Y->next;
            }
        }

        q->next =(struct poly*)malloc(sizeof(struct poly));
        q=q->next;

    }
    q->next=NULL;

}
