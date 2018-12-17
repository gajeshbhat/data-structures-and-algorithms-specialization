#include <iostream>
using namespace std;

int const MAX=100;

/*Selection Sort using recursion is also in the repository*/

void selection(int a[],int n)//recives array using pointer and size of the array
{
    
    int imin;//to hold the minimum value
    
    int i,j,temp;
    
    for(i=0;i<n-1;i++)
    {
        imin=i;//initializing the minimum element
        
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
            {
                imin=j;//updating the minimum element
            }
        }
        
        
        temp=a[i];      // swapping
        a[i]=a[imin];
        a[imin]=temp;
    }
    
}

int main()
{
    int a[MAX],n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    
    for(int k=0;k<n;k++)
    {
        cin>>a[k];
        
    }
    
    selection(a,n);//passing array and number of elements
    
    cout<<"\nSorted list is\n";
    
    for(int k=0;k<n;k++)
    {
        cout<<" "<<a[k];
        
    }
    
    cout<<"\n";
    
    return(0);
    
}
