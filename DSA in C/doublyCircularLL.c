#include<stdio.h>
#include<stdlib.h>
struct Node{
    int d;
    struct Node *next,*prev;
};
void main(){
    void add(struct Node **,int);
    void disp(struct Node *);
    void begIns(struct Node **,int);
    void rev_disp(struct Node *);
    void midIns(struct Node **,int,int);
    void begDel(struct Node **);
    void midDel(struct Node **,int);
    void lastDel(struct Node **);
    void searchDel(struct Node **,int);
    struct Node *head = NULL;
    int i,j,k=1,ch,ele,pos;
    while(k){
        printf("\nMenu\n1. Add\n2. Disp\n3. rev_disp\n4. begIns\n5. midIns\n6. lastIns\n7. begDel\n8. midDel\n9. lastDel\n10. search_Del\n11. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter ele: ");
                scanf("%d",&ele);
                add(&head,ele);
                break;
            case 2:
                disp(head);
                break;
            case 3:
                rev_disp(head);
                break;
            case 4:
                printf("Enter ele: ");
                scanf("%d",&ele);
                begIns(&head,ele);
                break;
            case 5:
                printf("Enter ele: ");
                scanf("%d",&ele);
                printf("Enter pos: ");
                scanf("%d",&pos);
                midIns(&head,pos,ele);
                break;
            case 6:
                printf("Enter ele: ");
                scanf("%d",&ele);
                add(&head,ele);
                break;
            case 7:
                begDel(&head);
                break;
            case 8:
                printf("Enter pos: ");
                scanf("%d",&pos);
                midDel(&head,pos);
                break;
            case 9:
                lastDel(&head);
                break;
            case 10:
                printf("Enter ele: ");
                scanf("%d",&ele);
                searchDel(&head,ele);
        }
    }
}

void add(struct Node **p,int ele){
    struct Node *t,*q;

    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory Full");
        return;
    }
    t->d = ele;

    if(*p == NULL){
        *p = t;
        t->prev = *p;
        t->next = *p;
    }
    else{
        q = *p;
        while(q->next!= *p){
            q = q->next;
        }
        t->prev = q;
        q->next = t;
        t->next = *p;
        (*p)->prev = t;
    }
}

void disp(struct Node *p){
    struct Node *q;
    if(p==NULL){
        printf("Empty list");
        return;
    }
    q = p;
    do{
        printf("%d\t",q->d);
        q = q->next;
    }
    while(q != p);
}

void rev_disp(struct Node *p){
    struct Node *q;
    if(p==NULL){
        printf("Empty list");
        return;
    }
    q = p->prev;
    p = p->prev;
    do{
        printf("%d\t",q->d);
        q = q->prev;
    }
    while(q != p);
}

void begIns(struct Node **p,int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->d = ele;
    t->next = *p;
    t->prev = (*p)->prev;
    (*p)->prev->next = t;
    (*p)->prev = t;
    *p = t;
}

void midIns(struct Node **p,int pos,int ele){
    struct Node *q,*t;
    int c,ch;
    q = *p;
    c = 1;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Memory Full");
        return;
    }
    if(pos == 1){
        printf("Before or after: ");
        scanf("%d",&ch);
        if(ch == 1){
            begIns(p,ele);
        }
        else{
            while(c != pos){
                q = q->next;
                c++;
            }
            t->d = ele;
            t->prev = q;
            t->next = q->next;
            q->next->prev = t;
            q->next = t;
        }
    }
    while(c != pos){
        q = q->next;
        c++;
    }
    t->d = ele;
    t->prev = q;
    t->next = q->next;
    q->next->prev = t;
    q->next = t;
}

void begDel(struct Node **p){
    struct Node *t;
    if(*p == NULL){
        printf("Empty list");
        return;
    }
    t = *p;
    (*p)->prev->next = (*p)->next;
    *p = (*p)->next;
    free(t);
}

void midDel(struct Node **p, int pos){
    struct Node *t,*q;
    q = *p;
    int c=1;
    if(*p == NULL){
            printf("Empty list");
            return;
    }
    if(pos == 1){
            begDel(p);
    }
    else{
        while(c != pos){
            q = q->next;
            c++;
        }
        t = q;
        q->prev->next = q->next;
        q->next->prev = q->prev;
        free(t);
    }
}
void lastDel(struct Node **p){
    struct Node *t,*q;
    q = *p;
    int c=1;
    if(*p == NULL){
            printf("Empty list");
            return;
    }
    if(q->prev == q->next){
        t = q;
        *p = NULL;
        free(t);
    }
    q = *p;
    q = q->prev;
    t = q;
    q->prev->next = q->next;
    q->next->prev = q->prev;
    free(t);
}

void searchDel(struct Node **p,int ele){
    struct Node *q,*t;
    q = *p;
    if(q->prev == q->next){
        t = q;
        *p = NULL;
        free(t);
    }
    while(q->d != ele){
            q = q->next;
        }
    t = q;
    q->prev->next = q->next;
    q->next->prev = q->prev;
    free(t);
}
