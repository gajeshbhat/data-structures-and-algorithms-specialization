#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;


int get_min_groups_naive(std::vector<int> children_ages){
  
}

int get_min_groups_optimal(std::vector<int> children_ages){
  int min_set_number = 0;
  int min_group = 0;
  std::sort(children_ages.begin(),children_ages.end());
  for (size_t i = 1; i < children_ages.size(); i++) {
    if ((abs(children_ages[i] - children_ages[min_group]) > 1)) {
      min_set_number++;
      min_group = i;
    }
  }
  // Add one to cover the last group corner case
  return min_set_number+1;
}

int main(int argc, char const *argv[]) {
  int number_of_children_input;
  std::cin >> number_of_children_input;
  std::vector<int> children_ages_input(number_of_children_input);
  for (auto i = 0; i < number_of_children_input; i++) {
    std::cin >> children_ages_input[i];
  }
  std::cout << get_min_groups_naive(children_ages_input) << '\n';
  return 0;
}
