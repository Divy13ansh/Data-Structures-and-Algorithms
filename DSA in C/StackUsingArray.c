#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int a[10];
    int top;
};
void main(){
    struct Stack A;
    A.top = -1;
    void push(struct Stack *, int);
    int pop(struct Stack *);
    int peak(struct Stack);
    void show(struct Stack);
    void isEmpty(struct Stack);
    void isFull(struct Stack);
    int i,j,k=1,ch,ele;
    while(k){
        printf("\nMenu\n1. Push\n2. Pop\n3. Peak\n4. Show\n5. isEmpty\n6. isFull\n7. exit\nChoice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter Ele: ");
                scanf("%d", &ele);
                push(&A,ele);
                break;
            case 2:
                i = pop(&A);
                printf("%d",i);
                break;
            case 3:
                j = peak(A);
                printf("%d",j);
                break;
            case 4:
                show(A);
                break;
            case 5:
                isEmpty(A);
                break;
            case 6:
                isFull(A);
                break;
            case 7:
                k = 0;
                break;
        }
    }
}
void push(struct Stack*p,int ele){
    if(p->top == 9){
        printf("Stack is full");
        return;
    }
    p->top++;
    p->a[p->top] = ele;
}

int pop(struct Stack *p){
    int num;
    if(p->top == 0){
        printf("Stack empty");
        return;
    }
    num = p->a[p->top];
    p->top--;
    return num;
}
int peak(struct Stack p){
    if(p.top == 0){
        printf("Stack empty");
        return;
    }
    return p.a[p.top];
}
void show(struct Stack p){
    int i;
    if(p.top == 0){
        printf("Stack empty");
        return;
    }
    for(i=0;i<=p.top;i++){
        printf("%d\t",p.a[i]);
    }
}
void isEmpty(struct Stack p){
    if(p.top == 0){
        printf("Stack empty");
        return;
    }
    else{
        printf("Not Empty");
    }
}
void isFull(struct Stack p){
    if(p.top == 9){
        printf("Stack Full");
        return;
    }
    else{
        printf("Not Full");
    }
}
