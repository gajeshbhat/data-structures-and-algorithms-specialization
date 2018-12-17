#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int amount,numberofCoins=0,totalMoney=0;
  std::cin >> amount;
  while (totalMoney!=amount) {
    if (totalMoney+10 <= amount) {
      totalMoney+=10;
    }
    else if(totalMoney+5 <= amount){
      totalMoney+=5;
    }
    else{
      totalMoney+=1;
    }
    numberofCoins++;
  }
  std::cout << numberofCoins << std::endl;
  return 0;
}
