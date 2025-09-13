#include<stdio.h>
#define SIZE 10
struct Stack{
    int ar[SIZE];
    int top1;
    int top2;
};
void main(){
    struct Stack A;
    A.top1 = -1;
    A.top2 = SIZE;
    void push_stack1(struct Stack *, int);
    void push_stack2(struct Stack *, int);
    int pop_stack1(struct Stack *);
    int pop_stack2(struct Stack *);
    void print_stack1(struct Stack *);
    void print_stack2(struct Stack *);
    int ch,i,num_ele,ele,k = 1;

    while(k){
        printf("\nMenu\n1. Push in stack 1\n2. Push in stack 2\n3. Pop in stack 1\n4. Pop in stack 2\n5. Print stack 1\n6. Print stack 2\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter ele: ");
                scanf("%d",&ele);
                push_stack1(&A,ele);
                break;
            case 2:
                printf("Enter ele: ");
                scanf("%d",&ele);
                push_stack2(&A,ele);
                break;
            case 3:
                i = pop_stack1(&A);
                if(i != -1){
                    printf("%d",i);
                }
                break;
            case 4:
                i = pop_stack2(&A);
                if(i != -1){
                    printf("%d",i);
                }
                break;
            case 5:
                print_stack1(&A);
                break;
            case 6:
                print_stack2(&A);
                break;
        }
    }
}

void push_stack1(struct Stack *p, int ele){
    if(p->top1  < p->top2){
        p->ar[++p->top1] = ele;
    }
    else{
        printf("Stack Full");
        return;
    }
}

void push_stack2(struct Stack *p, int ele){
    if(p->top1 < p->top2){
        p->ar[--p->top2] = ele;
    }
    else{
        printf("Stack Full");
        return;
    }
}

int pop_stack1(struct Stack *p){
    int num;
    if(p->top1 == -1){
        printf("Stack empty");
        return -1;
    }
    else{
        num = p->ar[p->top1];
        p->top1--;
    }
    return num;
}

int pop_stack2(struct Stack *p){
    int num;
    if(p->top2== SIZE){
        printf("Stack empty");
        return -1;
    }
    else{
        num = p->ar[p->top2];
        p->top2++;
    }
    return num;
}

void print_stack1(struct Stack *p){
    int i;
    if(p->top1 == -1){
        printf("Stack empty");
        return;
    }
    else{
        for(i = p->top1;i>=0;i--){
            printf("%d\t",p->ar[i]);
        }
    }
}

void print_stack2(struct Stack *p){
    int i;
    if(p->top2== SIZE){
        printf("Stack empty");
        return;
    }
    else{
        for(i = p->top2;i < SIZE;i++){
            printf("%d\t",p->ar[i]);
        }
    }
}
