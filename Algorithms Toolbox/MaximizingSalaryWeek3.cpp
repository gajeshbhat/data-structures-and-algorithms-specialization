#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iterator>
using namespace std;

string integerString(std::vector<long int>vec){
  std::ostringstream oss;

 if (!vec.empty())
 {
   // Convert all but the last element to avoid a trailing ","
   std::copy(vec.begin(), vec.end()-1,
       std::ostream_iterator<int>(oss, ""));

   // Now add the last element with no delimiter
   oss << vec.back();
 }
 return oss.str();
}

int main(int argc, char const *argv[]) {
  long int n;
  std::cin >> n;
  std::vector<long int>integerSet;

  for (size_t i = 0; i < n; i++) {
    long int value;
    std::cin >> value;
    integerSet.push_back(value);
  }
   string answerSting=integerString(integerSet);
   sort(answerSting.begin(),answerSting.end());
   reverse(answerSting.begin(),answerSting.end());
   std::cout << answerSting<< std::endl;
  /*sort(integerSet.begin(),integerSet.end());

  size_t i=n-1;
  while (i!=-1) {
    std::cout <<integerSet[i];
    i--;
  }
  std::cout <<"\n";*/
  return 0;
}
