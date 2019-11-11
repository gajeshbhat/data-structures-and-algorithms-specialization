#include <iostream>

using std::cin;
using std::count;

long int fibonacci_naive(long int number){
  if (number <= 1) {
    return number;
  }
  return (fibonacci_naive(number - 1) + fibonacci_naive(number - 2));
}

// Breaks at n=1075 (So n<= 1074)
long long unsigned int fibonacci_optimal(long int number){
  if (number <= 1) {
    return number;
  }
  long long unsigned int previous_value = 1;
  long long unsigned int previous_of_previous = 0;
  long long unsigned int result;
  for (size_t i = 0; i < number; i++) {
    result = previous_value + previous_of_previous;
    previous_of_previous = previous_value;
    previous_value =result;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int series_limit_input;
  std::cin >> series_limit_input;
  std::cout << "Fibonacci Number of " <<  series_limit_input << " is : " << fibonacci_optimal(series_limit_input) << '\n';
  return 0;
}
