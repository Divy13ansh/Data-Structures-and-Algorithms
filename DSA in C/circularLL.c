#include<stdio.h>
#include<stdlib.h>
struct Node{
int d;
struct Node *next;
};
void main(){
    int i,j,k=1,s,ch,ele,pos,c;
    struct Node *f, *r;
    void add(struct Node **,struct Node **,int);
    void disp(struct Node *, struct Node *);
    int count(struct Node *, struct Node *);
    int sum(struct Node *, struct Node *);
    void begins(struct Node **, struct Node **, int);
    void midins(struct Node *, struct Node **, int, int);
    void lastins(struct Node **, struct Node **, int);
    void begdel(struct Node **, struct Node **);
    void middel(struct Node **, struct Node **,int);
    f = r = NULL;
    while(k){
        printf("\nMenu\n1. Add\n2. Display\n3. Count\n4. Sum\n5. Insert\n6. Delete\n7.Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                add(&f,&r,ele);
                break;
            case 2:
                disp(f,r);
                break;
            case 3:
                c = count(f,r);
                printf("%d",c);
                break;
            case 4:
                s = sum(f,r);
                printf("%d",s);
                break;
            case 5:
                int ch1;
                printf("\nMenu\n1. begins\n2. midins\n3. lastins\nEnter Your Choice: ");
                scanf("%d", &ch1);
                printf("Enter element: ");
                scanf("%d",&ele);
                switch(ch1){
                    case 1:
                        begins(&f,&r,ele);
                        break;
                    case 2:
                        printf("Enter position to insert: ");
                        scanf("%d",&pos);
                        midins(f,&r,ele,pos);
                        break;
                    case 3:
                        lastins(&f,&r,ele);
                        break;
                }
                break;
            case 6:
                int ch2,pos;
                printf("\nMenu\n1. begdel\n2. middel\n3. lastdel\nEnter your choice: ");
                scanf("%d",&ch2);
                switch(ch2){
                    case 1:
                        begdel(&f,&r);
                        break;
                    case 2:
                        printf("Enter position of node to delete: ");
                        scanf("%d",&pos);
                        middel(&f,&r,pos);
                }
        }
    }

}
void add(struct Node **f,struct Node **r, int ele){
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory full");
        return;
    }
    t->d = ele;
    if(*f == NULL){
        *f = t;
        *r = t;
        t->next = *r;
    }
    else{
        (*r)->next = t;
        *r = t;
    }
    t->next = (*f);
}
void disp(struct Node *f, struct Node *r){
    if(f==NULL){
        printf("Empty list");
        return;
    }
    do{
        printf("%d\t",f->d);
        f = f->next;
    }
    while(f != r->next);
}
int count(struct Node *f, struct Node *r){
    int c = 0;
    do{
        c++;
        f = f->next;
    }
    while(f != r->next);
    return c;
}
int sum(struct Node *f, struct Node *r){
    int s = 0;
    do{
        s += f->d;
        f = f->next;
    }
    while(f != r->next);
    return s;
}
void begins(struct Node **f, struct Node **r, int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory full");
        return;
    }
    t->d = ele;
    t->next = *f;
    *f = t;
    (*r)->next = *f;
}
void midins(struct Node *f, struct Node **r, int ele, int pos){
    int c = 1;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory full");
        return;
    }
    t->d = ele;
    while(pos != c){
        f = f->next;
        c++;
    }
    if(f->next == (*r)->next){
        t->next = f->next;
        f->next = t;
        *r = t;
    }
    else{
        t->next = f->next;
        f->next = t;
    }
}
void lastins(struct Node**f, struct Node **r, int ele){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Memory Full");
        return;
    }
    t->d = ele;
    t->next = (*r)->next;
    (*r)->next = t;
    *r = t;
}
void begdel(struct Node **f,struct Node **r){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Memory full");
        return;
    }
    t->d = (*f)->d;
    t->next = (*f)->next;
    (*f) = (*f)->next;
    (*r)->next = *f;
    free(t);
}
void middel(struct Node **f,struct Node **r, int pos){
    int c = 1;
    struct Node *t,*ft = *f;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Memory full");
        return;
    }
    while((pos-1)!=c){
        ft = ft->next;
        c++;
    }
    if(ft == *f){
        *f = *f->next
        *ft->next = *f;
    }
}
