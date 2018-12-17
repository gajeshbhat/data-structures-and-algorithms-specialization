#include <iostream>
#include <vector>
#include <algorithm>

long int BinarySearch(std::vector<long int>List1,long int Key){
    long int low=0,high=(int)List1.size();
    while (low<=high) {
      long int mid=(low+high)/2;
      if(List1[mid]==Key){return mid;}
      else if(Key > List1[mid]){low=mid+1;}
      else if(Key < List1[mid]){high=mid-1;}
    }
    return -1;
}
int main(int argc, char const *argv[]) {
  long int n,k;
  std::cin >> n;
  std::vector<long int> Vector1;
  for (size_t i = 0; i < n; i++) {
    long int value;
    std::cin >> value;
    Vector1.push_back(value);
  }
 sort(Vector1.begin(),Vector1.end());
  std::cin >> k;
  for (size_t i = 0; i < k; i++) {
    long int keyValue;
    std::cin >> keyValue;
    std::cout <<BinarySearch(Vector1,keyValue)<<" ";
  }
  return 0;
}
