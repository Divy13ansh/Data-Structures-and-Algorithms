#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
struct sparse{
    int *sp;
    int nor;
};
void main(){
    void create_mat(struct sparse *);
    void disp_mat(struct sparse);
    int count(struct sparse);
    void create_tuple(struct sparse, struct sparse *);
    void disp_tuple(struct sparse);
    void addTuples(struct sparse, struct sparse, struct sparse *);
    void tupleTranspose(struct sparse,struct sparse*);
    struct sparse A[9];
    int i,j,k=1,ch;
    while(k){
        printf("\nMenu\n1. Create First Matrix\n2. Display First Matrix\n3. Count in first \n4. Create First Tuple\n5. Display First Tuple\n6. Create Second Matrix\n7. Display Second Matrix\n8. Count in second\n9. Create Second Tuple\n10. Display Second Tuple\n11. Addition\n12. Display third tuple\n13. Tuple Transpose\n14. Display transposed matrix\n15. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                create_mat(&A[0]);
                break;
            case 2:
                disp_mat(A[0]);
                break;
            case 3:
                i = count(A[0]);
                printf("%d",i);
                break;
            case 4:
                create_tuple(A[0],&A[1]);
                break;
            case 5:
                disp_tuple(A[1]);
                break;

            case 6:
                create_mat(&A[2]);
                break;
            case 7:
                disp_mat(A[2]);
                break;
            case 8:
                i = count(A[2]);
                printf("%d",i);
                break;
            case 9:
                create_tuple(A[2],&A[3]);
                break;
            case 10:
                disp_tuple(A[3]);
                break;
            case 11:
                addTuples(A[1],A[3],&A[4]);
                break;
            case 12:
                disp_tuple(A[4]);
                break;
            case 13:
                tupleTranspose(A[1],&A[5]);
                break;
            case 14:
                disp_tuple(A[5]);
                break;
            case 15:
                k = 0;
                break;
        }
    }
}
void create_mat(struct sparse *p){
    int i,j;
    p->sp = (int *)malloc(sizeof(int)*(ROW*COL));
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("Enter ele: ");
            scanf("%d",p->sp+(i*COL)+j);
        }
    }
}

void disp_mat(struct sparse p){
    int i;
    for(i=0;i<(ROW*COL);i++){
        if(i % COL == 0){
            printf("\n");
        }
        printf("%d\t",*(p.sp+i));
    }
}

int count(struct sparse p){
    int i,c = 0;
    for(i=0;i<(ROW*COL);i++){
        if(*(p.sp+i)!= 0){
            c++;
        }
    }
    return c;
}

void create_tuple(struct sparse X, struct sparse *y){
    int i,j,k,r,c;
    y->nor = count(X)+1;
    y->sp = (int *)malloc(sizeof(int)*(y->nor*3));
    *(y->sp+0) = ROW;
    *(y->sp+1) = COL;
    *(y->sp+2) = (y->nor)-1;
    k = 3;
    r = -1;
    c = -1;
    for(i=0;i<(ROW*COL);i++){
        c++;
        if(i % COL == 0){
            r++;
            c = 0;
        }
        if(*(X.sp+i) != 0){
            *(y->sp+k) = r;
            k++;
            *(y->sp+k) = c;
            k++;
            *(y->sp+k) = *(X.sp+i);
            k++;
        }
    }
}

void disp_tuple(struct sparse y){
    int i;
    for(i=0;i<y.nor*3;i++){
            if(i%3 == 0){
                printf("\n");
            }
            printf("%d\t",*(y.sp+i));
    }
}

void addTuples(struct sparse X, struct sparse Y, struct sparse *Z){
    int i,j,k = 3,ra,ca,rb,cb,va,vb,c=0,l;
    Z->sp = (int *)malloc(sizeof(int)*(X.nor + Y.nor)*3);
    for(i=3,j=3;i<X.nor*3 || j<Y.nor*3;){
        ra = *(X.sp+i);
        ca = *(X.sp+i+1);
        va = *(X.sp+i+2);
        rb = *(Y.sp+j);
        cb = *(Y.sp+j+1);
        vb = *(Y.sp+j+2);
        if(i==((X.nor*3))){
            ra = 99;
            ca = 99;
        }
        else if(j == ((X.nor*3))){
            rb = 99;
            cb = 99;
        }

        if(ra<rb){
            *(Z->sp+k) = ra;
            *(Z->sp+k+1) = ca;
            *(Z->sp+k+2) = va;
            k+=3;
            i+=3;
        }
        else if(ra>rb){
            *(Z->sp+k) = rb;
            *(Z->sp+k+1) = cb;
            *(Z->sp+k+2) = vb;
            k+=3;
            j+=3;
        }
        else{
            if(ca<cb){
                *(Z->sp+k) = ra;
                *(Z->sp+k+1) = ca;
                *(Z->sp+k+2) = va;
                k+=3;
                i+=3;
            }
            else if(ca>cb){
                *(Z->sp+k) = rb;
                *(Z->sp+k+1) = cb;
                *(Z->sp+k+2) = vb;
                k+=3;
                j+=3;
            }
            else{
                *(Z->sp+k) = ra;
                *(Z->sp+k+1) = ca;
                *(Z->sp+k+2) = va+vb;
                k+=3;
                i+=3;
                j+=3;
            }
        }

    }
    Z->nor = ((k)/3);
    *(Z->sp+0) = (Z->nor)-1;
    *(Z->sp+1) = 3;
    *(Z->sp+2) = (Z->nor)-1;
}

void tupleTranspose(struct sparse X,struct sparse*Y){
    int i,j,k=3,*z;
    Y->nor = X.nor;

    Y->sp = (int *)malloc(sizeof(int)*(X.nor)*3);
    *(Y->sp+0) = *(X.sp+1);
    *(Y->sp+1) = *(X.sp+0);
    *(Y->sp+2) = *(X.sp+2);

    for(i=0;i<X.nor;i++){
        for(j=1;j<X.nor*3;j+=3){
            if(*(X.sp+j) == i){
                *(Y->sp+k) = *(X.sp+j);
                *(Y->sp+k+1) = *(X.sp+j-1);
                *(Y->sp+k+2) = *(X.sp+j+1);
                k+=3;
            }
        }
    }
}
