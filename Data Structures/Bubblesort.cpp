#include <iostream>

using namespace std;

int const MAX=50;

void bubblesort(int *a,int n)
{
    int i,j,temp;
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            
        }
        
    }
    
}

int main()
{
    int a[MAX],n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"\nEnter the elements\n";
    for(int k=0;k<n;k++)
    {
        cin>>a[k];
    }
    bubblesort(a,n);
    cout<<"\nSorted list is\n";
    
    for(int k=0;k<n;k++)
    {
        cout<<" "<<a[k];
        
    }
    cout<<"\n";
    return(0);
}
