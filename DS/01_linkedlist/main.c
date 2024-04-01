#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct n{
    int data;
    struct n * next;
}Node;
Node*first = NULL;
int length(Node*p)
{
    int count = 0;
    if(p) p=p->next;
    count++;
    return count;
}
void insert(Node*p,int index,int d)
{
    if(index>=0 && index<=length(p)){
        Node*t = (Node*)malloc(sizeof(Node));
        t->data = d;
    if(index==0)
    {
      t->next = first;
      first = t;
    }
    else
    {
        for(int i=1;i<index-1;i++)p=p->next;
        t->next = p->next;
        p->next = t;
    }
}
}
void display(Node*p)
{
    for(int i=0;i<=length(first);i++)
    {
         printf("%d",p->data );
        p=p->next;
    }
}
int main()
{
  insert(first,0,30);
  insert(first,1,42);
  display(first);
  return 0;
}