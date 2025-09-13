#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    struct Node *next;
}*stNode;

void createNodeList(int n){
    stNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fnNode, *temp;
    temp = stNode;
    if(stNode == NULL){
        printf("Memory is full");
        return;
    }
    printf("Enter data for node 1: ");
    scanf("%d",&stNode->num);
    stNode->next = NULL;

    for(int i = 2;i<=n;i++){
        fnNode = (struct Node *)malloc(sizeof(struct Node));
        if(fnNode == NULL){
            printf("Memory is full");
            break;
        }
        else{
            printf("Enter data for node %d: ",i);
            scanf("%d",&fnNode->num);
            fnNode->next = NULL;

            temp->next = fnNode;
            temp = temp->next;
        }
    }
}

void displayList(){
    struct Node *temp = stNode;
    while(temp!=NULL){
        printf("%d\t", temp->num);
        temp = temp->next;
    }
}

void appendNode(){
    struct Node *temp = stNode;

    struct Node *fnNode;
    fnNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data for node to append: ");
    scanf("%d",&fnNode->num);
    fnNode->next = NULL;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = fnNode;
}

void main(){
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);

    createNodeList(n);

    displayList();

    appendNode();

    displayList();
}
