#include <iostream>
#include <forward_list>

using namespace std;

struct Node{
int data;
Node* next;
};

class SinglyLinkedList {
private:
  Node* head;
public:
  SinglyLinkedList (){
    this->head = NULL;
  };

  Node* get_new_node(int value){
    Node* new_node = new Node;
    new_node->data = value;
    return new_node;
  }

  void create_head(int value){
    this->head = get_new_node(value);
    this->head->next = NULL;
  }

  bool is_head_null(){
    if (this->head == NULL) {
      return true;
    }
    return false;
  }

  void insert_at_head(int value){
    if (is_head_null()) {
      create_head(value);
    }
    else{
      Node* append_head_node = get_new_node(value);
      append_head_node->next = this->head;
      this->head = append_head_node;
    }
  }

  void insert_at_tail(int value){
    if (is_head_null()) {
      create_head(value);
    }
    else{
      Node* traverser_node = this->head;
      while (traverser_node->next != NULL) {
        traverser_node = traverser_node->next;
      }
      traverser_node->next = get_new_node(value);
      traverser_node->next->next = NULL;
    }
  }

  void insert_at_position(int pos,int value){
  if (is_head_null()) {
    if (pos == 0) {
      create_head(value);
    }
    else{
      std::cout << "Empty list! Please specify in valid range" << '\n';
    }
  }
  else{
  int curr_list_size = get_list_size();
  if (pos == 0) {
    insert_at_head(value);
  }
  else if (pos > curr_list_size) {
    std::cout << "Index larger than list size." << '\n';
  }
  else{
    Node *traverser_node = this->head;
    while (pos-1 && traverser_node->next != NULL) {
      traverser_node = traverser_node->next;
      pos--;
    }
    Node* new_node_pos = get_new_node(value);
    new_node_pos->next = traverser_node->next;
    traverser_node->next = new_node_pos;
  }
  }
  }

  void remove_head_element(){
    if (is_head_null()) {
      std::cout << "List empty!" << '\n';
    }
    else{
      this->head = this->head->next;
    }
  }

  void remove_tail_element(){
    if (is_head_null()) {
      std::cout << "List empty!" << '\n';
    }
    else if (this->head->next == NULL) {
      this->head = NULL;
    }
    else{
      Node* traverser_node = this->head;
      while (traverser_node->next->next != NULL) {
        traverser_node = traverser_node->next;
      }
      traverser_node->next = NULL;
    }
  }

  int get_head_value(){
    if (is_head_null()) {
      return -1;
    }
    return this->head->data;
  }

  int get_tail_value(){
    if (is_head_null()) {
      return -1;
    }
    else{
      Node* traverser_node = this->head;
      while (traverser_node->next != NULL) {
        traverser_node = traverser_node->next;
      }
      return traverser_node->data;
    }
  }

  void find(int element){
    if (is_head_null()) {
      std::cout << "Empty list!" << '\n';
      return;
    }
    else{
      Node* traverser_node = this->head;
      while (traverser_node != NULL) {
        if (traverser_node->data == element) {
          std::cout << '\n' << "Found!";
          return;
        }
        traverser_node = traverser_node->next;
      }
      std::cout << '\n' << "Not found!";
    }
  }

  void erase(int element){
    if (is_list_empty()) {
      std::cout << "List empty!" << '\n';
      return;
    }
    Node* traverse_node = head;
    Node* prev;
    while (traverse_node != NULL && traverse_node->data != element) {
      prev = traverse_node;
      traverse_node = traverse_node->next;
    }
    if (traverse_node == NULL) {
      std::cout << "Not found!" << '\n';
      return;
    }
    else if (traverse_node == head) {
      remove_head_element();
      return;
    }
    else{
      prev->next = traverse_node->next;
    }
  }

  void print_list(){
    if (is_head_null()) {
      std::cout << "Empty list!" << '\n';
    }
    else{
      Node* traverser_node = this->head;
      while (traverser_node != NULL) {
        std::cout << traverser_node->data << ' ';
        traverser_node = traverser_node->next;
      }
    }
  }

  bool empty(){
    if (is_head_null()) {
      return true;
    }
    return false;
  }

  int size(){
    if (is_head_null()) {
      return -1;
    }
    Node* traverser_node = this->head;
    int size = 0;
    while (traverser_node!=NULL) {
      size++;
      traverser_node = traverser_node->next;
    }
    return size;
  }
};

int main(int argc, char const *argv[]) {
  SinglyLinkedList sll_obj = SinglyLinkedList();
  sll_obj.insert_at_tail(10);
  sll_obj.insert_at_tail(20);
  sll_obj.insert_at_tail(30);
  sll_obj.print_list();
  std::cout << '\n';
  return 0;
}
