#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long int getLCS(string s1,string s2,string s3){
  string resultant;long int count=s1.size();long int totalCommon=0;
  for (size_t i = 0; i < count; i++) {
    if(s1[i]!=' '){
    if(s1.find(s1[i])!=string::npos && s2.find(s2[i])!=string::npos && s2.find(s2[i])!=string::npos ){
      totalCommon++;
    }
  }
  }
  return totalCommon;
}
int main(int argc, char const *argv[]) {
  string s1,s2,s3;long int n1,n2,n3;
  std::cin >> n1;
  std::cin >> s1;
  std::cin >> n2;
  std::cin >> s2;
  std::cin >> n3; 
  std::cin >> s3;
  std::cout << getLCS(s1,s2,s3) << '\n';
  return 0;
}
