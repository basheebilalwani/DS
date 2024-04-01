#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct st{
        int size;
        int top;
        int*sr;
}stack;
void create(stack * s,int size){
    s->size = size;
    s->sr=(char*)malloc(sizeof(size));
}
void push(stack*s,char c){
    if(s->top==s->size-1)
    printf("Stack full");
    else{
        s->top++;
        s->sr[s->top]=c;
    }
}
char pop(stack*s){
    char c;
    if(s->top==-1)
    printf("Stack empty");
    else{
        c=s->sr[s->top];
        s->top--;
    }
    return c;
}
int isoperand(stack*s,infix){
    int i;
    for(i=0;i<s->size;i++){
        if(infix[i]=='+' || '-' || '/' || '*')
        return 0;
        else
        return 1;
    }
}
int out(char c){
    switch(c)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 3;
    }
}
int in(char c){
    switch(c)
    {
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        return 4;
    }
}
char* convert(infix){
    int n = strlen(infix);
    char*postfix=(char*)malloc(sizeof(n+1));
}
int main(){
    stack stk;
    char*infix = "a+b";
    stk.top=-1;
    create(&stk,strlen(infix));
}