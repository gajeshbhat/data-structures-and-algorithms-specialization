#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename BS>
bool binary_search_iter(const std::vector<BS> &values, BS search_key){
BS start_idx = 0,end_idx = values.size();

while (end_idx > start_idx) {

  BS mid_idx = (start_idx+end_idx) / 2;
  if (values[mid_idx] == search_key) {
    return true;
  }
  if (values[mid_idx] > search_key) {
    end_idx = mid_idx;
  }
  else{
    start_idx = mid_idx+1;
  }
}
return false;
}

template <typename BSS>
bool search_test_function(const std::vector<BSS> &elements,BSS search_key){
  return std::binary_search(elements.begin(),elements.end(),search_key);
}

// Test suite
template<typename TEST>
std::vector<TEST> get_random_sequence_sorted(TEST size,TEST numbers_upto){
  std::vector<TEST> values;
  for (size_t i = 0; i < size; i++) {
    values.push_back(rand()%numbers_upto+1);
  }
  return values;
}

template<typename N>
N get_random_number(N numbers_upto){
  return (rand()%numbers_upto);
}

template<typename P>
void print_values(const P &values){
for(auto element:values){
  std::cout << element << ' ';
}
std::cout << '\n';
}

void run_tests(int number_of_test){
while (number_of_test--) {

  std::vector<int> test_binary_search = get_random_sequence_sorted(100, 100);
  int test_search_key = get_random_number(100);
  std::sort(test_binary_search.begin(),test_binary_search.end());

  bool custom_result = binary_search_iter(test_binary_search,test_search_key);
  bool library_test_result = search_test_function(test_binary_search,test_search_key);

  if (custom_result == library_test_result) {
     std::cout << "OK." << '\n';
   }
   else{
     std::cout << "Wrong Answer!" << '\n';
     std::cout << "Correct answer : "<< library_test_result << "Your answer: " << custom_result << '\n';
     std::cout << test_binary_search.size() << test_search_key << '\n';
     print_values(test_binary_search);
     break;
   }
}
}

int main(int argc, char const *argv[]) {
  run_tests(100);
  return 0;
}
