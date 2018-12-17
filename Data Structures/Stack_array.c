#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 5
int top=-1;
int a[MAXSIZE];


int push(int x)
{
  if(top==MAXSIZE-1)
  {
    printf("\nStack Overflow!\n");
    return 0;
  }
a[++top]=x;//increment and assign
return 0;
}


void pop()
{
  if(top==-1)
  {
    printf("\nStack Underflow!\n");
  }
else
{
 printf("\n%d is Poped.\n",a[top]);
  top--;
}
}


int TOP()
{
  if(top==-1)
  {
    printf("\nStack Underflow!\n");
    return 0;
  }
return a[top];
}


void display()
{
  int i;
if(top==-1)
{
  printf("\nStack Underflow!\n");
}
else
  {
printf("\nThe Elements of Stack are\n\n");

      for(i=0;i<=top;i++)
    {
        printf("%d  ",a[i]);
    }
  }
}


int main(int argc, char const *argv[]) {
int choice,x;
while (1) {
printf("\nStack Using Array\n");
printf("\n1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n\n");
printf("Enter you Choice\n");
scanf("%d",&choice);
switch (choice) {
  case 1 :printf("Enter Element to be Pushed\n");
          scanf("%d",&x);
          push(x);
          break;
 case 2 : pop();
         break;
 case 3 :printf("\nThe Top Element is %d  \n",TOP());
         break;
 case 4 :display();
         break;
 case 5: exit(0);
         break;
default: printf("\nWrong Choice\n");
}
}
printf("\n");
  return 0;
}
