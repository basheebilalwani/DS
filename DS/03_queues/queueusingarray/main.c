#include<stdio.h>
#include<stdlib.h>
typedef struct qu{
    int size;
    int front;
    int rear;
    int*qr;
}queue;
void create(queue*q,int s){
    q->size = s;
    q->qr=(int*)malloc(sizeof(int)*q->size);
}
void enqueue(queue*q,int x){
    if(q->rear==q->size-1)
    printf("Queue full");
    else{
        q->rear++;
        q->qr[q->rear]=x;
    }
}
int dequeue(queue*q){
    int x= -1;
    if(q->rear==q->front)
    printf("Queue empty");
    else{
         q->front++;
         x = q->qr[q->front];
    }
    return x;
}
void display(queue q){
     for(int i=q.front+1; i<=q.rear;i++){
        printf(" %d ", q.qr[i]);
     }
}
int isempty(queue q){
    if(q.rear == q.front)
    return 1;
    else
    return 0;
}
int search(queue q,int key){
    int i = q.front+1;
    while(i<=q.size-1){
        if(q.qr[i]==key)
        return i;
        else
        i++;
    }
}
int main(){
    queue qu;
    qu.front = qu.rear = -1;
    create(&qu,2);
    enqueue(&qu,42);
    enqueue(&qu,30);
    printf("Found at %d\n",search(qu,30));
    display(qu);
    return 0;
}