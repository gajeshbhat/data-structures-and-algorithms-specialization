#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <typeinfo>

using namespace std;

template<typename PG>
void print_grid(const std::vector<std::vector<PG>>&grid){
  for(auto row : grid){
    for(auto element: row){
      std::cout << element << ' ';
    }
    std::cout << '\n';
  }
}

void init_values(std::vector<std::vector<int>> &grid,int row_size){
  for (size_t i = 0; i < grid.size(); i++) {
    std::vector<int> row(row_size);
    grid[i] = row;
  }
}

int get_lcs_count(string first_str,string second_str){
  std::vector<std::vector<int>>lcs_table(first_str.length()+1);
  init_values(lcs_table,second_str.length()+1);

  for (size_t i =1; i < first_str.length()+1; i++) {
    for (size_t j = 1; j < second_str.length()+1; j++) {
      if (second_str[j-1] == first_str[i-1] ) {
        lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
      }
      else{
        lcs_table[i][j] = max(lcs_table[i][j-1],lcs_table[i-1][j]);
      }
    }
  }
return lcs_table[first_str.length()][second_str.length()];
}

string get_lcs_str(string first_str,string second_str){
  std::vector<std::vector<int>>lcs_table(first_str.length()+1);
  init_values(lcs_table,second_str.length()+1);

  for (size_t i =1; i < first_str.length()+1; i++) {
    for (size_t j = 1; j < second_str.length()+1; j++) {
      if (second_str[j-1] == first_str[i-1] ) {
        lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
      }
      else{
        lcs_table[i][j] = max(lcs_table[i][j-1],lcs_table[i-1][j]);
      }
    }
  }
  // Find the sequence
  int jdx = second_str.length();
  int idx = first_str.length();
  string lcs;

  while (lcs_table[idx][jdx] != 0) {
    if (lcs_table[idx][jdx] != max(lcs_table[idx-1][jdx],lcs_table[idx][jdx-1])) {
      lcs.push_back(first_str[idx-1]);
      idx--;
      jdx--;
    }
    else if (lcs_table[idx][jdx] == lcs_table[idx-1][jdx]) {
      idx--;
    }
    else{
      jdx--;
    }
  }
  std::reverse(lcs.begin(),lcs.end());
  return lcs;
}

int main(int argc, char const *argv[]) {
  string str1_input,str2_input;
  std::cin >> str1_input>>str2_input;
  std::cout << get_lcs_count(str1_input,str2_input) << '\n';
  return 0;
}
