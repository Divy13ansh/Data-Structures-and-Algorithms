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

struct Node *alternateSwap(){

}

void main(){
    struct Node *l1 = new_node(1);
    l1->next = new_node(2);
    l1->next->next = new_node(3);
    l1->next->next->next = new_node(4);
    l1->next->next->next->next = new_node(5);
    l1->next->next->next->next->next = new_node(6);

    displayList(l1);
}
