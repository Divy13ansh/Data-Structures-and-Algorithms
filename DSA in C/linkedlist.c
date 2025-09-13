#include<stdio.h>
#include<stdlib.h>
struct Node{
      int d;
      struct Node *next;
};
int main(){
      void create(struct Node*);
      void disp(struct Node*);
      int count(struct Node*,int);
      int sum(struct Node*,int);
      void insert(struct Node*,int,int);
      struct Node * begins(struct Node *);
      void midins(struct Node *,int,int);
      void lastins(struct Node *);
      struct Node * bigdel(struct Node *);
      void middel(struct Node *,int ,int );
      void lastdel(struct Node *);
      int search(struct Node *,int,int);
    struct Node*head;
    int i,j,k=1,ch,num,s,pos,ch1,ele;
    head=(struct Node*)malloc(sizeof(struct Node));
    while(k){
        printf("\nMenu\n1. create\n2. display\n3. count\n4. sum\n5. insert\n6. delete\n7. search\n8 exit\n enter your choice=");
        scanf("%d",&ch);
        switch(ch){
    case 1:
        create(head);
        break;
    case 2:
        disp(head);
        break;
    case 3:
        i=count(head,0);
        printf("total nodes=%d\n",i);
        break;
    case 4:
        i=sum (head,0);
        printf("sum is=%d\n",i);
        break;
    case 5:
        printf("menu\n1.begins\n2.middle\n3.last\nenter ur choice=");
        scanf("%d",&ch1);
        switch(ch1){
            case 1:
                head=begins(head);
                break;
            case 2:
                printf("enter pos after u wants to insert a Node");
                scanf("%d",&pos);
                if(pos>count(head,0))
                    printf("out of reach");
                else{
                    midins(head,pos,0);
                    break;
                }
            case 3:
                lastins(head);
                break;
        }
        break;
    case 6:
        printf("menu\n1.bigdel\n2.middel\n3.lastdel\nenter ur choice=");
        scanf("%d",&ch1);
        switch(ch1){
            case 1:
                head=bigdel(head);
                break;
            case 2:
                printf("enter Node no u want to del=");
                scanf("%d",&pos);
                if(pos>count(head,0))
                    printf("out of reach");
                else{
                    middel(head,pos,0);
                }
                break;
            case 3:
                lastdel(head);
                break;
        }
        break;
    case 7:
        printf("enter searching ele=");
        scanf("%d",&ele);
        i=search(head,ele,0);
        if(i!=-1)
            printf("found at %d pos",i);
        break;
    case 8:
        k=0;
        break;
    default:
        printf("wrong choice");
        }
    }
}
void create(struct Node *p){
          int ch;
          printf("enter data=");
          scanf("%d",&p->d);
          printf("enter more 1 for yes 0 for no= ");
          scanf("%d",&ch);
          if(ch==1){
            p->next=(struct Node*)malloc(sizeof(struct Node));
            create(p->next);
          }
          else{
            p->next=NULL;
          }
}
void disp(struct Node *p){
    printf("%d\t",p->d);
    if(p->next!=NULL){
        disp(p->next);
    }
}
int count(struct Node *p,int c){
    c++;
    if(p->next!=NULL)
        count(p->next,c);
    else
        return(c);
}
int sum (struct Node *p,int s){
    s=s+p->d;
    if(p->next!=NULL)
        sum(p->next,s);
    else
        return(s);
}
struct Node * begins(struct Node *p){
    struct Node *t;
    t=(struct Node *)malloc (sizeof(struct Node));
    if(t==NULL){
        printf("memory is full");
        return;
    }
    printf("enter new ele=");
    scanf("%d",&t->d);
    t->next=p;
    return t;
}
void midins(struct Node *p,int pos,int c){
    c++;
    if(pos!=c){
        midins(p->next,pos,c);
    }
    else{
        struct Node *t;
         t=(struct Node *)malloc (sizeof(struct Node));
         if(t==NULL){
            printf("memory is full");
            return;
         }
         printf("enter data");
         scanf("%d",&t->d);
         t->next=p->next;
         p->next=t;

    }
}
void lastins(struct Node *p){
    if(p->next!=NULL){
        lastins(p->next);
    }
    else{
        struct Node *t;
        t=(struct Node *)malloc (sizeof(struct Node));
        if(t==NULL){
            printf("memory is full");
            return;
        }
        printf("enter data");
        scanf("%d",&t->d);
        t->next=NULL;
        p->next=t;
    }
}
struct Node * bigdel(struct Node *p){
    struct Node *t;
    t=p;
    p=p->next;
    free(t);
    return p;
}
void middel(struct Node *p,int pos,int c){
    c++;
    if((pos-1)!=c){
        middel(p->next,pos,c);
    }
    else{
        struct Node *t;
        t=p->next;
        p->next=p->next->next;
        free(t);
    }
}
void lastdel(struct Node *p){
    if(p->next->next!=NULL)
        lastdel(p->next);
    else{
        struct Node *t;
        t=p->next;
        p->next=NULL;
        free(t);
    }
}
int search(struct Node *p, int ele, int pos){
    pos++;
    if(p->d != ele){
        search(p->next,ele,pos);
    }
    else
        return pos;
}
