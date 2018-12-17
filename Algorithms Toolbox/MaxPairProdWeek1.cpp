#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    long int n;
    std::cin >> n;

    std::vector<long int>Numbers;

    for (size_t i = 0; i < n; i++) {
      long int value;
      std::cin >> value;
      Numbers.push_back(value);
    }

    sort(Numbers.begin(),Numbers.end());
    std::cout << Numbers[n-1]*Numbers[n-2]<< std::endl;
  return 0;
}
