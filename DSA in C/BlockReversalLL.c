#include<stdio.h>

//NICE FUCKIN LOGIC

struct Node{
    int data;
    struct node *next;
};

void push_node(struct Node **head, int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *head;
    *head = node;
}

void displayList(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *reverse_k_nodes(struct Node *head, int k){
    //printf("%d",head->data);
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    int c = 0;
    while(current != NULL && c < k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        c++;
    }
    if(next != NULL)
        head->next = reverse_k_nodes(next,k);

    return prev;
}

void main(){
    struct Node *head = NULL;
    push_node(&head,1);
    push_node(&head,2);
    push_node(&head,3);
    push_node(&head,4);
    push_node(&head,5);

    displayList(head);

    head = reverse_k_nodes(head,3);

    displayList(head);

}
