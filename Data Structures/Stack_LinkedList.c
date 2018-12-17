#include "stdio.h"
#include "stdlib.h"

struct node
{
  int data;
  struct node *link;
};

struct node *head=NULL; //Underflow Condittion
struct node *temp;

void push() // Push into Stack
{
  struct node *newnode;
  newnode=malloc(sizeof(struct node));
  printf("\nEnter the element\n");
  scanf("%d",&newnode->data);

  if(head==NULL)
  {
   temp=head=newnode;
   newnode->link=NULL;
  }
 else
 {
   newnode->link=NULL;
   temp->link=newnode;
   temp=newnode;
 }
}

void pop() // Pop out of Stack
{
  if (head==NULL) {
    printf("\nStack Underflow!\n");
  }
else
{
printf("\n%d is Poped\n",head->data);
  head=head->link;
}
}

int display(struct node *p) //Display using recursion
{
  if(p==NULL)
  {
    printf("\n");
    return 0;
  }
 printf("%d  ",p->data);
 display(p->link);

 return 0;
}

void top() // Return Topmost element
{
printf("Top element is %d\n",head->data);
}

int main(int argc, char const *argv[]) {
  int choice;
  while (1) {
printf("\nStack Using Linked List\n");
printf("\n1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n");
printf("\nEnter your choice\n");
scanf("%d",&choice);
    switch (choice) {
      case 1 :push();
              break;
      case 2: pop();
              break;
      case 3:top();
              break;
      case 4:display(head);
              break;
      case 5:exit(0);
              break;
      default:printf("\nWrong Chocie!\n");
    }
  }
  printf("\n");
  return 0;
}
