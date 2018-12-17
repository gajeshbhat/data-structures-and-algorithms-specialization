#include "stdio.h"
#include "string.h"

char stack[30];
int top=-1;


void push(char x)
{
  if(top==29)
  {
    printf("\nStack Full!\n");
  }
else
{
  stack[++top]=x;
}
}

char pop()
{
  if(top==-1)
  {
    printf("\nEmpty Stack!");
  }
else
{
  return(stack[top--]);
}
}

void Reverse(char str[]) {
  int i=0;
  while(str[i]!='\0')
  {
    push(str[i]);
    i++;
  }
i=0;
while(str[i]!='\0')
{
  str[i]=pop();
  i++;
}
}


int main(int argc, char const *argv[]) {
  char str[10];
  printf("\nEnter a string\n");
  scanf("%s",str);
  Reverse(str);
  printf("\nThe Reversed String is %s",str);
  printf("\n");
  return 0;
}
