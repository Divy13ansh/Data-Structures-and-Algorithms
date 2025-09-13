#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* new_node(int data){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node * mergeTwoLists(struct Node *h1, struct Node *h2){
    struct Node *t1 = h1, *t2 = h2;

    struct Node *neew;
    neew = (struct Node *)malloc(sizeof(struct Node));
    if(t1->data > t2->data){
        neew->data = t2->data;
        t2 = t2->next;
    }
    else{
        neew->data = t1->data;
        t1 = t1->next;
    }

    struct Node *temp = neew;

    while(t1 != NULL && t2 != NULL){
        if(t1->data > t2->data){
            temp->next = new_node(t2->data);
            temp = temp->next;
            t2 = t2->next;
        }
        else{
            temp->next = new_node(t1->data);
            temp = temp->next;
            t1 = t1->next;
        }
    }

    if(t1 != NULL){
        while(t1 != NULL){
            temp->next = new_node(t1->data);
            t1 = t1->next;
            temp = temp->next;
        }
    }
    if(t2 != NULL){
        while(t2 != NULL){
            temp->next = new_node(t2->data);
            t2 = t2->next;
            temp = temp->next;
        }
    }


    return neew;
}

void displayList(struct Node *h){
    struct Node *temp = h;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}



void main(){
    int n;

    struct Node *a = new_node(1);
    a->next = new_node(3);
    a->next->next = new_node(5);

    struct Node *b = new_node(2);
    b->next = new_node(4);
    b->next->next = new_node(6);

    struct Node *c = mergeTwoLists(a,b);

    displayList(a);
    printf("\n");
    displayList(b);
    printf("\n");
    displayList(c);
}
