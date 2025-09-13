#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    struct Node *next;
    struct Node *prev;
}*stNode, *enNode;

void createNodeList(int n){
    stNode = (struct Node *)malloc(sizeof(struct Node));
    if(stNode == NULL){
        printf("Memory is full");
        return;
    }
    printf("Enter data for Node 1: ");
    scanf("%d",&stNode->num);
    stNode->prev = NULL;
    stNode->next = NULL;
    enNode = stNode;

    for(int i = 2;i<=n;i++){
        struct Node *fnNode;
        fnNode = (struct Node *)malloc(sizeof(struct Node));
        if(fnNode == NULL){
            printf("Memory is full");
            break;
        }

        printf("Enter data for Node %d: ",i);
        scanf("%d",&fnNode->num);
        fnNode->next = NULL;
        fnNode->prev = enNode;

        enNode->next = fnNode;
        enNode = enNode->next;
    }

}

void displayList(){
    struct Node *temp = stNode;
    while(temp != NULL){
        printf("%d\t",temp->num);
        temp = temp->next;
    }
    printf("\n");
    temp = enNode;
    while(temp != NULL){
        printf("%d\t",temp->num);
        temp = temp->prev;
    }
}


void main(){
    int n;
    printf("Enter the no. of Nodes: ");
    scanf("%d",&n);
    createNodeList(n);
    displayList();
}
