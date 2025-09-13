#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
struct cheadnode{
    struct cheadnode *next;
    int colno;
    struct Node *down;
};

struct rheadnode{
    struct rheadnode *next;
    int rowno;
    struct Node *right;
};

struct Node{
    int row,col,val;
    struct Node *down,*right;
};

struct spmat{
    int noofrows,noofcols;
    struct rheadnode *firstrow;
    struct cheadnode *firstcol;
};

struct sparse{
    int *sp;
    int nor;
    struct spmat *smat;
    struct cheadnode *chead[COL];
    struct rheadnode *rhead[ROW];
    struct Node *nd;
};
void insert(struct sparse *,struct spmat *,int,int,int);

void main(){
    void initialize(struct sparse *);
    void create_matrix(struct sparse *);
    void display_matrix(struct sparse *);
    int count(struct sparse *);
    void create_tuple(struct sparse,struct sparse *);
    void disp_tuple(struct sparse *);
    void create_list(struct sparse *);
    void disp_list(struct sparse *);
    void del_sparse(struct sparse *);
    int i,j,k=1,ch;

    struct sparse A,B;
    while(k){
        printf("\nMenu\n1. Initialize 1st sparse\n2. Initialize 2nd sparse\n3. Create Matrix\n4. Display Matrix\n5. Count\n6. Create Tuple\n7. Display Tuple\n8. Create List\n9. Display list\n10. Delete sparse\n11. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                initialize(&A);
                break;
            case 2:
                initialize(&B);
                break;
            case 3:
                create_matrix(&A);
                break;
            case 4:
                display_matrix(&A);
                break;
            case 5:
                i = count(&A);
                printf("%d",i);
                break;
            case 6:
                create_tuple(A,&B);
                break;
            case 7:
                display_matrix(&B);
                break;
            case 8:
                create_list(&A);
                break;
            case 9:
                disp_list(&B);
                break;
            case 10:
                //del_sparse(&B);
                break;
            case 11:
                k=0;
                break;
        }
    }
}

void initialize(struct sparse *p){
    int i;
    for(i=0;i<ROW;i++){
        p->rhead[i] = (struct rheadnode*)malloc(sizeof(struct rheadnode));
    }
    for(i=0;i<ROW-1;i++){
        p->rhead[i]->next = p->rhead[i+1];
        p->rhead[i]->right = NULL;
        p->rhead[i]->rowno = i;
    }
    p->rhead[i]->right = NULL;
    p->rhead[i]->next = NULL;
    p->rhead[i]->rowno = i;

    for(i=0;i<COL;i++){
        p->chead[i] = (struct cheadnode*)malloc(sizeof(struct cheadnode));
    }
    for(i=0;i<COL-1;i++){
        p->chead[i]->next = p->chead[i+1];
        p->chead[i]->down = NULL;
        p->chead[i]->colno = i;
    }
    p->chead[i]->down = NULL;
    p->chead[i]->next = NULL;
    p->chead[i]->colno = i;


    p->smat = (struct spmat *)malloc(sizeof(struct spmat));
    p->smat->firstcol = p->chead[0];
    p->smat->firstrow = p->rhead[0];
    p->smat->noofcols = COL;
    p->smat->noofrows = ROW;
}

void create_matrix(struct sparse *p){
    int n,i;

    p->sp = (int *)malloc(sizeof(int)*ROW*COL);

    for(i=0;i<ROW*COL;i++){
        printf("Enter ele: ");
        scanf("%d",p->sp+i);
    }
}

void display_matrix(struct sparse *p){
    int i;
    for(i=0;i<ROW*COL;i++){
        if(i%COL==0){
            printf("\n");
        }
        printf("%d\t",*(p->sp+i));
    }
}

int count(struct sparse *p){
    int i,c=0;
    for(i=0;i<ROW*COL;i++){
        if(*(p->sp+i)!=0){
            c++;
        }
    }
    return c;
}

void create_tuple(struct sparse S,struct sparse *p){
    int r = -1,c = -1,k = 0,i;
    p->nor = count(&S)+1;
    p->sp = (int *)malloc(sizeof(int)*(p->nor * 3));
    *(p->sp+k) = ROW;
    *(p->sp+k+1) = COL;
    *(p->sp+k+2) = p->nor - 1;
    k = 3;
    for(i=0;i<ROW*COL;i++){
        if(i%COL == 0){
            r++;
            c=0;
        }
        if(*(S.sp+i)!=0){
            *(p->sp+k) = r;
            *(p->sp+k+1) = c;
            *(p->sp+k+2) = *(S.sp+i);
            k+=3;
        }
    }
}

void disp_tuple(struct sparse *p){
    int i = 0,j = 0;
    for(i=0;i<p->nor;i++){
        printf("%d\t%d\t%d\n",*(p->sp+(i*3)+0),*(p->sp+(i*3)+1),*(p->sp+(i*3)+2));
    }
}

void create_list(struct sparse *p){
    int i,j=0;
    for(i=1;i<p->nor;i++){
        insert(p,p->smat,*(p->sp+i*3+0),*(p->sp+i*3+1),*(p->sp+i*3+2));
    }
}

void insert(struct sparse *p,struct spmat *s,int r,int c,int v){
    struct Node *temp1=NULL,*temp2=NULL;
    struct rheadnode *rh;
    struct cheadnode *ch;
    int i,j;
    p->nd = (struct Node*)malloc(sizeof(struct Node));
    p->nd->row = r;
    p->nd->col = c;
    p->nd->val = v;
    p->nd->right = NULL;
    p->nd->down = NULL;
    //get the proper row head node

    rh = s->firstrow;
    for(i=0;i<r;i++){
        rh = rh->next;
    }
    temp1 = rh->right;
    if(temp1 == NULL || temp1->col > c){
        rh->right = p->nd;
        p->nd->right = temp1;
    }
    else{
        while((temp1 != NULL) && (temp1->col<c)){
            temp2 = temp1;
            temp1 = temp1->right;
        }
        temp2->right = p->nd;
        p->nd->right = temp1;
    }

    //link proper column head node

    ch = s->firstcol;
    for(j=0;j<c;j++){
        ch = ch->next;
    }
    temp1 = ch->down;
    if(temp1 == NULL || temp1->row > r){
        ch->down = p->nd;
        p->nd->down = temp1;
    }
    else{
        while((temp1 != NULL)&&(temp1->row<r)){
            temp2 = temp1;
            temp1 = temp1->down;
        }
        temp2->down = p->nd;
        p->nd->down = temp1;
    }
}

void disp_list(struct sparse *p){
    struct Node *temp;
    int r = p->smat->noofrows;
    int i;
    for(i=0;i<r;i++){
        temp = p->rhead[i]->right;
        while(temp != NULL){
            printf("%d\t%d\t%d\n",temp->row,temp->col,temp->val);
            temp = temp->right;
        }
    }

    int c = p->smat->noofcols;
    printf("Transpose\n");
    for(i=0;i<c;i++){
        temp = p->chead[i]->down;
        while(temp!=NULL){
            printf("%d\t%d\t%d\n",temp->row,temp->col,temp->val);
            temp = temp->down;
        }
    }
}
