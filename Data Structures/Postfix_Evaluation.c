#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "ctype.h"

#define MAXSTK 20
char stack[MAXSTK];
int top=-1,nn;

char push(char x)
{
top++;
stack[top]=x;
return 0;
}

char pop()
{

char x;
x=stack[top];
top--;
return(x);

}

void EvaluatePostfix(char *expr)
{
int n1, n2, n3 ;
	while ( *expr)
	{
		/* skip whitespace, if any */
		if ( *expr == ' ' || *expr == '\t' )
		{
			expr++ ;
			continue ;
		}

		/* if digit is encountered */
		if ( isdigit ( *expr ) )
		{
			nn = *expr - '0' ;
			push ( nn ) ;
		}
		else
		{
			/* if operator is encountered */
			n1 = pop( ) ;
			n2 = pop( ) ;
			switch ( *expr )
			{
				case '+' :
					  n3 = n2 + n1 ;
					  break ;

				case '-' :
					  n3 = n2 - n1 ;
					  break ;

				case '/' :
					  n3 = n2 / n1 ;
					  break ;

				case '*' :
					  n3 = n2 * n1 ;
					  break ;

				case '%' :
					  n3 = n2 % n1 ;
					  break ;

				case '$' :
					  n3 = pow ( n2 , n1 ) ;
					  break ;

				default :
					  printf("\nUnknown operator\n");
					  exit ( 0 ) ;
			}

			push ( n3 ) ;
		}
		expr++ ;
	}
}


int main(int argc, char const *argv[]) {
  char expr[20];
  printf("\nEnter an Expression\n");
 scanf("%s",expr);
 EvaluatePostfix(expr);
  nn=pop();
  printf("Result is %d  ",nn);
 printf("\n");
  return 0;
}
