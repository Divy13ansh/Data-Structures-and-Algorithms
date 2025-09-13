#include <stdio.h>
#include <stdlib.h>
struct Node{
    int d;
    struct Node *next;
};
void main() {
    void add(struct Node **,int);
    void disp(struct Node *);
    int count(struct Node *,int);
    int sum(struct Node *,int);
    struct Node *begins(struct Node *,int);
    void midins(struct Node *,int,int,int);
    void lastins(struct Node *,int);
    struct Node *begdel(struct Node *);
    struct Node *head;
    head = (struct Node*)malloc(sizeof(struct Node));
    int i,j,k=1,ch,ele,pos,s,c;
    while(k){
        printf("\nMenu\n1. Create\n2. Display\n3. count\n4. sum\n5. insert\n6. del\n7. Search\n8. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                add(head);
                break;
            case 2:
                disp(head);
                break;
            case 3:
                c = count(head,0);
                printf("%d",c);
                break;
            case 4:
                s = sum(head,0);
                printf("%d",s);
                break;
            case 5:
                int ch1;
                printf("Enter element: ");
                scanf("%d",&ele);

                printf("\nMenu\n1. Begins\n2. Midins\n3. Lastins\nEnter Your Choice: ");
                scanf("%d",&ch1);
                switch(ch1){
                    case 1:
                        head = begins(head,ele);
                        break;
                    case 2:
                        printf("Enter position to insert at: ");
                        scanf("%d",&pos);
                        midins(head,pos,ele,0);
                        break;
                    case 3:
                        lastins(head,ele);
                        break;
                }
                break;
            case 6:
                int ch2;
                printf("\nMenu\n1. Begdel\n2. Middel\n3. Lastdel\nEnter Your Choice: ");
                scanf("%d",&ch2);
                switch(ch2){
                    case 1:
                        head = begdel(head);
                }
        }
    }

}
void create(struct Node *p){
    int c;
    printf("Enter Element: ");
    scanf("%d", &p->d);

    printf("Do you want to add more elements\n1 for YES\n2 for NO\nEnter Your choice: ");
    scanf("%d",&c);
    if(c == 1){
        p->next = (struct Node *)malloc(sizeof(struct Node));
        create(p->next);
    }
    else{
        p->next = NULL;
    }
}

void disp(struct Node *p){
    printf("%d ",p->d);
    if(p->next != NULL){
        disp(p->next);
    }
}

int count(struct Node *p, int c){
    c++;
    if(p->next != NULL){
        count(p->next,c);
    }
    else{
        return c;
    }
}

int sum(struct Node *p,int s){
    s = s + p->d;
    if(p->next != NULL){
        sum(p->next,s);
    }
    else{
        return s;
    }
}
struct Node *begins(struct Node *p,int ele){
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Memory is full");
        return p;
    }
    t->d = ele;
    t->next = p;
    return t;
}
void midins(struct Node *p,int pos,int ele,int c){
    c++;
    if((pos-1) != c){
        midins(p->next,pos,ele,c);
    }
    else{
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        if(t == NULL){
            printf("Memory Full");
            return;
        }
        else{
            t->d = ele;
            t->next = p->next;
            p->next = t;
        }
    }
}
void lastins(struct Node *p,int ele){
    if(p->next != NULL){
        p = p->next;
        lastins(p->next,ele);
    }
    else{
        struct Node *t;
        t = (struct Node*)malloc(sizeof(struct Node));
        if(t == NULL){
            printf("Memory full");
            return;
        }
        else{
            t->d = ele;
            t->next = NULL;
            p->next = t;
        }
    }
}
struct Node *begdel(struct Node *p){
    struct Node *t;
    t->next = p->next;
    t->d = p->d;
    free(t);
    return p->next;

}
// struct Node *middel(struct Node *p)
