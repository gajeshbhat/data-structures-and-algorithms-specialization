#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename LS>
bool linear_search(const std::vector<LS> &elements,LS search_key){
  for (size_t i = 0; i < elements.size(); i++) {
    if (elements[i] == search_key) {
      return true;
    }
  }
  return false;
}

template <typename LLS>
bool search_test_function(const std::vector<LLS> &elements,LLS search_key){
  return std::find(elements.begin(),elements.end(),search_key) != elements.end();
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
  std::vector<int> test_linear_search = get_random_sequence_sorted(100, 100);
  int test_search_key = get_random_number(100);
  bool custom_result = linear_search(test_linear_search,test_search_key);
  bool library_test_result = search_test_function(test_linear_search,test_search_key);
   if (custom_result == library_test_result) {
     std::cout << "OK." << '\n';
   }
   else{
     std::cout << "Wrong Answer!" << '\n';
     std::cout << "Correct answer : "<< library_test_result << "Your answer: " << custom_result << '\n';
     std::cout << test_linear_search.size() << test_search_key << '\n';
     print_values(test_linear_search);
     break;
   }
}
}

int main(int argc, char const *argv[]) {
  run_tests(100);
  return 0;
}
