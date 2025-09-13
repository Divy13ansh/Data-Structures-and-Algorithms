#include<stdio.h>

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

struct Node *conditionalRemoval(struct Node *head, int k){
    struct Node *temp = head;
    struct Node *t1;
    while(temp->next != NULL){
        if(temp->next->data > k){
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
    struct Node *head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);
    head->next->next->next->next->next = new_node(2);
    head->next->next->next->next->next->next = new_node(7);

    displayList(head);
    head = conditionalRemoval(head,3);
    displayList(head);
}
