#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;

template<typename NGCD>
NGCD NaiveGCD(NGCD first_value,NGCD second_value){
  NGCD gcd_value = 1;
  for (size_t i = 2; i < (first_value+second_value); i++) {
    if (first_value % i == 0 && second_value %i == 0) {
      gcd_value = i;
    }
  }
  return gcd_value;
}

template<typename EGCD>
EGCD EuclidGCD(const EGCD &first_value,const EGCD &second_value){
  if (second_value == 0) {
    return first_value;
  }
  return EuclidGCD(second_value,(first_value % second_value));
}

// Test suite

template<typename T>
std::pair<T,T> get_random_number_pairs(const T &limit){
  return {rand() % limit+1 , rand() % limit+1};
}

bool run_test(){
  auto random_number_pair = get_random_number_pairs(10000000);
  auto result_naive = NaiveGCD(random_number_pair.first,random_number_pair.second);
  auto result_library = EuclidGCD(random_number_pair.first,random_number_pair.second);
  if (result_naive != result_library) {
    std::cout << "Wrong answer! for Inputs "<< random_number_pair.first << " and " << random_number_pair.second << '\n';
    std::cout << "Correct output : " << result_library << " Your output : "<< result_naive << '\n';
    return false;
  }
  else{
    std::cout << "OK." << '\n';
    return true;
  }
}

int main(int argc, char const *argv[]) {
  while (true) {
    bool success  = run_test();
    if (!success) {
      break;
    }
  }
  return 0;
}
