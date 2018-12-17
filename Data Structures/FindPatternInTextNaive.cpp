#include <iostream>
#include <string>
#include <algorithm>

//This Passes 47/52 Test cases on Coursera. Better Implemented using Rabin Karp Hash Method.

int main(int argc, char const *argv[]) {
  std::string searchString,inputString;
  std::cin >> searchString;
  std::cin >> inputString;
  while (inputString.find(searchString)!=std::string::npos) {
      size_t strIt = inputString.find(searchString);
      std::cout << strIt << " ";
      inputString[strIt]+=1;
  }
  return 0;
}
