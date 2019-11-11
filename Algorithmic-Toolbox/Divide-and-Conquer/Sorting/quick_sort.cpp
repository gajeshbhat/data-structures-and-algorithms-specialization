#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(std::vector<int> &values,int start_idx,int end_idx){
  int idx = start_idx;
  int pivot_idx = end_idx;
  for(int jdx = start_idx; jdx <= end_idx - 1;jdx++){
    if(values[jdx] <= values[pivot_idx]){
      iter_swap(values.begin()+idx,values.begin()+jdx);
      idx++;
    }
  }
  iter_swap(values.begin()+idx,values.begin()+end_idx);
  return idx;
}

void quick_sort(std::vector<int> &values,int start_idx,int end_idx){
  if (end_idx > start_idx) {
    int pivot_idx = partition(values,start_idx,end_idx);
    quick_sort(values,start_idx,pivot_idx-1);
    quick_sort(values,pivot_idx+1,end_idx);
  }
}

int main(int argc, char const *argv[]) {
  int count_input;
  std::cin >> count_input;
  std::vector<int> elements(count_input);
  for (size_t i = 0; i < count_input; i++) {
    std::cin >> elements[i];
  }
  quick_sort(elements,0,elements.size()-1);
  for (size_t i = 0; i < count_input; i++) {
    std::cout << elements[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
