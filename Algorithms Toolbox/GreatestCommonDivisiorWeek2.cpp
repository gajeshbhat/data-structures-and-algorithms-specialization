#include <iostream>
using namespace std;

long long unsigned int ComputeGCD(long long unsigned int a,long long unsigned int b){
      long long unsigned int temp;
      while (b!=0) {
        a%=b;
        temp=a;
        a=b;
        b=temp;
      }
      return a;
}

int main(int argc, char const *argv[]) {
    long long unsigned int a,b;
    std::cin >> a>>b;
    std::cout << ComputeGCD(a,b) << std::endl;
   return 0;
 }
