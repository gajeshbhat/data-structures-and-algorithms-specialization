#include <iostream>
#include <cstdio>
#include <map>

int main(int argc, char const *argv[]) {
  long int n,capacity;
  std::cin >> n>>capacity;

  std::map<long int,long int>lootBag;
  for (size_t i = 0; i < n; i++) {
    long int value,lootWeight;
    std::cin >>value>>lootWeight;
    lootBag[value]=lootWeight;
  }

  float fractionalvalue=0.0000;
  int maxWeight=capacity;

std::map<long int,long int>::reverse_iterator it = lootBag.rbegin();

      while(maxWeight!=0)
     {
          if(it==lootBag.rend()){
            it=lootBag.rbegin();
          }

          if (maxWeight-(it->second) >= 0) {
           maxWeight-=(it->second);
           fractionalvalue+=(float)(it->first);
         }
        else if(it->second > capacity && lootBag.size() == 1){
            maxWeight-=capacity;
            fractionalvalue+=(float)(it->first)/(it->second)*(float)capacity;
        }
        ++it;
     }
  printf("%.4f\n",fractionalvalue);
  return 0;
}
