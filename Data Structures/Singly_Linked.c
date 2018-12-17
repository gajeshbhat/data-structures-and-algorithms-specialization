#include "stdio.h"
#include "stdlib.h"

struct node
{
int data;
struct node *link;
};

struct node *head=NULL;
struct node *temp;

void insert() {
struct node  *newnode;
newnode=malloc(sizeof(struct node));
printf("\nEnter the element to be inserted\n");
scanf("%d",&newnode->data);

if(head==NULL)
{
  head=newnode;
  newnode->link=NULL;
  temp = newnode;
}
else
{
  temp->link = newnode;//assigning address of newnode to previous node
  newnode->link=NULL;
  temp = newnode;
}

}

void display()
{

struct node *i=head;

  if(head==NULL)
  {
    printf("Empty List!\n");
  }

else
{
printf("\nList is\n");
  while(i!=NULL){
  printf("%d\t",i->data);
  i=i->link;
  }
}
}
void dele()
{
if(head==NULL)
{
  printf("\nEmpty List!\n");
}
else
{
   printf("\nElement deleted is %d\n",head->data);
  head = head->link;
}
}
int main(int argc, char const *argv[]) {
int choice;
while (1) {
printf("\n\n\t- - - Singly Linked List- - -\n");
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
