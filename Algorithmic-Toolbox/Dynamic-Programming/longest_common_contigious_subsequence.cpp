#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

template<typename P>
void print_values(const std::set<P> &values) {
  for(auto ele:values){
    std::cout << ele << ' ';
  }
  std::cout << '\n';
}

template<typename PG>
void print_grid(const std::vector<std::vector<PG>>&grid){
  for(auto row : grid){
    for(auto element: row){
      std::cout << element << ' ';
    }
    std::cout << '\n';
  }
}

// Naive solution 2^n of no use for n > 15

std::set<string> get_all_substr(string str){
  std::set<string> all_str;
  for (int i = 0; i < str.length(); i++){
    for (int len = 1; len <= str.length() - i; len++){
            all_str.insert(str.substr(i, len));
        }
  }
  return all_str;
}

int get_contigious_lcs_count_naive(string first_str,string second_str){
  std::set<string> first_str_subs = get_all_substr(first_str);
  std::set<string> second_str_subs = get_all_substr(second_str);

  string longest_substr;
  for(auto ele:first_str_subs){
    if (second_str_subs.find(ele) != second_str_subs.end()) {
      if (ele.length() > longest_substr.length()) {
        longest_substr.clear();
        longest_substr = ele;
      }
    }
  }
  return longest_substr.length();
}

int main(int argc, char const *argv[]) {
  string str1_input,str2_input;
  std::cin >> str1_input>>str2_input;
  std::cout << get_contigious_lcs_count_naive(str1_input,str2_input) << '\n';
  return 0;
}
