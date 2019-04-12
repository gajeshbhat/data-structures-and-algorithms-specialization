#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

template<typename P>
void print_values(const std::vector<P> &values) {
  for(auto ele:values){
    std::cout << ele << ' ';
  }
  std::cout << '\n';
}

template<typename CDP>
CDP change_coins_dp(set<CDP>&coins,CDP money){
std::vector<int> sub_coins(money+1);
if (money == 0) {
  return 0;
}
sub_coins[0] = 1;
for (size_t i = 1; i <= money; i++) {
  auto coin_it = coins.find(i);
  if (coin_it == coins.end()) {
    sub_coins[i] = sub_coins[i-1] + 1;
  }
  else{
    sub_coins[i] = 1;
  }
}
print_values(sub_coins);
return sub_coins[money];
}

template<typename CDG>
CDG change_coins_greedy(const vector<CDG>&coins,CDG money){
CDG money_left = money;
CDG change_count = 0;
while (money_left) {
  CDG largest_denom = INT_MIN;
for (size_t i = 0; i < coins.size(); i++) {
  if (coins[i] <= money_left && money_left - coins[i] >= 0 && coins[i] > largest_denom) {
    largest_denom = coins[i];
  }
}
  if (largest_denom == INT16_MIN) {
    return 0;
  }
  money_left-=largest_denom;
  change_count++;
}
return change_count;
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

std::set<int>get_seq_set(std::vector<int> &values){
  std::set<int>values_set;
  for(auto ele:values){
    values_set.insert(ele);
  }
  return values_set;
}

void stress_test(int number_of_tests){
  for (size_t i = 0; i < number_of_tests; i++) {

  // Time shown are approximate values.
  std::vector<int> test_seq_dp = get_random_sequence(10,10);
  std::vector<int> test_seq_greedy = test_seq_dp;
  int money_test_input = get_random_number(10);

  clock_t start_time,end_time;

  std::set<int>test_seq_dp_set = get_seq_set(test_seq_dp);
  cout << "Using DP function.\n";
  start_time = clock();
  auto result_dp = change_coins_dp(test_seq_dp_set,money_test_input);
  end_time =clock();
  cout << "Time take in seconds : " << (double)(end_time-start_time)/CLOCKS_PER_SEC << "\n";

  cout<<"Using Greedy function.\n";
  start_time = clock();
  auto result_greddy = change_coins_greedy(test_seq_greedy,money_test_input);
  end_time =clock();
  cout << "Time taken in seconds: " << (double)(end_time-start_time)/CLOCKS_PER_SEC << "\n";

  if(result_dp == result_greddy){
    cout<<"OK.\n";
  }
  else{
    cout<<"ERROR..\n";
    std::cout << money_test_input << '\n';
    for (size_t i = 0; i < test_seq_dp.size(); i++) {
      std::cout << test_seq_dp[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "Your output :" << '\n';
    std::cout << result_dp << '\n';
    std::cout << "Correct output: " << '\n';
    std::cout << result_greddy << '\n';
    break;
  }
  std::cout << '\n';
}
}

int main(int argc, char const *argv[]) {
  stress_test(10);
  return 0;
}
