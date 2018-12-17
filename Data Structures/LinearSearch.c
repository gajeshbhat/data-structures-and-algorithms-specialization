#include "stdio.h"

int linear_search(int a[],int n,int ele,int i)
{

 if(i > n)
 {
   printf("Element not found!\n");//Terminating case
  return(0);
 }
if(ele == a[i])
{
  printf("Search Successful! Element found at %d\n",i+1); //Successful Search
  return(0);
}
else{
linear_search(a,n,ele,i=i+1);
}

}

int main(int argc, char const *argv[])
{
  int a[100],i,n,ele;
  printf("Enter number of elements in list\n");
  scanf("%d",&n);
  printf("Enter the list\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the search element\n");
  scanf("%d",&ele);
  linear_search(a,n,ele,0);
  return 0;
}
