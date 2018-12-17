#include "stdio.h"
#include "stdlib.h"

struct node
{
  int data;
  struct node *link;
};

struct node *head=NULL;
struct node *temp;

int count=-1;  //counts number of nodes for traversing the circular List.

void insert()
{
  struct node *newnode;
  newnode=malloc(sizeof(struct node));
  printf("Enter the element to be inserted\n");
  scanf("%d",&newnode->data);
  if(head==NULL)
  {
    head=newnode;
    newnode->link=newnode;
    temp=newnode;
    count++;
  }
else
{
  newnode->link=temp;
  temp->link=newnode;
  temp=newnode;
  count++;
}
}

void display()
{
   struct node *i=head;
   int c=0;
  if(count==-1)
  {
    printf("\nEmpty list\n");
  }
  else
  {
   printf("\nElement of list are\n");
    while(c<=count)
    {
     printf("\t%d",i->data);
     i=i->link;
     c++;
    }
  }
}
void dele() {
  if(count==-1)
  {
    printf("\nEmpty List!\n");
  }

else
{
  printf("\nElement deleted is %d",head->data);
head=head->link;
count--;
}

}

int main(int argc, char const *argv[]) {
  int choice;
  while (1) {
  printf("\n\n\t- - - Circular Singly Linked List- - -\n");
    printf("\n1.Insert a node\n2.Delete a node\n3.Display\n4.Exit\n\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:insert();
      break;
      case 2:dele();
      break;
      case 3:display();
      break;
      case 4:exit(0);
      default:printf("Wrong choice!\n");
    }
  }
  printf("\n");
  return 0;
}
