#include "stdio.h"
#include "stdlib.h"

#define MAXSTK 30
int top=-1;

char stack[MAXSTK];

char push(char x)
{
  top++;
  stack[top]=x;
 return 0;
}

void pop()
{
  top--;
}

void CheckBalance(char expr[])
{
  int i;
  for(i=0;expr[i]!='\0';i++)
  {

    if(expr[i]=='('||expr[i]=='{'||expr[i]=='[')
    {
      push(expr[i]);
    }

else if(expr[i]==')')
{

  if(stack[top]=='(')
  {
    pop();
  }

 else
{
  printf("Unbalanced Paranthesis!\n");
  exit(0);
}

}

else if(expr[i]=='}')
{

  if(stack[top]=='{')
  {
    pop();
  }

 else
 {
  printf("Unbalanced Paranthesis!\n");
  exit(0);
 }

}

  else if(expr[i]==']')
  {

   if(stack[top]=='[')
    {
      pop();
    }

   else
  {
    printf("Unbalanced Paranthesis!\n");
    exit(0);
  }

  }

}// end of for

if(top==-1)
{
  printf("Paranthesis are Balanced!\n");
}
else
{
  printf("Unbalanced Paranthesis!\n");
}

} // end of CheckBalance

int main(int argc, char const *argv[]) {
  char expr[20];
  printf("\nEnter an Expression\n");
  scanf("%s",expr);
  CheckBalance(expr);
  printf("\n");
  return 0;
}
