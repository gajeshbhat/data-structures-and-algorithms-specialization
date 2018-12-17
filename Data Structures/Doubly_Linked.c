#include "stdio.h"
#include "stdlib.h"

struct node
{
  int data;
  struct node *next;    //links to next node
  struct node *prev;   //Links to Previous node
};


struct node *head=NULL;
struct node *temp; //temproray pointer variable for Previous node

void insert()
{
struct node *newnode;
newnode=malloc(sizeof(struct node));
printf("\nEnter an element to be inserted\n");
scanf("%d",&newnode->data);
if(head==NULL)
{
   head=newnode;
   temp=newnode;
  newnode->prev=NULL;
  newnode->next=NULL;
}
else
{
  temp->next=newnode;
  newnode->prev=temp;
  newnode->next=NULL;
  temp=newnode;
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
  printf("\nThe List is \n");
 while (i!=NULL) {
   printf("\t%d",i->data);
   i=i->next;
 }
}
}

void Reverseprint(struct node *p)
{
  if(p==NULL)
  {
    printf("\n");
    return;
  }
Reverseprint(p->next);

printf("\t%d",p->data);

}

void dele()
{
  if(head==NULL)
  {
    printf("\nEmpty List!\n");
  }

else
{
printf("\nElement deleted is %d  \n",head->data);
head=head->next;
}

}


int main(int argc, char const *argv[]) {
  int choice;
  while (1) {
  printf("\n\n\t- - - Doubly Linked List- - -\n");
    printf("\n1.Insert a node\n2.Delete a node\n3.Display\n4.Reverse Display (Check Linking)\n5.Exit\n\n");
    scanf("%d",&choice);
    switch (choice) {

      case 1:insert();
      break;
      case 2:dele();
      break;
      case 3:display();
      break;
      case 4:if(head==NULL)
      {
      printf("\nEmpty List!\n");
      break;
      }
     else
     {
       printf("\nReverse List is\n\n");
       Reverseprint(head);
     }

     break;

    case 5:exit(0);

      default:printf("Wrong choice!\n");
    }
  }
  printf("\n");
  return 0;
}
