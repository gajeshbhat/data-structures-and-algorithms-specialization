#include <iostream>

using namespace std;

void selection(int list[],int i,int j, int size,int flag)
{
    int temp;
    if (i < size - 1)
    {
        if (flag)
        {
            j = i + 1;
        }
        if (j < size)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            selection(list, i, j + 1, size, 0); //Recursive Calls
        }
        selection(list, i + 1, 0, size, 1);
    }
}



int main()
{

int array[20],n,k;

cout<<"enter number of elements\n";
cin>>n;
cout<<"enter the elements\n";
for(k=0;k<n;k++)
{

cin>>array[k];

}
selection(array,0,0,n,1);

cout<<"sorted list is\n";

for(k=0;k<n;k++)
{

cout<<array[k]<<"\n";
}

return(0);
}
