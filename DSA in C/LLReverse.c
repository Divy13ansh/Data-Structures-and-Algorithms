#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    struct Node *nextptr;
}*stNode;

void createNodeList(int n);

void reverseDispList();

void displayList();
void main(){
    int n;

    printf("Input the no. of nodes: ");
    scanf("%d", &n);

    createNodeList(n);

    printf("Data in the list is: \n");

    displayList();

    reverseDispList();

    printf("Data in the reversed list is: \n");
    displayList();
}

void createNodeList(int n){
    struct Node *fnNode, *tmp;
    int num, i;

    stNode = (struct Node *)malloc(sizeof(struct Node));

    if(stNode == NULL){
        printf("Memory can't be allocated");
    }
    else{
        printf("input data for node 1: ");
        scanf("%d", &stNode->num);
        stNode->nextptr = NULL;
        tmp = stNode;

        for(i=2;i<=n;i++){
            fnNode = (struct Node *)malloc(sizeof(struct Node));
            if(fnNode == NULL){
                printf("Memory is full");
                break;
            }

            else{
                printf("Input data for node %d: ", i);
                scanf("%d", &fnNode->num);

                fnNode->nextptr = NULL;

                tmp->nextptr = fnNode;
                tmp = tmp->nextptr;
            }
        }
    }
}

void reverseDispList(){
    struct Node *prevNode, *curNode;

    if(stNode == NULL){
        printf("List is Empty");
    }
    else{
        prevNode = stNode;
        curNode = stNode->nextptr;
        stNode = stNode->nextptr;

        prevNode->nextptr = NULL;
    }
    while(stNode != NULL){
        stNode = stNode->nextptr;
        curNode->nextptr = prevNode;

        prevNode = curNode;
        curNode = stNode;
    }
    stNode = prevNode;
}

void displayList(){
    struct Node *tmp;

    if(stNode == NULL){
        printf("List is empty");
    }
    else{
        tmp = stNode;
        while(tmp != NULL){
            printf("Data = %d\n", tmp->num);
            tmp = tmp->nextptr;
        }
    }
}
