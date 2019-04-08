#include <iostream>
#include <vector>

using namespace std;

bool linear_search(const std::vector<int> &elements,int key){
  for (size_t i = 0; i < elements.size(); i++) {
    if (elements[i] == key) {
      return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int count_input,search_key_input;
  std::cin >> count_input >> search_key_input;
  std::vector<int> values_input(count_input);
  for (size_t i = 0; i < count_input; i++) {
    std::cin >> values_input[i];
  }
  std::cout << linear_search(values_input,search_key_input) << '\n';
  return 0;
}
