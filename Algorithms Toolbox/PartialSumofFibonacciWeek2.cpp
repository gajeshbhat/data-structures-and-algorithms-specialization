#include <iostream>
using namespace std;
long long unsigned PartialFiboSum(long long unsigned from, long long unsigned to) {
    if (to <= 1)
        return to;

    long long unsigned previous = 0;
    long long unsigned current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long unsigned sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int main(int argc, char const *argv[]) {
    long long unsigned int m,n;
    std::cin >> m>>n;
    std::cout << PartialFiboSum(m,n) << std::endl;
  return 0;
}
