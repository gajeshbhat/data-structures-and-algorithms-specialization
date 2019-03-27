#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int get_min_refuels(std::vector<int> &gas_stations,int tank_limit){
  int current_station = 0;
  int total_refills = 0;

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
int main(int argc, char const *argv[]) {
  int tank_limit_input,number_of_gas_stations;
  std::cin >> number_of_gas_stations >> tank_limit_input;
  std::vector<int> gas_stations_distance(number_of_gas_stations);
  for (size_t i = 0; i < number_of_gas_stations; i++) {
    std::cin >> gas_stations_distance[i];
  }
  std::cout << get_min_refuels_naive(gas_stations_distance,tank_limit_input) << '\n';
  return 0;
}
