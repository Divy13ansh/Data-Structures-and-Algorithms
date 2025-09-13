#include<stdio.h>
#include<stdlib.h>
struct queue{
    int a[10];
    int f,r;
};
void main(){
    int i,j,k=1,ch,ele;
    void push(struct queue *,int);
    int pop(struct queue *);
    void show(struct queue);
    void isEmpty(struct queue);
    void isFull(struct queue);
    struct queue A;
    A.f = A.r = -1;
    while(k){
        switch(ch){
            case 1:
                printf("Enter ele: ");
                scanf("%d", &ele);
                push(&A,ele);
            case 2:
                i = pop(&A);
                if(i != -1){
                    printf("%d",i);
                }
                break;
            case 3:
                show(A);
                break;
            case 4:
                isEmpty(A);
                break;
            case 5:
                isFull(A);
                break;
        }
    }
}
void push(struct queue *p,int ele){
    if(p->r == 9){
        printf("queue full");
        return;
    }
    else{
        if(p->r == 0){
            p->f++;
        }
        p->a[p->r] = ele;
        p->r++;
    }
}
int pop(struct queue *p){
    if(p->f == -1){
        printf("queue empty");
        return -1;
    }
    else{
        int num;
        num = p->a[p->f];
        if(p->f == p->r)
            p->f = p->r = -1;
        else
            p->f++;
        return num;
    }
}
void show(struct queue p){
    int i;
    if(p.f == -1){
        printf("queue Empty");
        return;
    }
    for(i = p.f;i <= p.r;i++){
        printf("%d\n",p.a[p.f]);
    }
}
void isEmpty(struct queue p){
    if(p.f == -1){
        printf("Empty");
    }
    else{
        printf("Not");
    }
}
void isFull(struct queue p){
    if(p.r == 9){
        printf("Full");
    }
    else{
        printf("Not");
    }
}
