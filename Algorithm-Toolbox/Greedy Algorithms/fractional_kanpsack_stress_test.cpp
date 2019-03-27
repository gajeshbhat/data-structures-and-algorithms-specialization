#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void print_values(const T &pair_vector){
  for(auto element:pair_vector){
    std::cout << element.first << " " << element.second << '\n';
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
