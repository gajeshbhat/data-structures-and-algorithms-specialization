#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[]) {
  long long unsigned int n;
  std::cin >> n;
  std::vector<long long unsigned int>FiboNum;
  for (size_t i = 0; i <=n; i++) {
    if (i<=1) {
      FiboNum.push_back(i);
    }
    else{
      FiboNum.push_back((FiboNum[i-1]+FiboNum[i-2])%10);
    }
  }
  std::cout <<FiboNum[n]<< std::endl;
  return 0;
}
