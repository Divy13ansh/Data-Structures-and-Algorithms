#include<stdio.h>
#include<stdlib.h>
struct Node{
    int d;
    struct Node *next;
};
void main(){
    int i,j,k=1,ch,ele;
    struct Node *head = NULL;
    void push(struct Node **,int);
    void show(struct Node *);
    int pop(struct Node **);
    int peak(struct Node *);
    void isEmpty(struct Node *);
    while(k){
        printf("\nMenu\n1. Push\n2. Pop\n3. show\n4. Peak\n5. isEmpty\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter ele: ");
                scanf("%d",&ele);
                push(&head,ele);
                break;
            case 2:
                i = pop(&head);
                printf("%d",i);
                break;
            case 3:
                show(head);
                break;
            case 4:
                j = peak(head);
                if(j != -1){
                    printf("%d",j);
                }
                break;
            case 5:
                isEmpty(head);
                break;
        }
    }
}

void push(struct Node **p,int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory Full");
    }
    t->d = ele;
    t->next = *p;
    *p = t;
}

void show(struct Node *p){
    if(p==NULL){
        printf("Stack is empty");
    }
    while(p!=NULL){
        printf("%d\t",p->d);
        p = p->next;
    }
}

int pop(struct Node **p){
    int num;
    if(*p == NULL){
        printf("Stack is empty");
        return;
    }
    struct Node *t;
    t = *p;
    (*p) = (*p)->next;
    num = t->d;
    free(t);
    return num;
}
int peak(struct Node *p){
    if(p == NULL){
        printf("Stack Empty");
        return -1;
    }
    return p->d;
}
void isEmpty(struct Node *p){
    if(p == NULL){
        printf("Stack empty");
    }
    else{
        printf("NOT");
    }
}
