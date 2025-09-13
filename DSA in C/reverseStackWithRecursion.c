#include<stdio.h>
#include<stdlib.h>
struct Node{
    int a;
    struct Node *next;
};

void generate(struct Node **);
void display(struct Node *);
void stack_reverse(struct Node **, struct Node **);
void del(struct Node **);
void main(){
    struct Node *head = NULL;

    generate(&head);
    printf("\nThe Sequence of contents in stack\n");
    display(head);
    printf("\nInversing the contents of the stack\n");
    stack_reverse(&head, &(head->next));
    printf("\nThe contents in stack after reversal\n");
    display(head);
    del(&head);
}

void generate(struct Node **p){
    struct Node *t;
    int i,l;
    printf("Enter length of list: ");
    scanf("%d",&l);
    for(i=l;i>0;i--){
        t = (struct Node *)malloc(sizeof(struct Node));
        if(t == NULL){
            printf("Memory Full");
            return;
        }
        t->a = i;
        if(*p == NULL){
            t->next = NULL;
            *p = t;
        }
        else{
            t->next = *p;
            *p = t;
        }
    }
}

void display(struct Node *p){
    if(p!= NULL){
        printf("%d\t",p->a);
        display(p->next);
    }
}

void stack_reverse(struct Node **p, struct Node **pn){
    struct Node *temp;
    if(*pn != NULL){
        temp = (*pn)->next;
        (*pn)->next = *p;
        *p = *pn;
        *pn = temp;
        stack_reverse(p,pn);
    }
}

void del(struct Node **head){
    struct Node *t;
    while(*head != NULL){
        t = *head;
        *head = (*head)->next;
        free(t);
    }
}
