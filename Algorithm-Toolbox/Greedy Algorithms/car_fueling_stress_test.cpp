#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cin;
using std::cout;

// algorithms
template<typename MNAIVE>
MNAIVE get_min_refuels_naive(std::vector<MNAIVE> &gas_stations,MNAIVE tank_limit){
  size_t i,j;
  MNAIVE total_refills = 0;
  for (i = 0; i < gas_stations.size()-1; i++) {
    size_t last_fuelled = i;
    for (j = i+1; j < gas_stations.size(); j++) {
      if (gas_stations[j] - gas_stations[i] > tank_limit) {
        total_refills++;
        i = j-1;
        break;
      }
    }
    if (i==last_fuelled && total_refills > 0) {
      return -1;
    }
  }
return total_refills;
}

template<typename MINREF>
MINREF get_min_refuels_greedy(std::vector<MINREF> &gas_stations,MINREF tank_limit){
  MINREF current_station = 0;
  MINREF total_refills = 0;

  while (current_station < gas_stations.size()) {
    int last_refuel_at = current_station;
    while (current_station < gas_stations.size() && gas_stations[current_station+1] - gas_stations[last_refuel_at] <= tank_limit) {
      current_station++;
    }
    if (last_refuel_at == current_station) {
      // We could not reach next station. Journey is impossible
      return -1;
    }
    if (current_station < gas_stations.size()) {
      total_refills++;
    }
  }
return total_refills;
}

// Test Suite
template<typename TEST>
std::vector<TEST> get_random_sequence_sorted(TEST size,TEST limit){
  std::vector<TEST> values;
  for (size_t i = 0; i < size; i++) {
    values.push_back(rand()%limit+1);
  }
  std::sort(values.begin(),values.end());
  return values;
}

template<typename N>
N get_random_number(N limit){
  return (rand()%limit);
}

template<typename P>
void print_values(const P &values){
  for(const auto element:values){
    std::cout << element << ' ';
  }
  std::cout << "" << '\n';
}

bool run_test(){
  std::vector<int> random_sorted_distances = get_random_sequence_sorted(5, 10);
  int car_capacity = get_random_number(10);
  int result_naive = get_min_refuels_naive(random_sorted_distances,car_capacity);
  int result_greedy = get_min_refuels_greedy(random_sorted_distances,car_capacity);
  if (result_greedy != result_naive) {
    std::cout << random_sorted_distances.size() << " " << car_capacity << '\n';
    print_values(random_sorted_distances);
    std::cout << "Wrong Answer! " << "Correct output: " << result_greedy << " Your output: " << result_naive << '\n';
    return false;
  }
  else{
    std::cout << "OK." << '\n';
    return true;
  }
}

int main(int argc, char const *argv[]) {
  while (true) {
    bool test_success = run_test();
    if (!test_success) {
      break;
    }
  }
  return 0;
}
