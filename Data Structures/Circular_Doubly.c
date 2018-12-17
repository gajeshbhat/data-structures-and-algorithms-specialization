#include "stdio.h"
#include "stdlib.h"

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head=NULL;
struct node *temp;
struct node *first;
int count = -1;

void insert()
{
struct node *newnode;
newnode=malloc(sizeof(struct node));
printf("\nEnter the element to be inserted\n");
scanf("%d",&newnode->data);

if(head==NULL)
{
  head=newnode;
  temp=first=newnode;
  newnode->prev=NULL;
  newnode->next=temp;
  count++;
}
else
{
  temp->next=newnode;
  newnode->next=first;
  newnode->prev=temp;
  temp=newnode;
  count++;
}

}

void display()
{
  struct node *i=head;
  int c=0;

  if (count==-1) {
    printf("\nEmpty List\n");
  }

else
{
  printf("\nThe List is\n");

  while (c<=count) {
    printf("\t%d",i->data);
   i=i->next;
   c++;
  }
}

}

void dele()
{
  if(count==-1)
  {
    printf("\nEmpty List!\n");
  }
else
{
  printf("\nElement deleted is %d  \n",head->data);
  first=head=head->next;
  temp->next=head;
  count--;
}

}

int main(int argc, char const *argv[]) {
  int choice;
  while (1) {
  printf("\n\n\t- - - Circular Doubly Linked List- - -\n");
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
