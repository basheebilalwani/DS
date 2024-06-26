#include<stdio.h>
#include<stdlib.h>
typedef struct t{
        int data;
        struct t * lchild;
        struct t * rchild;
}tree;
tree * root = NULL;
typedef struct qu{
        int size;
        int front;
        int rear;
        tree**qr;
}queue;
void enqueue(queue*q,tree * x){
     if(q->rear == q->size-1)
        printf("Queue full");
        else{
            q->rear++;
            q->qr[q->rear] = x;
        }
     }
int isempty(queue q){
    if(q.front==q.rear)
    return 1;
    else
    return 0;
}
tree * dequeue(queue * q){
    tree*x = NULL;
    if(q->front == q->rear)
    printf("Queue empty");
    else{
        q->front++;
        x = q->qr[q->front];
    }
    return x;
}
void create(){
     queue q;
     q.size=100;
     q.front=q.rear=-1;
     q.qr=(tree**)malloc(sizeof(tree*)*q.size);
     tree * p;
     tree * t;
     int x;
     printf("Enter root value:");
     scanf("%d", &x);
     root = (tree*)malloc(sizeof(tree));
     root->data = x;
     root->lchild = root->rchild = NULL;
     enqueue(&q,root);
     while(!isempty(q)){
        p = dequeue(&q);
        printf("Enter left child:");
        scanf("%d", &x);
        if(x!=-1){
            t = (tree*)malloc(sizeof(tree));
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        printf("Enter right child:");
        scanf("%d", &x);
        if(x!=-1){
            t = (tree*)malloc(sizeof(tree));
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
     }
}
void display(tree * x){
     if(x)
         {
            printf("%d\n",x->data);
            display(x->lchild);
            display(x->rchild);
 }
}
int main(){
    create();
    printf("Elements you entered are:\n");
    display(root);
    return 0;
}