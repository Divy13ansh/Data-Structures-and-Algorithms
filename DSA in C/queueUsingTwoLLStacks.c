#include<stdio.h>
#include<stdlib.h>

struct Node{
    int d;
    struct Node *next;
};

struct Queue{
    struct Node *stack1, *stack2;
};

void push(struct Node **, int);
void pop(struct Node **);

void main(){
    void enqueue(struct Queue *, int);
    void dequeue(struct Queue *);
    void disp(struct Node *,struct Node *);
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    int f = 0,a,ele,ch,i,j,k=1;
    while(k){
        printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                enqueue(q,ele);
            case 2:
                dequeue(q);
                break;
            case 3:
                disp(q->stack1,q->stack2);N
                break;
            case 4:
                k = 0;
                break;

        }
    }
}
void push(struct Node **top, int ele){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory full");
        return;
    }
    t->d = ele;
    t->next = (*top);
    *top = t;
}
