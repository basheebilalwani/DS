#include<stdio.h>
#include<stdlib.h>
typedef struct st{
        int data;
        struct st*next;
}stack;
stack*top = NULL;
void create(){
    top=(stack*)malloc(sizeof(stack));
}
void push(int x){
    stack*t = (stack*)malloc(sizeof(stack));
    if(t==NULL)
    printf("stack full");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void display(){
    stack*p = top;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}
int pop(){
    int x=-1;
    stack*p;
    if(top==NULL)
    printf("stack empty");
    else
    {
       p=top;
       top=top->next;
       x=p->data;
       free(p);
    }
    return x;
}
int main(){
    stack stk;
    push(30);
    push(42);
    display();
    return 0;
}