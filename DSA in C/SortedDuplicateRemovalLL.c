#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *new_node(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void displayList(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *removeDuplicates(struct Node *head){
    struct Node *temp = head;
    struct Node *t1;
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            t1 = temp->next;
            temp->next = temp->next->next;
            free(t1);
        }
        else{
        temp = temp->next;
        }
    }
    return head;
}

void main(){
    struct Node *l1 = new_node(1);
    l1->next = new_node(1);
    l1->next->next = new_node(1);
    l1->next->next->next = new_node(2);
    l1->next->next->next->next = new_node(2);
    l1->next->next->next->next->next = new_node(3);

    displayList(l1);

    struct Node *head;
    head = removeDuplicates(l1);
    displayList(head);
}
