#include<stdio.h>
#include<stdlib.h>
struct Node{
    int d;
    struct Node *next;
};
int count(struct Node *);
void main(){
    int i,j,k=1,s,ch,ele,pos,c;
    struct Node *head = NULL;
    struct Node *f, *r;
    void add(struct Node **,int);
    void disp(struct Node *);
    void reverse(struct Node **);
    void rev1(struct Node **);
    void addascend(struct Node **, int);
    while(k){
        printf("\nMenu\n1. Add\n2. Display\n3. Reverse\n4. rev1\n5. Addascend\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                add(&head,ele);
                break;
            case 2:
                disp(head);
                break;
            case 3:
                reverse(&head);
                break;
            case 4:
                rev1(&head);
            case 5:
                printf("Enter element: ");
                scanf("%d",&ele);
                addascend(&head,ele);
        }

    }
}
void add(struct Node **p,int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory Full");
        return;
    }
    t->d = ele;
    t->next = NULL;
    if(*p == NULL){
        *p = t;
    }
    else{
        struct Node *q;
        q = *p;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = t;
    }
}
void disp(struct Node *p){
    while(p != NULL){
        printf("%d\t",p->d);
        p = p->next;
    }
}
int count(struct Node *p){
    int c=0;
    while(p->next != NULL){
        c++;
        p = p->next;
    }
}

void reverse(struct Node **p){
    int c,i,j,k;
    struct Node *q = *p;
    struct Node *m = *p;

    for(m = *p;m!=NULL;m=m->next){
        for(q=m->next;q!=NULL;q=q->next){
            k = m->d;
            m->d = q->d;
            q->d = k;
        }
    }
}
void rev1(struct Node **p){
    struct Node *r,*s;
    struct Node *q = *p;
    r = NULL;
    while(q!=NULL){
        s = r;
        r = q;
        q = q->next;
        r->next = s;
    }
    *p = r;
}
void addascend(struct Node **p,int ele){
    struct Node *t,*q;
    t = (struct Node *)malloc(sizeof(struct Node));
    q = *p;
    if(t==NULL){
        printf("Memory Full");
        return;
    }
    t->d = ele;

    if(*p == NULL ||(*p)->d > ele){
        *p = t;
        (*p)->next = q;

    }
    else{
        while((q != NULL)){
            if((q->d<=ele) && (q->next = NULL)||(q->next->d > ele)){
                t->next = q->next;
                q->next = t;
                return;
              }
            q = q->next;
        }

    }
}
