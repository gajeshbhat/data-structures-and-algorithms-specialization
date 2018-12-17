#include <iostream>
#include <math.h>
using namespace std;

int a[10],n,i,j;

class quicksort
{
    
    public:
    void getdata();
    void display();
    void qsort(int *a,int start,int end);
    int partition(int *a,int start,int end);
    
};


void quicksort::getdata()
{
    
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        
    }
    
    
}

void quicksort::display()
{
    
    cout<<"The sorted array is\n";
    
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<a[i];
    }
}

int quicksort::partition(int *a,int start,int end)
{
    
    int pivot=a[end];
    
    int partitionindex=start;
    
    for(i=start;i<end;i++)
    {
        
        if(a[i]<=pivot)
        {
            
            swap(a[i],a[partitionindex]);//swapping the elements
            partitionindex++;
            
        }
        
        
    }
    swap(a[partitionindex],a[end]);//swapping the pivot
    return partitionindex;
    
}

void quicksort::qsort(int *a,int start,int end)
{
    if(start<end)
    {
        int partitionindex = partition(a,start,end);
        qsort(a,start,partitionindex-1);
        qsort(a,partitionindex+1,end);
    }
}

int main()
{
    quicksort q;
    q.getdata();
    q.qsort(a,0,n-1);
    q.display();
    
    return(0);
}
