#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

struct Node *reverseList(struct Node *head){
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(struct Node *head){
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prev_slow = head;
    struct Node *midnode = NULL;
    bool res = true;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast != NULL){
        midnode = slow;
        slow = slow->next;
    }

    slow = reverseList(slow);
    fast = head;
    while(slow != NULL){
        if(fast->data != slow->data){
            res = false;
            break;
        }

        fast = fast->next;
        slow = slow->next;
    }
    slow = reverseList(slow);

    if(midnode != NULL){
        prev_slow->next = midnode;
        midnode->next = slow;
    }
    else{
        prev_slow->next = slow;
    }
    return res;
}

void displayList(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

void main(){
    struct Node *head1 = new_node(1);
    head1->next = new_node(2);
    head1->next->next = new_node(3);
    head1->next->next->next = new_node(4);
    head1->next->next->next->next = new_node(5);

    displayList(head1);

    if(isPalindrome(head1)){
        printf("List is palindrome");
    }
    else{
        printf("List is not palindrome");
    }
}
