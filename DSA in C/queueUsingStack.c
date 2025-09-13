#include<stdio.h>
#include<stdlib.h>

void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void disp();
int st1[100],st2[100];
int top1 = -1,top2 = -1,count = 0,ch,i,j,k=1,ele;
void main(){

    while(k){
        printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                disp();
                break;
            case 4:
                k = 0;
                break;
        }
    }
}
void push1(int ele){
    st1[++top1] = ele;
}

int pop1(){
    return(st1[top1--]);
}

void push2(int ele){
    st2[++top2] = ele;
}

int pop2(){
    return(st2[top2--]);
}

void enqueue(int ele){
    push1(ele);
    count++;
}

void dequeue(){
    int i;
    for(i=0;i<count;i++){
        push2(pop1());
    }
    pop2();
    count--;
    for(i=0;i<count;i++){
        push1(pop2());
    }
}

void disp(){
    int i;
    for(i=0;i<=top1;i++){
        printf("%d\t",st1[i]);
    }
}
