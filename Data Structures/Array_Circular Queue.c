 #include "stdio.h"
 #include "stdlib.h"

#define MAX 10

int q[MAX];
int head=-1,tail=-1;

void push(int x)
{
  if(head==tail-1)
  {
    printf("\nQueue is FUll!");
  }
else if(head==-1 && tail==-1)
{
  tail++;
  q[++head]=x;
}
else
{
  q[++head]=x;
}
}

void pop()
{
  if(head==-1 && tail==-1)
  {
    printf("\nEmpty Queue!");
  }
else
{
  tail++;
}
}

void display()
{
  int i=tail;

  if(head==-1 && tail==-1)
  {
    printf("\nEmpty Queue!\n");
  }
else
{
  printf("\nThe Elements of Queue are\n");
  while(i<=head)
  {
    printf("%d  ",q[i]);
    i++;
  }
}
}

int main(int argc, char const *argv[]) {
  int choice,x;
  while (1) {
  printf("\n\n\t- - - Circular Queue Array - - -\n");
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("\nEnter your Choice\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:printf("\nEnter an element\n");
      scanf("%d",&x);
      push(x);
      break;
      case 2:pop();
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
