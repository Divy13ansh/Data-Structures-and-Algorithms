#include<stdio.h>
#include<stdlib.h>
struct data{
    char job[10];
    int priority,order;
};
struct pQueue{
    int front,rear;
    struct data a[10];
};
void main(){
    struct data q;
    struct pQueue A;
    A.front = A.rear = -1;
    int i,j,k = 1,ch;

    void add(struct pQueue *, struct data);
    void disp(struct pQueue *);

    while(k){
        printf("\nMenu\n1. Add\n2. Display\n3. delete\n4. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter job: ");
                scanf("%s",q.job);
                printf("Enter priority",&q.priority);
                scanf("%d",&q.priority);
                q.order = ++i;
                add(&A,q);
                break;

            case 2:
                disp(&A);
        }
    }
}
void add(struct pQueue *p, struct data d){
    struct data t;
    int i,j;
    if(p->rear == 9){
        printf("queue is full");
        return;
    }
    p->rear++;
    p->a[p->rear] = d;
    if(p->front == -1)
        p->front = 0;
    for(i=p->front;i<=p->rear;i++){
        for(j=i+1;j<=p->rear;j++){
            if(p->a[i].priority > p->a[j].priority){
                t = p->a[i];
                p->a[i] = p->a[j];
                p->a[j] = t;
            }
            else{
                if(p->a[i].priority == p->a[j].priority){
                        if(p->a[i].order > p->a[j].order){
                            t = p->a[i];
                            p->a[i] = p->a[j];
                            p->a[j] = t;
                        }
                }
            }
        }
    }
}
void disp(struct pQueue *p){
    if(p->front == -1){
        printf("Queue is empty");
        return;
    }
    int i;
    for(i=p->front;i<=p->rear;i++){
        printf("%s\t%d\t%d",p->a[i].job,p->a[i].priority,p->a[i].order);
    }
}
struct data del(struct pQueue *p){
    if(p->front == -1){
        printf("Queue empty");
        return;
    }
    struct data q;
    q = p->a[p->front];
    if(p->front == p->rear){
        p->front = p->rear = -1;
    }
    else{
        p->front++;
    }
    return q;
}
