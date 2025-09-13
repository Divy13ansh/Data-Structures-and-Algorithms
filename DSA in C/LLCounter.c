#include<stdio.h>

struct Node{
    int num;
    struct Node *nextptr;
}*stNode;

void createNodeList(int n){
    struct Node *fnNode, *temp;
    stNode = (struct Node *)malloc(sizeof(struct Node));
    temp = stNode;
    if(stNode == NULL){
        printf("Memory is full");
        return;
    }
    else{
        printf("Enter data for node 1: ");
        scanf("%d",&stNode->num);
        stNode->nextptr = NULL;

        for(int i = 2;i<=n;i++){
            fnNode = (struct Node *)malloc(sizeof(struct Node));
            if(fnNode == NULL){
                printf("Memory full");
                break;
            }

            printf("Enter data for node %d: ",i);
            scanf("%d",&fnNode->num);

            fnNode->nextptr = NULL;

            temp->nextptr = fnNode;
            temp = temp->nextptr;
        }
    }

}

int counter(){
    int c = 0;
    struct Node *temp = stNode;
    if(stNode == NULL){
        printf("The list is empty");
        return;
    }
    else{
        while(temp != NULL){
            c++;
            temp = temp->nextptr;
        }
    }
    return c;
}

void displayList(){
    struct Node *temp = stNode;
    if(stNode == NULL){
        printf("List is empty");
        return;
    }
    else{
        while(temp != NULL){
            printf("%d\t",temp->num);
            temp = temp->nextptr;
        }
    }
}
void main(){
    int n;
    printf("Enter no. of nodes for list: ");
    scanf("%d", &n);

    createNodeList(n);

    displayList();
    printf("\n");

    printf("No. of nodes in the list is %d", counter());



}


