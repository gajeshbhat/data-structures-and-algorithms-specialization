#include "stdio.h"
#include "stdlib.h"

struct node
{
  int data;
  struct node *link;
};

struct node *head=NULL;
struct node *temp; //temp stores address of last node to refernce the and update its link part to nodes added
struct node *lastnode;
int count=0;

void enqueue()
{
  struct node *newnode;
  newnode=malloc(sizeof(struct node));
  printf("\nEnter an element to be inseretd\n");
  scanf("%d",&newnode->data);

if (head==NULL) {
lastnode=head=temp=newnode;
newnode->link=newnode;
}

else
{
head=newnode;
newnode->link=temp;
lastnode->link=newnode;
temp=newnode;
count++;
}
}

int dequeue()
{
  struct node *i=head;
  int c=0;

if(head==NULL)
{
  printf("\nEmpty Queue!\n");
  return 0;
}
while (c!=count-1) {
  i=i->link;
  c++;
}
printf("\nElement deleted is %d \n",lastnode->data);
i->link=temp;
count--;
lastnode=i;
return 0;
}

void display()
{
  struct node *i=head;
  int c=0;
if (i==NULL) {
  printf("\nEmpty Queue\n");
}
else
{

printf("\nThe Elements of Queue are\n");
  while (c<=count) {
printf("%d  ",i->data);
  i=i->link;
  c++;
 }

}
}

int main(int argc, char const *argv[]) {
  int choice;
  while (1) {
  printf("\n\n\t- - - Circular Queue Linked List- - -\n");
    printf("\n1.Insert a node\n2.Delete a node\n3.Display\n4.Exit\n\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:enqueue();
      break;
      case 2:dequeue();
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
