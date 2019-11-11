#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::cin;
using std::cout;

// Naive Greedy method
double get_max_value_in_bag_naive(std::vector<std::pair<int,int>> items_bag,int max_weight){
  double max_value = 0;
  double existing_weight = 0;

while (existing_weight <= max_weight) {

    double per_unit_value = 0;
    int per_unit_value_index = 0;

    for (size_t i = 0; i < items_bag.size(); i++) {
      if ( (items_bag[i].first/items_bag[i].second) > per_unit_value) {
        per_unit_value = (items_bag[i].first/items_bag[i].second);
        per_unit_value_index = i;
      }
    }

    if (items_bag[per_unit_value_index].second + existing_weight > max_weight) {
      double remaining_weight = max_weight - existing_weight;
      max_value+= items_bag[per_unit_value_index].first * (remaining_weight/items_bag[per_unit_value_index].second);
      break;
    }
    else{
      max_value += items_bag[per_unit_value_index].first;
      existing_weight+=items_bag[per_unit_value_index].second;
      items_bag[per_unit_value_index].first = 0;
    }
  }
  return max_value;
}

// Optimal greedy
bool sort_per_unit(const std::pair<int,int> &first_pair,const std::pair<int,int> &second_pair){
  return (first_pair.first / first_pair.second) > (second_pair.first / second_pair.second);
}

double get_max_value_in_bag_optimal(std::vector<std::pair<int,int>> items_bag,int max_weight){
  double max_value = 0;
  double existing_weight = 0;

  std::sort(items_bag.begin(),items_bag.end(),sort_per_unit);

  for (size_t i = 0; i < items_bag.size(); i++) {
    if (items_bag[i].second + existing_weight > max_weight) {
      double remaining = max_weight - existing_weight;
      max_value+= items_bag[i].first * (remaining/items_bag[i].second);
      break;
    }
    max_value+=items_bag[i].first;
    existing_weight+=items_bag[i].second;
  }

  return max_value;
}

int main(int argc, char const *argv[]) {
  int number_of_items_input,max_weight_input;
  std::cin >> number_of_items_input >> max_weight_input;

  std::vector<std::pair<int,int>> items_bag;

  for (size_t i = 0; i < number_of_items_input; i++) {
    int value,weight;
    std::cin >> value >> weight;
    items_bag.push_back({value,weight});
  }

  std::cout << get_max_value_in_bag_naive(items_bag,max_weight_input) << '\n';
  return 0;
}
