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
    void begdel(struct Node **);
    void middel(struct Node **,int);
    void lastDel(struct Node *);
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
                begdel(&head);
                break;
            case 8:
                printf("Enter pos: ");
                scanf("%d",&pos);
                middel(&head,pos);
                break;
            case 9:
                lastDel(head);
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
    if(t==NULL){
        printf("Memory full");
        return;
    }
    t->d = ele;
    if(*p==NULL){
        t->next = NULL;
        t->prev = NULL;
        *p = t;
    }
    else{
        q = *p;
        while(q->next != NULL){
            q = q->next;
        }
       t->prev = q;
       t->next = NULL;
       q->next = t;
    }
}
void disp(struct Node *p){
          if(p == NULL){
            printf("List is empty");
            return;
          }
          while(p != NULL){
            printf("%d\t",p->d);
            p = p->next;
          }
}
void rev_disp(struct Node *p){
    if(p == NULL){
        printf("List is empty");
        return;
    }
    while(p->next != NULL){
        p = p->next;
    }
    while(p!=NULL){
        printf("%d\t",p->d);
        p = p->prev;
    }
}

void begIns(struct Node **p,int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Memory full");
        return;
    }
    t->d = ele;
    t->next = *p;
    t->prev = NULL;
    (*p)->prev = t;
    *p = t;
}

void midIns(struct Node **p,int pos,int ele){
    int c=1,ch;
    struct Node *t,*q;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory full");
        return;
    }
    t->d = ele;
    if(pos == 1){
        printf("\nMenu\n1. After\n2. Before\nEnter Your Choice: ");
        scanf("%d",&ch);
        if(ch==1){
            t->next = (*p)->next;
            t->prev = *p;
            (*p)->next->prev = t;
            (*p)->next = t;
        }
        else if(ch==2){
            t->next = *p;
            t->prev = NULL;
            (*p)->prev = t;
            *p = t;
        }
    }
    else{
        q = *p;
        int c = 1;
        while(c!=pos){
            q = q->next;
            c++;
        }
        if(q->next == NULL){
            printf("\nMenu\n1. Before pos\n2. after pos\nEnter Your Choice: ");
            scanf("%d",&ch);

            if(ch==1){
                t->next = q;
                t->prev = q->prev;
                q->prev->next = t;
                q->prev = t;
            }
            else if(ch==2){
                t->next = NULL;
                t->prev = q;
                q->next = t;
            }
        }
        else{
            printf("\nMenu\n1. Before pos\n2. after pos\nEnter Your Choice: ");
            scanf("%d",&ch);
            if(ch==1){
                t->next = q;
                t->prev = q->prev;
                q->prev->next = t;
                q->prev = t;
            }
            else if(ch==2){
                t->next = q->next;
                t->prev = q;
                q->next->prev = t;
                q->next = t;
            }
        }
    }
}
void begdel(struct Node **p){
    struct Node *t;
    if(*p == NULL){
        printf("Empty list");
        return;
    }
    t = *p;
    t->next->prev = NULL;
    *p = (*p)->next;
    free(t);
}

void middel(struct Node **p,int pos){
    struct Node *t,*q;
    int ch;
    if(*p == NULL){
        printf("Empty list");
        return;
    }
    if(pos == 1){
        printf("\nMenu\n1. Itself\n2. after\nEnter Your Choice: ");
        scanf("%d",&ch);
        if(ch==1){
            t = *p;
            t->next->prev = NULL;
            *p = t->next;
            free(t);
        }
        else if(ch==2){
            (*p)->next->next->prev = *p;
            (*p)->next = (*p)->next->next;
        }
    }
    else{
        q = *p;
        int c = 1;
        while(c != pos){
            q = q->next;
            c++;
        }
        if(q->next == NULL){
            printf("\nMenu\n1. Itself\n2. Before\nEnter Your Choice: ");
            scanf("%d",&ch);
            if(ch == 1){
                q->prev->next = NULL;
                free(q);
            }
            else if(ch == 2){
                t = q->prev;
                q->prev->prev->next = q;
                q->prev = q->prev->prev;
                free(t);
            }
        }
        else{
            printf("\nMenu\n1. Itself\n2. After pos\n3. Before pos\nEnter Your Choice: ");
            scanf("%d",&ch);
            if(ch==1){
                q->prev->next = q->next;
                q->next->prev = q->prev;
            }
            else if(ch == 2){
                q->next->next->prev = q;
                q->next = q->next->next;
            }
            else{
                q->prev->prev->next = q;
                q->prev = q->prev->prev;
            }
        }
    }
}

void lastDel(struct Node *p){
    if(p == NULL){
        printf("List Empty");
        return;
    }
    while(p->next != NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
}

void searchDel(struct Node **p,int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    while((*p)->d != ele){
        p = (*p)->next;
    }
    t = *p;
    (*p)->prev->next = (*p)->next;
    (*p)->next->prev = (*p)->prev;
    free(t);
}
