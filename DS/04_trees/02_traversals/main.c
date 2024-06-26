#include<stdio.h>
#include<stdlib.h>
typedef struct tr{
        int data;
        struct tr *lchild;
        struct tr *rchild;
}tree;
tree*root = NULL;
typedef struct qu{
        int size;
        int front;
        int rear;
        tree**qr;
}queue;
typedef struct st{
        int top;
        int size;
        tree**sr;
}stack;
void createqueue(queue*q,int si){
    
}
void createstack(stack*s,int si){
     s->size = si;
    
}
void enqueue(queue*q,tree*x){
     if(q->rear==q->size-1)
        printf("Queue full");
     else{
         q->rear++;
         q->qr[q->rear]=x;
     }
}
tree*dequeue(queue*q){
    tree*x;
    if(q->rear==q->front)
       printf("Queue empty");
    else{
        q->front++;
        x = q->qr[q->front];
    }
    return x;
}
int isempty(queue q){
    if(q.front==q.rear)
    return 1;
    else
    return 0;
}
void createtree(){
     int x;
     queue q;
     q.front = q.rear = -1;
     q.size = 100;
     q.qr=(tree**)malloc(sizeof(tree*)*q.size);
     tree *t; 
     tree *p;
     printf("Enter root:");
     scanf("%d", &x);
     root = (tree*)malloc(sizeof(tree*));
     root->data = x;
     root->lchild = root->rchild = NULL;
     enqueue(&q,root);
     while(!isempty(q)){
          p = dequeue(&q);
          printf("Enter left child:");
          scanf("%d",&x);
        if(x!=-1){
          t = (tree*)malloc(sizeof(tree*));
          t->data = x;
          t->lchild = t->rchild = NULL;
          p->lchild = t;
          enqueue(&q,t);}
          printf("Enter right child:");
          scanf("%d",&x);
        if(x!=-1){
          t = (tree*)malloc(sizeof(tree*));
          t->data = x;
          t->lchild = t->rchild = NULL;
          p->rchild = t;
          enqueue(&q,t);}
     }
}
void push(stack * s,tree * x){
     if(s->top==s->size-1)
     printf("Stack full");
     else{
        s->top++;
        s->sr[s->top]=x;
     }
}
tree * pop(stack*s){
    tree*x;
    if(s->top==-1)
    printf("Stack empty");
    else{
        x=s->sr[s->top];
        s->top--;
    }
    return x;
}
int isemptys(stack s){
    if(s.top==-1)
    return 1;
    else
    return 0;
}
void preorder(){
     tree*r;
     r=root;
     stack s;
     s.top = -1;
     s.size = 100;
     s.sr=(tree**)malloc(sizeof(tree*)*s.size);
     while(!isemptys(s)||r!=NULL){
     if(r!=NULL){
        printf("%d\n",r->data);
        push(&s,r);
        r=r->lchild;
     }
     else{
        r = pop(&s);
        r = r->rchild;
     }
    }
}
void inorder(){
     tree*r;
     r=root;
     stack s;
     s.top = -1;
     s.size = 100;
     s.sr=(tree**)malloc(sizeof(tree*)*s.size);
     while(!isemptys(s)||r!=NULL){
     if(r!=NULL){
        push(&s,r);
        r=r->lchild;
     }
     else{
        r = pop(&s);
        printf("%d\n",r->data);
        r = r->rchild;
     }
    }
}
void levelorder(){
    queue q;
    q.front = q.rear = -1;
    q.size = 100;
    q.qr=(tree**)malloc(sizeof(tree*)*q.size);
    tree * t;
    t = root;
    printf("%d\n",t->data);
    enqueue(&q,t);
    while(!isempty(q))
    {
        t = dequeue(&q);
        if(t->lchild)  
        {
            printf("%d\n",t->lchild->data);
            enqueue(&q,t->lchild);
        }
        if(t->rchild)  
        {
            printf("%d\n",t->rchild->data);
            enqueue(&q,t->rchild);
        }
    }
}
int height(tree * p){
    int x,y;
    while(p)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if(x>y) return x+1;
        else return y+1;
    }
    return 0;
}
int count(tree * p){
    int x,y;
    while(p)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}
int main(){
    createtree();
    printf("Preorder:\n");
    preorder();
    printf("Inorder:\n");
    inorder();
    printf("levelorder:\n");
    levelorder();
    printf("Height of tree is: %d\n", height(root));
    printf("Number of nodes of the tree is: %d", count(root));
    return 0;
}