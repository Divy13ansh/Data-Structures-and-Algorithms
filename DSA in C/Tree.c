#include <stdio.h>

struct Node{
    int d;
    struct Node *lc;
    struct Node *rc;
};

char a[] = {'a','b','c','d','e','f','g','\0','\0','h'};
int lc[] = {1,3,5,-1,9,-1,-1,-1,-1,-1};
int rc[] = {2,4,6,-1,-1,-1,-1,-1,-1,-1};

void main(){
    struct Node *buildtree(int);
    void inorder(struct Node *);
    void preorder(struct Node *);
    void postorder(struct Node *);
    struct Node * root;
    int i,j,k=1,ch;
    while(k){
        printf("\nMenu\n1. Build Tree\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                root = buildtree(0);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                k = 0;
                break;
        }
    }
}

struct Node *buildtree(int i){
    struct Node *t = NULL;
    if(i != -1){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->lc = buildtree(lc[i]);
        t->d = a[i];
        t->rc = buildtree(rc[i]);
    }
    return(t);
}

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->lc);
        printf("%c\t",root->d);
        inorder(root->rc);
    }
    return;
}

void preorder(struct Node *root){
    if(root != NULL){
        printf("%c\t",root->d);
        preorder(root->lc);
        preorder(root->rc);
    }
    return;
}

void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->lc);
        postorder(root->rc);
        printf("%c\t",root->d);
    }
    return;
}

