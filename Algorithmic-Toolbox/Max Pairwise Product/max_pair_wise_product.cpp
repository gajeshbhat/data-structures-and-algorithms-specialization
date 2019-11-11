#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::sort;

long long int MaxPairwiseProductNaive(const vector<long int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((long long )numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

long long int MaxPairwiseProductOptimalOne(vector<long int>numbers){
  sort(numbers.begin(),numbers.end());
  long int size = numbers.size();
  return numbers[size-1] * numbers[size-2];
}

long long int MaxPairwiseProductOptimalTwo(const vector<long int>& numbers){
  long long int max_value = INT_MIN;
  long long int second_max_value = max_value;
  for (size_t i = 0; i < numbers.size(); i++) {
    if (numbers[i] > max_value) {
      second_max_value = max_value;
      max_value = numbers[i];
    }
    else if (numbers[i] <= max_value && numbers[i] > second_max_value) {
      second_max_value = numbers[i];
    }
  }
  return max_value * second_max_value;
}

long long int MaxPairwiseProductOptimalThree(const vector<long int>& numbers){
  long long int max_value = INT_MIN;
  long long int second_max_value = max_value;
  for (size_t i = 0; i < numbers.size(); i++) {
     second_max_value = (numbers[i] > max_value) ? max_value : second_max_value;
     max_value = (numbers[i] > max_value) ? numbers[i] : max_value;
     second_max_value = (numbers[i] < max_value && numbers[i] > second_max_value) ? numbers[i] : second_max_value;
  }
  return max_value * second_max_value;
}

int main() {
    int n;
    cin >> n;
    vector<long int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProductOptimalThree(numbers);
    cout << result << "\n";
    return 0;
}
