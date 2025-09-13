#include<stdio.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * new_node(int data){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node * reverse_list(struct Node *head){
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next1 = NULL;
    struct Node *temp = NULL;

    while(current){
        next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
    }
    return prev;

};

bool isPalin(struct Node *head){
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *midNode = NULL;
    struct Node *temp = NULL;
    bool res = true;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast == NULL){
        midNode = slow;
    }
    else{
        midNode = slow->next;
    }

    temp = reverse_list(midNode);
    disp_list(temp);
    printf("\n");

    while(temp != NULL){
        if(head != temp){
            res = false;
            break;
        }
        head = head->next;
        temp = temp->next;
    }
    return res;
}

void disp_list(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
}

void main(){
    struct Node *head;
    head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(3);
    head->next->next->next->next->next = new_node(2);
    head->next->next->next->next->next->next = new_node(1);

    disp_list(head);
    printf("\n");

    if(isPalin(head)){
        printf("is palin\n");
    }
    else{
        printf("is not palin\n");
    }




}
