#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort(std::vector<int> &values,int start_idx,int end_idx){
  if (end_idx - start_idx > 1) {
    int mid_idx = start_idx + (end_idx-start_idx)/2;
    merge_sort(values,start_idx,mid_idx);
    merge_sort(values,mid_idx,end_idx);
    inplace_merge(values.begin()+start_idx,values.begin()+mid_idx,values.begin()+end_idx);
  }
}

int main(int argc, char const *argv[]) {
  int count_input;
  std::cin >> count_input;
  std::vector<int> elements(count_input);
  for (size_t i = 0; i < count_input; i++) {
    std::cin >> elements[i];
  }
  merge_sort(elements ,0,elements.size());
  for (size_t i = 0; i < count_input; i++) {
    std::cout << elements[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
