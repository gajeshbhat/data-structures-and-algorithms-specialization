#include <iostream>

using namespace std;

void insertion(int *a,int n)

{

    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    { temp = a[i+1];
        for( j = i; j >= 0; j--)
        {
            if( temp < a[j])
            {
                a[j+1] = a[j];

            }
            else
            {
                break;

            }
        }
    a[j+1] = temp;
  }

    return;

}

int main()
{
    int a[10],n,k;


    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"\nEnter the elements\n";

    for(k=0;k<n;k++)
    {

        cin>>a[k];

    }

    insertion(a,n);//calling insertion

    cout<<"\nSorted list is\n";

    for(k=0;k<n;k++)
    {

        cout<<" "<<a[k];

    }
    cout<<"\n";
    return(0);
}
