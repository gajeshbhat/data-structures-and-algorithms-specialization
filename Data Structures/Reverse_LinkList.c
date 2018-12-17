#include "stdio.h"
#include "stdlib.h"

#define MAXSTK 10
int a[MAXSTK];
int top=-1;

struct node
{
  int data;
  struct node *link;
};

struct node *head=NULL;
struct node *temp;

int push(int x)
{
  top++;
  a[top]=x;
  return 0;
}

int pop()
{
  int x=a[top];
  top--;
  return(x);

}

void insert()
{
  struct node *newnode;
  newnode=malloc(sizeof(struct node));
  printf("Enter the Element to be inserted\n");
  scanf("%d",&newnode->data);

  if(head==NULL)
  {
    head=temp=newnode;
    newnode->link=NULL;
    }
  else
  {
   temp->link=newnode;
   newnode->link=NULL;
   temp=newnode;
  }
}

int display(struct node *p)
{
  if(p==NULL)
  {
    printf("\n");
    return 0;
  }
  printf(" %d  ",p->data);
  display(p->link);
  return 0;
}

void reverse()
{
  struct node *i=head;
  int ele;

  while(i!=NULL)
  {
    ele=i->data;
    push(ele);
    i=i->link;
 }

i=head;

while (i!=NULL) {
  ele=pop();
  i->data=ele;
  i=i->link;
}

}

int main(int argc, char const *argv[]) {
  insert();
  insert();
  insert();
  display(head);
  reverse();
  display(head);
  return 0;
}
