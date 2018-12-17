#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  long int n;
  std::cin >> n;

  std::vector<long int>profitperClick;
  std::vector<long int>averageclickNumber;

  for (size_t i = 0; i < n; i++) {
    long int value;
    std::cin >> value;
    profitperClick.push_back(value);
  }

  for (size_t i = 0; i < n; i++) {
    long int value;
    std::cin >> value;
    averageclickNumber.push_back(value);
  }

  sort(profitperClick.begin(),profitperClick.end());
  sort(averageclickNumber.begin(),averageclickNumber.end());

  long int maxProfit=0;

  for (size_t i = 0; i < n; i++) {
    maxProfit+=(profitperClick[i]*averageclickNumber[i]);
  }
  std::cout << maxProfit << std::endl;
  return 0;
}
