#include <iostream>
#include <vector>

using namespace std;

std::vector<int> get_poly_product_naive(const std::vector<int> &expr_a,const std::vector<int> &expr_b){
  std::vector<int> result(2*expr_a.size()-1);
  for (size_t i = 0; i < expr_a.size(); i++) {
    for (size_t j = 0; j < expr_b.size(); j++) {
      result[i+j]+= expr_a[i] * expr_b[j];
    }
  }
  return result;
}

std::vector<int> get_poly_product_recur_naive(const std::vector<int> &expr_a,const std::vector<int> &expr_b,int l_bound,int _ubound){

}
std::vector<int> get_poly_product_recur_karastuba(const std::vector<int> &expr_a,const std::vector<int> &expr_b,int l_bound,int _ubound){

}
void print_polynomial_expr(const std::vector<int> &expr){
  for (size_t i = 0; i < expr.size(); i++) {
    std::cout << expr[i] << ' ';
  }
  std::cout << '\n';
}

int main(int argc, char const *argv[]) {
  int order_input;
  std::cin >> order_input;
  std::vector<int> expr_a_input(order_input);
  std::vector<int> expr_b_input(order_input);
  for (size_t i = 0; i < order_input; i++) {
    std::cin >> expr_a_input[i];
  }
  for (size_t i = 0; i < order_input; i++) {
    std::cin >> expr_b_input[i];
  }
  std::vector<int> result = get_poly_product(expr_a_input,expr_b_input);
  print_polynomial_expr(result);
  return 0;
}
