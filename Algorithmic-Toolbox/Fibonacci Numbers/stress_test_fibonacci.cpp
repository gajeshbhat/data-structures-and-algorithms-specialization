#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;
using std::cin;

template<typename FIBONA>
FIBONA fibonacci_naive(FIBONA number){
  if (number <= 1) {
    return number;
  }
  return (fibonacci_naive(number - 1) + fibonacci_naive(number - 2));
}


template<typename FIBOOP>
FIBOOP fibonacci_optimal(FIBOOP number){
  if (number <= 1) {
    return number;
  }

  FIBOOP previous_value = 1;
  FIBOOP previous_of_previous = 0;
  FIBOOP result;

  for (size_t i = 0; i < number; i++) {
    result = previous_value + previous_of_previous;
    previous_of_previous = previous_value;
    previous_value =result;
  }
  return result;
}


// Test suite

template<typename TEST>
TEST get_random_value(TEST limit){
return std::rand()%limit+1;
}

bool run_test(){
  auto test_value = get_random_value(30);
  auto naive_result = fibonacci_naive(test_value+1);
  auto optimal_result = fibonacci_optimal(test_value);
  if (naive_result != optimal_result) {
    std::cout << "Wrong Answer." << '\n';
    std::cout << "Correct output is "<< optimal_result << " Your output is " << naive_result << '\n';
    return false;
  }
  std::cout << "OK." << '\n';
  return true;
}

int main(int argc, char const *argv[]) {
  while (true) {
    bool success = run_test();
    if (!success) {
      break;
    }
  }
  return 0;
}
