#include<stdio.h>
#include<stdlib.h>
struct cqueue{
    int a[10];
    int f,r;
};
void main(){
    void add(struct cqueue *, int);
    void disp(struct cqueue *);
    int del(struct cqueue *);
    void isFull(struct cqueue);
    void isEmpty(struct cqueue);
    int i,j,k=1,ch,ele,pos;
    struct cqueue A;
    A.f = A.r = -1;
    while(k){
        printf("\nMenu\n1. add\n2. display\n3. del\n4. isEmpty\n5. isFull\n6. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter ele: ");
                scanf("%d",&ele);
                add(&A,ele);
                break;
            case 2:
                disp(&A);
                break;
            case 3:
                i = del(&A);
                printf("%d",i);
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
void add(struct cqueue *p, int ele){
    if((p->f == 0 && p->r == 9) || (p->r+1 == p->f)){
        printf("queue is full");
        return;
    }
    if(p->r == 9){
        p->r = 0;
    }
    else
        p->r++;
    p->a[p->r] = ele;
    if(p->f == -1)
        p->f = 0;
}

void disp(struct cqueue *p){
    if(p->f == -1){
        printf("Queue is empty");
        return;
    }
    int i;
    if(p->f < p->r){
        for(i=p->f;i<=p->r;i++){
            printf("%d\t",p->a[i]);
        }
    }
    else{
        for(i=p->f;i<=9;i++){
            printf("%d\t",p->a[i]);
        }
        for(i=0;i<=p->r;i++){
            printf("%d\t",p->a[i]);
        }
    }
}

int del(struct cqueue *p){
    int num;
    if(p->f == -1){
        printf("queue empty");
        return -1;
    }
    if(p->f == 9 && p->r != 0){
        num = p->a[p->f];
        p->f = 0;
        return num;
    }
    else if(p->f == p->r){
        num = p->a[p->f];
        p->f = p->r = -1;
        return num;
    }
    else{
        num = p->a[p->f];
        p->f++;
        return num;
    }
}

void isFull(struct cqueue p){
    if((p.f == 0 && p.r == 9)||(p.r+1 == p.f)){
        printf("Full");
    }
    else
    printf("Not Full");
}

void isEmpty(struct cqueue p){
    if(p.f == -1)
        printf("Empty");
    else
        printf("Not empty");
}
