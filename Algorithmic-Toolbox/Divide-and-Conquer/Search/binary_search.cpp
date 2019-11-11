#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search_iter(const std::vector<int> &values, int search_key){
int start_idx = 0;
int end_idx = values.size();

while (end_idx > start_idx) {
  int mid_idx = (start_idx+end_idx) / 2;

  if (values[mid_idx] == search_key) {
    return true;
  }
  if (values[mid_idx] > search_key) {
    end_idx = mid_idx;
  }
  else{
    start_idx = mid_idx+1;
  }

}
return false;
}

bool binary_search_recursive(const std::vector<int> &values,int start_idx,int end_idx ,int search_key){
  if (start_idx > end_idx) {
    return false;
  }
  int mid_idx = start_idx + ((end_idx - start_idx)/2);
  if (values[mid_idx] == search_key) {
    return true;
  }
  else if (values[mid_idx] > search_key) {
    return binary_search_recursive(values,start_idx,mid_idx-1,search_key);
  }
  else{
    return binary_search_recursive(values,mid_idx+1,end_idx,search_key);
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int count_input,search_key_input;
  std::cin >> count_input >> search_key_input;

  std::vector<int> values(count_input);

  for (size_t i = 0; i < count_input; i++) {
    std::cin >> values[i];
  }

  std::sort(values.begin(),values.end());
  //bool result = binary_search_iter(values,search_key_input);
  bool result = binary_search_recursive(values,0,values.size()-1,search_key_input);

  if (result == true) {
    std::cout << "Found!" << '\n';
  }
  else{
    std::cout << "Not found!" << '\n';
  }

  return 0;
}
