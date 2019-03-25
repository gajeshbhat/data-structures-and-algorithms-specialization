#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;
using std::rand;

template <typename MPP>
MPP MaxPairwiseProductOptimalThree(const vector<MPP>& numbers){
  MPP max_value = INT_MIN;
  MPP second_max_value = max_value;
  for (size_t i = 0; i < numbers.size(); i++) {
     second_max_value = (numbers[i] >= max_value) ? max_value : second_max_value;
     max_value = (numbers[i] > max_value) ? numbers[i] : max_value;
     second_max_value = (numbers[i] < max_value && numbers[i] > second_max_value) ? numbers[i] : second_max_value;
  }
  return max_value * second_max_value;
}

template <typename MPPN>
MPPN MaxPairwiseProductNaive(const vector<MPPN>& numbers) {
  MPPN result = 0;
  MPPN n = numbers.size();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

// Test suite

template<typename T>
void print_values(T values){
  for(auto element : values){
    std::cout << element << ' ';
  }
  std::cout << "" << '\n';
}

template<typename S>
std::vector<S> generate_test(S size ,S each_value_limit){
  std::vector<S> test_values;
  for (size_t i = 0; i < size; i++) {
    test_values.push_back(rand()%each_value_limit);
  }
  return test_values;
}

template<typename P>
bool run_test(const P &values){
  std::cout << values.size() << '\n';
  auto res_optimal = MaxPairwiseProductOptimalThree(values);
  auto res_naive = MaxPairwiseProductNaive(values);
  if (res_optimal == res_naive) {
    std::cout << "OK." << '\n';
    return true;
  }
  else{
    print_values(values);
    std::cout << "Wrong Answer! Naive says: "<< res_naive << " Optimal algorithm says : "<< res_optimal  << '\n';
    return false;
  }
}

int main(int argc, char const *argv[]) {
  while (true) {
    std::vector<int> stress_test = generate_test<int>(10,10);
    bool success = run_test(stress_test);
    if (!success) {
      break;
    }
  }
  return 0;
}
