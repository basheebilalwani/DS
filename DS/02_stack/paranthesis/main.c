#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct s{
        int size;
        int top;
        char * s;
}stack;
void push(stack * str,char c){
    if(str->top== str->size-1)
    printf("stack full");
    else{
     str->top++;
     str->s[str->top] = c;}
}
void pop(stack * str){
    char c = -1;
    if(str->top==-1)
    printf("stack empty");
    else{
    c = str->s[str->top];
    str->top--;}
    //printf("%c popped out of stack",c);
    //return c;
}
int isempty(stack * str){
    if(str->top==-1)
    return 1;
    else
    return 0;
}
int isbalance(stack * str,char * exp){
    for(int i=0; exp[i]!='\0';i++){
        if (exp[i]=='(') push(str,exp[i]);
        else if(exp[i]==')')
        {
            if(!isempty(str))
            pop(str);
            else{
            printf("paranthesis matching unsuccessful\n");
            return 0;
            }
        }
    }
    if(!isempty(str)){
    printf("paranthesis matching unsuccessful\n");
    return 0;}
    else{
    printf("paranthesis matching successful\n");
    return 1;
}
}
int main(){
    stack st;
    char*exp = "((a+b)*(c-d)";
    st.size = sizeof(exp);
    st.top=-1;
    st.s=(char*)malloc(sizeof(st.size));
    isbalance(&st,exp);
    return 0;
}