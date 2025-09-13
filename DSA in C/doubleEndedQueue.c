#include<stdio.h>
#include<stdlib.h>
struct dQueue{
    int a[10],f,r;
};
void main(){
    void initialize(struct dQueue *);
    void addBeg(struct dQueue *, int);
    int count(int[])


    struct dQueue A;
    int i,j,k=1,ch,ele;
    while(k){
        printf("\nMenu\n1. Initialize\n2. addBeg\n3. addEnd\n4. delBeg\n5. delEnd\n6. display\n7. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                initialize(&A);
                break;
            case 2:
                printf("Enter ele: ");
                scanf("%d",&ele);
                addBeg(&A,ele);
        }
    }
}
void initialize(struct dQueue *p){
    int i;
    p->f = p->r = -1;
    for(i=0;i<=9;i++){
        p->a[i] = 0;
    }
}

void addBeg(struct dQueue *p, int ele){
    int i,k,c;
    if(p->f == 0 && p->r == 9){
        printf("queue is full");
        return;
    }
    if(p->f == -1){
        p->f = p->r = 0;
        p->a[p->f] = ele;
    }
    if(p->r != 9){
        c = count(p->a);
        k = p->r + 1;
        for(i=1;i<=c;i++){
            p->a[k] = p->a[k-1];
            k--;
        }
        p->a[k] = ele;
        p->f = k;
        p->r++;
    }
    else{
        p->f--;
        p->a[p->f] = ele;
    }
}

int count(int n[9]){
    int i,c;
    c = 0;
    for(i=0;i<= 0;i++){
        if(n[i] != 0){
            c++;
        }
    }
    return c;
}

void addEnd(struct dQueue *p,int ele){
    int k,i;
    if(p->f == 0 && p->r == 9){
        printf("Full");
        return;
    }
    if(p->f == -1){
        p->f = p->r = 0;
        p->a[p->r] = ele;
        return;
    }
    if(p->r == 9){
        k = (p->f)-1;
        for(i=(p->f)-1;i<= p->r;i++){
            k = i;
            if(k==9)
                p->a[k] = 0;
            else
                p->a[k] = p->a[i+1];
        }
        p->r--;
        p->f--;
    }
    p->r++;
    p->a[p->r] = ele;
}

int delBeg(struct dQueue *p){
    int num;
    if(p->f == -1){
        printf("Queue is empty");
        return -1;
    }
    num = p->a[p->f];
    p->a[p->f] = 0;
    if(p->f == p->r)
        p->f = p->r = -1;
    else{
        p->f++;
    }
    return num;
}

int delEnd(struct dQueue *p){
    int num;
    if(p->f == -1){
        printf("queue is empty");
        return -1;
    }
    num = p->a[p->r];
    p->a[p->r] = 0;
    p->r--;
    if(p->r == -1)
        p->f = -1;
    return num;
}
