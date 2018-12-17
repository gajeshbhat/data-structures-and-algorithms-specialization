#include <iostream>
#include <algorithm>

long int Partition(long int a[],long int start,long int end){
  long int pivot=a[end];
  long int partitionIndex=start;

  for (size_t i = start; i < end; i++) {
    if(a[i] <= pivot){
      std::swap(a[i],a[partitionIndex]);//swapping the elements
            partitionIndex++;
    }
  }
  std::swap(a[partitionIndex],a[end]);//swapping the pivot
    return partitionIndex;
}

long int QuickSort(long int a[],long int start,long int end){
    if (start >= end){
      return 0; //Do nothing no or one elements
    }
    long int m=Partition(a,start,end); //Partion index
    QuickSort(a,start,m-1);
    QuickSort(a,m+1,end);
}

int main(int argc, char const *argv[]) {
  long int a[100],n;
  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  QuickSort(a,0,n-1);
  for (size_t i = 0; i < n; i++) {
    std::cout << a[i]<<" ";
  }
  return 0;
}
