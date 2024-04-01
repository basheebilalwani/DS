#include<stdio.h>
#include<stdlib.h>
typedef struct q{
        int data;
        struct q*next;
}queue;
queue*front = NULL;
queue*rear = NULL;
void create(){
    front=(queue*)malloc(sizeof(queue));
}
void enqueue(int x){
    queue*t = (queue*)malloc(sizeof(queue));
    if(t==NULL)
    printf("Queue Full");
    else
    {
       t->data=x;
       t->next=NULL;
       if(front==NULL)
       front=rear=t;
       else{
        rear->next = t;
        rear=t;
       }
    }
}
void display(){
    queue*p = front;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}
int dequeue(){
    int x = -1;
    queue*p;
    if(front==NULL)
    printf("Queue empty");
    else{
        p =front;
        front =front->next;
        x = p->data;
        free(p);
        return x;
    }
}
int main(){
    queue qu;
    enqueue(30);
    enqueue(42);
    display();
    return 0;
}