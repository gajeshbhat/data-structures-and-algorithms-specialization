#include <iostream>
#include <map>

int getMajority(std::map<long int,long int>MajorityMap,long int n){
  for(std::map<long int,long int>::const_iterator it = MajorityMap.begin();it!=MajorityMap.end();++it){
    if (it->second > n/2) {
      return 1;
    }
  }
  return 0;
}
int main(int argc, char const *argv[]) {
  long int count;
  std::cin >> count;

  std::map<long int,long int>MajorityMap;
  for (size_t i = 0; i < count; i++) {
    long int value;
    std::cin >> value;
    MajorityMap[value]++;
  }
  std::cout << getMajority(MajorityMap,count) << std::endl;
  return 0;
}
