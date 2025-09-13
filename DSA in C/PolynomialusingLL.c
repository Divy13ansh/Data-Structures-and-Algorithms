#include<stdio.h>
#include<stdlib.h>

struct Node{
    int c,e;
    struct Node *next;
};

void createNodeList(struct Node **head, int n){
    *head = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node *temp = *head;
    struct Node *fnNode;
    printf("Enter coefficient for the term 1: ");
    scanf("%d",&temp->c);

    printf("Enter exponent for the term 1: ");
    scanf("%d",&temp->e);

    for(int i = 2;i<=n;i++){
        fnNode = (struct Node *)malloc(sizeof(struct Node));
        if(fnNode == NULL){
            printf("List is empty");
            break;
        }
        printf("Enter coefficient for term %d: ",i);
        scanf("%d",&fnNode->c);
        printf("Enter exponent for term %d: ",i);
        scanf("%d",&fnNode->e);

        fnNode->next = NULL;

        temp->next = fnNode;
        temp = temp->next;
    }
}

void display(struct Node * head){
    struct Node *temp = head;
    while(temp!= NULL){
        printf("%dx^%d + ",temp->c, temp->e);
        temp = temp->next;
    }
}

void solve1(struct Node *head){
    struct Node *temp = head;
    int s = 0;
    while(temp != NULL){
        int pr = 1;
        for(int i=0;i<temp->e;i++){
            pr *= temp->c;
        }
        s+=pr;
        temp = temp->next;
    }
    printf("%d\n",s);
}

void solve2(struct Node *head){
    struct Node *temp = head;
    int x;
    int s = 0;

    printf("Enter the value of x: ");
    scanf("%d",&x);

    while(temp != NULL){
        int pr = 1;
        for(int i = 0;i<temp->e;i++){
            pr *= x;
        }
        s += temp->c*pr;
        temp = temp->next;
    }
    printf("%d\n",s);
}

void solve3(struct Node *head){
    struct Node *temp = head;
    int x;
    int s = 0;
    char sgn;

    printf("Enter the value of x: ");
    scanf("%d",&x);

    while(temp!=NULL){
        int pr = 1;
        for(int i = 0;i<temp->e;i++){
            pr*=x;
        }
        printf("Enter the sign(+ or -): ");
        scanf(" %c",&sgn);
        if(sgn == '+'){
            s+=temp->c*pr;
        }
        else{
            s-=temp->c*pr;
        }
        temp = temp->next;
    }
    printf("%d\n",s);
}


void main(){
    int i,j,k=1,ch,n;
    struct Node *Anode;
    while(k){
        printf("\n1. Create Poly 1\n2. Display Poly 1\n3. Solve 1\n4. Solve 2\n5. Solve 3\nEnter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
        case 1:
            printf("Enter no. of terms: ");
            scanf("%d",&n);
            createNodeList(&Anode, n);
            break;

        case 2:
            display(Anode);
            break;

        case 3:
            solve1(Anode);
            break;

        case 4:
            solve2(Anode);
            break;
        case 5:
            solve3(Anode);
            break;
        }
    }
}
