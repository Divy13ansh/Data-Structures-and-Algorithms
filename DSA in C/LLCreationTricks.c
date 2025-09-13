#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    struct Node *nextptr;
}*stnode;

void createNodeList(int n){

}

void displayList(){

}

void main(){
    int n;

    //Input no. of nodes for LL
    printf("Input the no. of nodes: ");
    scanf("%d",&n);

    //Creating LL with n nodes
    createNodeList(n);

    printf("The data entered in the list is: \n");
    displayList();
}

void createNodeList(int n){
    struct node *fnNode, *tmp;
    int num, i;

    //Allocating memory for the starting node
    stnode = (struct Node*)malloc(sizeof(struct Node));

    if(stnode == NULL){
        printf("Memory can not be allocated");
        return;
    }
    else{
        printf("Input data for node 1: ");
        scanf("%d", &num);

        stnode->num = num;
        stnode->nextptr = NULL;
        tmp = stnode;

        for(i = 2;i<=n;i++){
            fnnode = (struct Node *)malloc(sizeof(struct Node));

            if(fnNode == NULL){
                printf("Memory can not be allocated");
                break;
            }
            else{
                printf("Input data for node %d",i);
                scanf("%d",&fnNode->num);
                fnNode->nextptr = NULL;

                tmp->nextptr = fnNode;
                tmp = tmp->nextptr;
            }
        }
    }
}

void displayList(){
    struct Node *tmp;
    if(stnode == NULL){
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
