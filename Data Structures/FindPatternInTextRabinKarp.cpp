#include <iostream>
#include <string>
#include <map>

//Although it is one of the fastest Implementation it only passes 36/51 Coursera Test Cases!
void RabinKarpPatternSearch(std::string inputString,std::string searchPattern){
  std::map<std::string,int>searchMap;

  searchMap[searchPattern]=1;
  size_t count =inputString.size();

  for (size_t i = 0; i < count; i++) {
    std::string tempSearchString = inputString.substr(i,searchPattern.size()); // Creation of temprory search sting
    if (searchMap.find(tempSearchString)!=searchMap.end()) {
        std::cout << i << " ";
    }
  } //End of Iteration
}

int main(int argc, char const *argv[]) {
  std::string inputStr,inputPattern;
  std::cin >> inputPattern;
  std::cin >> inputStr;
  RabinKarpPatternSearch(inputStr,inputPattern);
  return 0;
}
