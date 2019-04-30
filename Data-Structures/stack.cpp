#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class Stack {
private:
  Node* head;

public:
  Stack (){
    this->head = NULL;
  }

  Node* get_new_node(int value){
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
  }

  void create_head(int value){
    head = get_new_node(value);
  }

  bool is_empty(){
    return head == NULL;
  }

  int top(){
    if (is_empty()) {
      std::cout << "Empty Stack!" << '\n';
      return -1;
    }
    return head->data;
  }
  void push(int value){
    if (is_empty()) {
      create_head(value);
    }
    else{
      Node* new_node = get_new_node(value);
      new_node->next = head;
      head = new_node;
    }
  }
  void pop(){
    if (is_empty()) {
      std::cout << "Empty Stack!" << '\n';
    }
    else{
      head = head->next;
    }
  }

};

int main(int argc, char const *argv[]) {
  Stack test_stk = Stack();
  test_stk.push(10);
  test_stk.push(20);
  test_stk.push(30);
  std::cout << test_stk.top() << '\n';
  test_stk.pop();
  std::cout << test_stk.top() << '\n';
  test_stk.pop();
  std::cout << test_stk.top() << '\n';
  test_stk.pop();
  std::cout << test_stk.top() << '\n';
  return 0;
}
