#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/*    NOTE :Some Compilers show Segmentation error it is better to implement using dynamic memeory allocation and use efficent methods if   
      you face the error */


/* Sample 'C' implementation using dynamic memory allocation is available in the repo*/

int const MAX=30;

void merge(int *l,int *r,int *a,int nl,int nr)
{

int i=0;
int j=0;
int k=0;


       while(i<nl && j<nr)
    {
        if(l[i]<=r[j])
       {
          a[k]=l[i];
          i++;
       }

          else
         {
            a[k]=r[j];
            j++;
         }
           k++;
     }
 
while(i<nl)

   {
      a[k]=l[i];
      i++;
      k++;

  }
        while(i<nr)
   {
      a[k]=r[j];
      j++;
      k++;

   }

}//end of merge function


void mergesort(int *a,int n)
{
int mid,right,left;
int l[MAX],r[MAX];
if(n < 2) return;//terminating case

mid=n/2; int i;

left=mid;
right=n-mid;//sizes of sub arrays

    for(i=0;i<mid-1;i++)
  {
    l[i]=a[i];
  }
  
 for(i=mid;i<n;i++)
{

 r[i]=a[i];
}

mergesort(l,left);//recursively sorting left subarry
mergesort(r,right);//recursively sorting right subarry
merge(l,r,a,left,right);//merging the arrays
}




int main()
{
int a[MAX],n,z;

cout<<"\nEnter the number of elements\n";
cin>>n;
cout<<"\nEnter the elements\n";
 
  for(z=0;z<n;z++)
{

cin>>a[z];

}

mergesort(a,n);//passing array and number of elements
cout<<"\nThe Sorted list is\n";
 for(z=0;z<n;z++)
{

cout<<" "<<a[z];
}

cout<<"\n";
return(0);

}
