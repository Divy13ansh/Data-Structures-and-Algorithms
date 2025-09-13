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

void detect_and_remove_Loop(struct Node *head){
    struct Node *slow = head, *fast = head;

    //using floyd's loop detection algorithm
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) break;

    }
    if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

void displayList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    struct Node *head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);

    printf("Original List: \n");
    displayList(head);

    //creating a loop
    head->next->next->next->next->next = head->next->next;

    //displaying the loop
    //displayList(head);


    //removing the loop
    detect_and_remove_Loop(head);
    displayList(head);



}
