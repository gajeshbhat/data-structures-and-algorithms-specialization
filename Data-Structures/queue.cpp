#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class Queue {
private:
  Node* head;
  Node* tail;

public:
  Queue (){
    head = tail = NULL;
  }

  bool is_empty(){
    return head == NULL;
  }

  Node* get_new_node(int value){
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
  }

  void create_head(int value){
    head = tail = get_new_node(value);
  }
  int peek_at_tail(){
    if (is_empty()) {
      std::cout << "Empty Queue" << '\n';
      return -1;
    }
    else{
      return tail->data;
    }
  }

  int peek_at_head(){
    if (is_empty()) {
      std::cout << "Empty Queue" << '\n';
      return -1;
    }
    else{
      return head->data;
    }
  }

  void insert(int value){
    if (is_empty()) {
      create_head(value);
    }
    else{
      tail->next = get_new_node(value);
      tail = tail->next;
    }
  }

  void remove_from_head(){
    if (is_empty()) {
      std::cout << "Empty List!" << '\n';
    }
    else{
      if (head->next == NULL) {
        head = tail = NULL;
      }
      else{
        head = head->next;
      }
    }
  }

};

int main(int argc, char const *argv[]) {
  Queue test_que = Queue();
  test_que.insert(10);
  test_que.insert(20);
  test_que.insert(30);
  std::cout << test_que.peek_at_tail() << '\n';
  std::cout << test_que.peek_at_head() << '\n';
  test_que.remove_from_head();
  std::cout << test_que.peek_at_head() << '\n';
  test_que.remove_from_head();
  test_que.remove_from_head();
  std::cout << test_que.peek_at_head() << '\n';
  return 0;
}
