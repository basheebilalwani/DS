#include<stdio.h>
#include<stdlib.h>
typedef struct st{
        int size;
        int top;
        int*sr;
}stack;
void create(stack*s,int size){
    s->size=size;
    s->sr=(int*)malloc(sizeof(int)*size);
}
void push(stack*s,int x){
    if(s->top==s->size-1)
    printf("Stack full");
    else{
        s->top++;
        s->sr[s->top]=x;
    }
}
void display(stack s){
     for(int i=0;i<=s.size-1;i++){
        printf("%d", s.sr[i]);
     }
}
int pop(stack*s){
    int x = -1;
    if(s->top==-1)
    printf("Stack empty");
    else{
          x=s->sr[s->top];
          s->top--;
    }
   return x;
}
int main(){
    stack stk;
    stk.top=-1;
    create(&stk,2);
    push(&stk,30);
    push(&stk,42);
    display(stk);
    return 0;
}