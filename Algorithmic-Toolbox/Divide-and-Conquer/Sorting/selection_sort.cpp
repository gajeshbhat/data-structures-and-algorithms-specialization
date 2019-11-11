#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n^2) time complexity
void selection_sort(std::vector<int> &values){
  for (size_t i = 0; i < values.size(); i++) {
    int min_idx = i;
    for (size_t j = i+1; j < values.size(); j++) {
      if (values[j] < values[min_idx]) {
        min_idx = j;
      }
    }
    iter_swap(values.begin()+i, values.begin()+min_idx);
  }
}

int main(int argc, char const *argv[]) {
  int count_input;
  std::cin >> count_input;
  std::vector<int> values(count_input);
  for (size_t i = 0; i < count_input; i++) {
    std::cin >> values[i];
  }
  selection_sort(values);
  for (size_t i = 0; i < count_input; i++) {
    std::cout << values[i] << ' ';
  }
  std::cout << "\n" << '\n';
  return 0;
}
