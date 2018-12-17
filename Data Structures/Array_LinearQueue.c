#include "stdio.h"
#include "stdlib.h"

#define MAX 10
int queue[MAX];
int front=-1,rear=-1;

int insert()
{

 int ele;

printf("Enter the element to be inserted\n");
scanf("%d",&ele);

if (rear==MAX-1)
{
  printf("Queue is Full!\n");
  return 0;
}
 else if(front==-1)
 {
   front=rear=0;
   queue[rear]=ele;
 }
else
{
  queue[++rear]=ele;
}
return 0;
}

int dele()
{
if (front==-1) {
  printf("Empty Queue!\n");
  return 0;
}

else if(front==rear)
{
  printf("\nElement deleted is %d\n",queue[front]);
  front=-1;
  rear=-1;
}

else
{
  printf("\nElement deleted is %d\n",queue[front]);
  front++;

}
return 0;
}

void display()
{
  int i;
  if(front==-1)
  {
    printf("\nEmpty Queue!\n");
    }
else
{
  printf("\nThe List is\n");
  for(i=front;i<=rear;i++)
  {
    printf("%d  ",queue[i]);
  }
}
}

int main(int argc, char const *argv[]) {

  int choice;
  while (1) {
  printf("\n\n\t- - - Linear Queue - - -\n");
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
    printf("\nEnter your choice\n");
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
