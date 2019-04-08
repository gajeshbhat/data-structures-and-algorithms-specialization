#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

template<typename SL>
void selection_sort(std::vector<SL> &values) {
  for (size_t i = 0; i < values.size(); i++) {
    SL min_idx = i;
    for (size_t j = i+1; j < values.size(); j++) {
      if (values[j] < values[min_idx]) {
        min_idx = j;
      }
    }
    iter_swap(values.begin()+i,values.begin()+min_idx);
  }
}

// Test Suite

template<typename TEST>
std::vector<TEST> get_random_sequence(TEST size,TEST limit){
  std::vector<TEST> values;
  for (size_t i = 0; i < size; i++) {
    values.push_back(rand()%limit+1);
  }
  return values;
}

template<typename N>
N get_random_number(N limit){
  return (rand()%limit);
}

void stress_test(int number_of_tests){
  for (size_t i = 0; i < number_of_tests; i++) {

  // Time shown are approximate values.
  std::vector<int> test_seq_lib = get_random_sequence(get_random_number(100),get_random_number(100));
  std::vector<int> test_seq_cust = test_seq_lib;

  clock_t start_time,end_time;

  start_time = clock();
  sort(test_seq_lib.begin(),test_seq_lib.end());
  cout << "Sorted using library function.\n";
  end_time =clock();
  cout << "Time take in seconds : " << (double)(end_time-start_time)/CLOCKS_PER_SEC << "\n";

  start_time = clock();
  selection_sort(test_seq_cust);
  cout<<"Sorted using custom function.\n";
  end_time =clock();
  cout << "Time taken in seconds: " << (double)(end_time-start_time)/CLOCKS_PER_SEC << "\n";

  if(test_seq_lib == test_seq_cust){
    cout<<"OK.\n";
  }
  else{
    cout<<"ERROR.Sorted improperly.\n";
    std::cout << "Your output :" << '\n';
    std::cout << test_seq_cust.size() << '\n';
    for (size_t i = 0; i < test_seq_cust.size(); i++) {
      std::cout << test_seq_cust[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Correct output: " << '\n';
    for (size_t i = 0; i < test_seq_lib.size(); i++) {
      std::cout << test_seq_lib[i] << ' ';
    }
  }
  std::cout << '\n';
}
}

int main(int argc, char const *argv[]) {
  stress_test(10);
  return 0;
}
