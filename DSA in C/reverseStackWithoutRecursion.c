#include<stdio.h>
#include<stdlib.h>
struct Node{
    int a;
    struct Node *next;
};

void generate(struct Node **);
void display(struct Node *);
void stack_reverse(struct Node **);
void del(struct Node **);
void main(){
    struct Node *head = NULL;

    generate(&head);
    printf("\nThe Sequence of contents in stack\n");
    display(head);
    printf("\nInversing the contents of the stack\n");
    stack_reverse(&head);
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
    while(p!= NULL){
        printf("%d\t",p->a);
        p = p->next;
    }
}

void stack_reverse(struct Node **p){
    struct Node *temp,*prev;
    if(*p == NULL){
        printf("Stack does not exist\n");
    }
    else if((*p)->next == NULL){
        printf("Single Node stack reversal brings no difference\n");
    }
    else if((*p)->next->next == NULL){
        (*p)->next->next = *p;
        (*p) = (*p)->next;
        (*p)->next->next = NULL;
    }
    else{
        prev = *p;
        temp = (*p)->next;
        *p = (*p)->next->next;
        prev->next = NULL;
        while((*p)->next != NULL){
            temp->next = prev;
            prev = temp;
            temp = *p;
            *p = (*p)->next;
        }
        temp->next = prev;
        (*p)->next = temp;
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
