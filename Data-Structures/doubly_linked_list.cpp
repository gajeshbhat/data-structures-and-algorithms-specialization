#include <iostream>

using namespace std;

struct Node{
int data;
Node* next;
Node* prev;
};

class DoublyLinkedList {
private:
  Node* head;
  Node* tail;
public:
  DoublyLinkedList (){
    head = tail = NULL;
  };
  Node* get_new_node(int value){
    Node* new_node = new Node;
    new_node->data = value;
    return new_node;
  }

  bool is_list_empty(){
    if (this->head == NULL) {
      return true;
    }
    return false;
  }

  int get_head_element(){
    if (is_list_empty()) {
      return -1;
    }
    return this->head->data;
  }

  int get_tail_element(){
    if (is_list_empty()) {
      return -1;
    }
    return this->tail->data;
  }

  void create_head(int value){
    head = get_new_node(value);
    tail = head;
    head->next = head->prev = tail->next = tail->prev = NULL;
  }

  void insert_at_head(int value){
    if (is_list_empty()) {
      create_head(value);
    }
    else{
      Node* new_head_node = get_new_node(value);
      new_head_node->next = head;
      head->prev = new_head_node;
      head = new_head_node;
    }
  }

  void insert_at_tail(int value){
    if (is_list_empty()) {
      create_head(value);
    }
    else{
      Node* new_head_node = get_new_node(value);
      new_head_node->prev = tail;
      new_head_node->next = NULL;
      tail->next = new_head_node;
      tail = new_head_node;
    }
  }

  void insert_at_position(int pos,int value){
    if (is_list_empty()) {
      if (pos == 0) {
        insert_at_head(value);
      }
      else{
        std::cout << "Index out of range!" << '\n';
      }
      return;
    }

    int list_size = size();
    if (pos > list_size) {
      std::cout << "Index out of range!" << '\n';
    }
    else if (pos == 0) {
      insert_at_head(value);
    }
    else if (pos == list_size) {
      insert_at_tail(value);
    }
    else{
      Node* traverse_node = head;
      while (traverse_node!=NULL && pos-1 > 0) {
        pos--;
        traverse_node = traverse_node->next;
      }
      Node* node_at_pos = get_new_node(value);
      node_at_pos->prev = traverse_node;
      node_at_pos->next = traverse_node->next;
      traverse_node->next->prev = node_at_pos;
      traverse_node->next = node_at_pos;
    }
  }

  void remove_from_head(){
    if (is_list_empty()) {
      std::cout << "Empty list!";
      return;
    }
    else if (head->next == NULL) {
      head = tail = NULL;
      return;
    }
    head->next->prev = NULL;
    head = head->next;
  }

  void remove_from_tail(){
    if (is_list_empty()) {
      std::cout << "Empty list!";
      return;
    }
    else if (tail == head) {
      head = tail = NULL;
      return;
    }
    tail->prev->next = NULL;
    tail = tail->prev;
  }

  void erase(int element){
    if (is_list_empty()) {
      std::cout << "List empty!" << '\n';
      return;
    }
    Node* traverse_node = head;
    while (traverse_node != NULL && traverse_node->data != element) {
      traverse_node = traverse_node->next;
    }
    if (traverse_node == NULL) {
      std::cout << "Not found!" << '\n';
      return;
    }
    else if (traverse_node == head) {
      remove_from_head();
      return;
    }
    else if (traverse_node == tail) {
      remove_from_tail();
      return;
    }
    traverse_node->prev->next = traverse_node->next;
    traverse_node->next->prev = traverse_node->prev;
    traverse_node = NULL;
    delete traverse_node;
  }

  int find(int element){
    if (is_list_empty()) {
      std::cout << "List Empty!" << '\n';
      return -1;
    }
    Node* traverse_node = head;
    while (traverse_node != NULL && traverse_node->data != element) {
      traverse_node = traverse_node->next;
    }
    if (traverse_node == NULL) {
      std::cout << "Not found!" << '\n';
      return -1;
    }
    return traverse_node->data;
  }

  int size(){
    if (is_list_empty()) {
      std::cout << "Empty list!" << '\n';
      return -1;
    }
    int size_counter = 0;
    Node* traverse_node = head;
    while (traverse_node!=NULL) {
      size_counter++;
      traverse_node = traverse_node->next;
    }
    return size_counter;
  }

  void print_list(){
    if (is_list_empty()) {
      std::cout << "List empty!" << '\n';
    }
    Node* traverse_node = head;
    while (traverse_node!=NULL) {
      std::cout << traverse_node->data << ' ';
      traverse_node = traverse_node->next;
    }
  }

  void reverse_print_list(){
    if (is_list_empty()) {
      std::cout << "List empty!" << '\n';
    }
    Node* traverse_node = tail;
    while (traverse_node!=NULL) {
      std::cout << traverse_node->data << ' ';
      traverse_node = traverse_node->prev;
    }
  }
};

int main(int argc, char const *argv[]) {
  DoublyLinkedList db_obj = DoublyLinkedList();
  db_obj.insert_at_head(10);
  db_obj.insert_at_head(20);
  db_obj.insert_at_tail(30);
  db_obj.print_list();
  std::cout << '\n';
  db_obj.reverse_print_list();
  std::cout << '\n';
  return 0;
}
