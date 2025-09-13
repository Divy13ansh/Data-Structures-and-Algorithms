#include<stdio.h>
#include<stdlib.h>
struct Node{
    int d;
    struct Node *next;
};
void main(){
    int i,j,k=1,ch,ele;
    struct Node *front,*rear;
    front = rear = NULL;
    void add(struct Node **,struct Node **,int);
    int pop(struct Node **,struct Node **);
    void show(struct Node *,struct Node *);
    void isEmpty(struct Node *);
    while(k){
        printf("\nMenu\n1. Add\n2. del\n3. Show\n4. isEmpty\n5. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter ele: ");
            scanf("%d", &ele);
            add(&front,&rear,ele);
            break;
        case 2:
            i = pop(&front,&rear);
            if(i!=-1){
                printf("%d",i);
            }
            break;
        case 3:
            show(front,rear);
            break;
        case 4:
            isEmpty(front);
            break;
        case 5:
            k = 0;
            break;
        }
    }
}
void add(struct Node **f,struct Node **r,int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory Full");
        return;
    }
    t->d = ele;
    t->next = NULL;
    if(*f == NULL)
        *f = *r = t;
    else
        (*r)->next = t;
        *r = t;
}
int pop(struct Node **f,struct Node **r){
    int n;
    struct Node *t;
    if(*f == NULL){
        printf("queue is empty");
        return -1;
    }

    t = *f;

    if(*f == *r)
        *f = *r = NULL;
    else
        *f = (*f)->next;

    n = t->d;
    free(t);
    return n;
}
void show(struct Node *f,struct Node *r){
    if(f == NULL){
        printf("Queue is empty");
        return;
    }
    while(f!=NULL){
        printf("%d\t",f->d);
        f = f->next;
    }
}
void isEmpty(struct Node *f){
        if(f == NULL)
        printf("Queue is empty");
        else
            printf("Not");
}

