#include<stdio.h>
#include<stdlib.h>
typedef struct qe{
        int size;
        int front;
        int rear;
        int *qr;
}queue;
void enqueue(queue * q, int x){
    if((q->rear+1)% q->size == q->front)
    printf("Queue full");
    else{
        q->rear = (q->rear+1)% q->size;
        q->qr[q->rear] = x;
        }
}
void display(queue q){
    int i = (q.front+1)%q.size;
    while(i<=q.rear)
     {
        printf("%d\n", q.qr[i]);
        i= (q.front+1)%q.size;
     } 
}
int dequeue(queue * q){
    int x = -1;
    if(q->front == q->rear)
    printf("Queue empty");
    else{
        q->front=(q->front+1)%q->size;
        x = q->qr[q->front];
    }
    return x;
}
int search(queue q,int key){
    int i = (q.front+1)%q.size;
    while(i<=q.rear)
    {
        if(key==q.qr[i])
        return i;
        else
        i= (q.front+1)%q.size;
    }
}
int main(){
    queue qu;
    qu.front = qu.rear = 0;
    int arr[6] = {1,2,3,4,5,6};
    qu.size = 7;
    qu.qr = (int*)malloc(sizeof(int)*7);
    for(int i=0;i<=5;i++)
    {enqueue(&qu,arr[i]);}
    display(qu);
    printf("Found at %d",search(qu,6));
    //dequeue(&qu);
    return 0;
}