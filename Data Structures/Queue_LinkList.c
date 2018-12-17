#include "stdio.h"
#include "stdlib.h"

struct node
{
  int data;
  struct node *link;
};

struct node *head=NULL;  //acts as rear end of queue
struct node *temp;
int count=0;
void insert()
{
 struct node *newnode;
 newnode=malloc(sizeof(struct node));
printf("\nEnter the element to be inserted\n");
scanf("%d",&newnode->data);
   if(head==NULL)
  {
     temp=head=newnode;
     newnode->link=NULL;

  }
else
{
  newnode->link=temp;
  head=temp=newnode;
  count++;
}
}

void dele()
{

struct node *j=head;
int i;
printf("\nElement from front is Successfully Removed!\n");
for (i=0;i<=count-1;i++) {
  if(i==count-1)
  {
    j->link=NULL;
  }
 j=j->link;
}
}

void display()
{
struct node *i=head;
if(head==NULL)
{
  printf("\nEmpty List!\n");
}
else
{
printf("\nThe List is\n\n");
 while(i!=NULL)
 {
   printf("%d ",i->data);
   i=i->link;
 }
}
}


int main(int argc, char const *argv[]) {
  insert();
  insert();
  insert();
  insert();
  display();
  dele();
  display();
  printf("\n");
  return 0;
}
