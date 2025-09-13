#include<stdio.h>

struct Node{
    int num;
    struct Node *next;
}*stNode;

void createNodeList(int n){
    struct Node *temp;
    stNode = (struct Node *)malloc(sizeof(struct Node));
    temp = stNode;
    if(stNode == NULL){
        printf("Memory is full");
    }
    printf("Enter data for Node 1: ");
    scanf("%d",&stNode->num);
    stNode->next = NULL;

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

        temp->next = fnNode;
        temp = temp->next;
    }
}

void displayList(){
    struct Node *temp = stNode;
    while(temp != NULL){
        printf("%d\t",temp->num);
        temp = temp->next;
    }
}

void headNodeDeletion(){
    struct Node *temp = stNode;
    stNode = stNode->next;
    printf("\nData in the node deleted is %d",temp->num);
    free(temp);

}

void main(){
    int n;
    printf("Enter the no. of nodes you want to add: ");
    scanf("%d",&n);
    createNodeList(n);
    printf("Data in List is: \n");
    displayList();

    headNodeDeletion();
    printf("\nData in List after head node deletion is: \n");
    displayList();

}
