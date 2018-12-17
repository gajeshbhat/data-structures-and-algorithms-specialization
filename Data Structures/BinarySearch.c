#include "stdio.h"
#include "stdlib.h"

int cmpfunc (const void * a, const void * b)//compares two elements used by qsort
{
   return ( *(int*)a - *(int*)b );
}


int Binary_Search(int a[],int ele,int beg,int end)
{
  int mid;
  mid=(beg+end)/2;

  if(end < beg)
  {
    printf("Search Unsuccesful!\n");//Unsuccesful Search Termination
    return(0);
  }

  if(ele == a[mid])
  {
    printf("Search Successful! Element found at Postion %d \n",mid+1);//Succesful Search
    return(0);
  }
  else if(ele > a[mid]){
    Binary_Search(a,ele,mid+1,end);//Right shift
  }
else{
  Binary_Search(a,ele,beg,mid-1); //Left shift
}
}

int main(int argc, char const *argv[])
{
  int a[100],n,ele,i;
  printf("Enter number of elements in the list\n");
  scanf("%d",&n);
  printf("Enter the list\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
printf("Enter the search element\n");
scanf("%d",&ele);
qsort(a,n,sizeof(int),cmpfunc);//sort the array
Binary_Search(a,ele,0,n-1);
  return 0;
}
