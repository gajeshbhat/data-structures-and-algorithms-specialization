#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[]) {
  long int n;
  std::cin >> n;
  std::vector<long int>numbers;
  for (size_t i = 0; i < n; i++) {
      long int value;
      std::cin >> value;
      numbers.push_back(value);
  }
  sort(numbers.begin(),numbers.end());//Fastest Possible Quick Sort available in libraray (Introsort).
  for (size_t i = 0; i < n; i++) {
    std::cout<<numbers[i]<<" ";
  }
  return 0;
}
