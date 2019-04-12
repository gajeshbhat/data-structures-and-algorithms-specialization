#include <iostream>
#include <vector>
#include <set>

using namespace std;

template<typename P>
void print_values(const std::vector<P> &values) {
  for(auto ele:values){
    std::cout << ele << ' ';
  }
  std::cout << '\n';
}

int change_coins_dp(set<int>&coins,int money){
std::vector<int> sub_coins(money+1);
for (size_t i = 1; i <= money; i++) {
  auto coin_it = coins.find(i);
  if (coin_it == coins.end()) {
    sub_coins[i] = sub_coins[i-1] + 1;
  }
  else{
    sub_coins[i] = 1;
  }
}
return sub_coins[money];
}

int change_coins_greedy(const vector<int>&coins,int money){
int money_left = money;
int change_count=0;
while (money_left) {
  int less_than_total_idx = 0;
  for (size_t i = 0; i < coins.size(); i++) {
    if (coins[less_than_total_idx] < coins[i] && coins[i] <= money_left) {
      less_than_total_idx = i;
    }
  }
  money_left-=coins[less_than_total_idx];
  change_count++;
}
return change_count;
}

int main(int argc, char const *argv[]) {
  int number_of_coin_denominations,total_money;
  std::cin >> number_of_coin_denominations>>total_money;
  /*set<int>coins_input;
  for (size_t i = 0; i < number_of_coin_denominations; i++) {
    int value;
    std::cin >> value;
    coins_input.insert(value);
  }*/
  std::vector<int> coins_input(number_of_coin_denominations);
  for (size_t i = 0; i < number_of_coin_denominations; i++) {
    std::cin >> coins_input[i];
  }
  std::cout << change_coins_greedy(coins_input,total_money) << '\n';
  return 0;
}
