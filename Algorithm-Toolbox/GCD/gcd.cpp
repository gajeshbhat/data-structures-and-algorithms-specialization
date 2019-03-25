#include <iostream>

using std::cin;
using std::count;

long unsigned int NaiveGCD(long int first_value,long int second_value){
  long int gcd_value = 1;
  for (size_t i = 2; i < (first_value+second_value); i++) {
    if (first_value % i == 0 && second_value %i == 0) {
      gcd_value = i;
    }
  }
  return gcd_value;
}
long unsigned int EuclidGCD(long unsigned int first_value,long unsigned int second_value){
  if (second_value == 0) {
    return first_value;
  }
  return EuclidGCD(second_value,(first_value % second_value));
}

int main(int argc, char const *argv[]) {
  long int first_value_input;
  long int second_value_input;
  std::cin >> first_value_input >> second_value_input;
  std::cout << "GCD of "<< first_value_input << " and " << second_value_input <<" is " << EuclidGCD(first_value_input,second_value_input) << '\n';
  return 0;
}
