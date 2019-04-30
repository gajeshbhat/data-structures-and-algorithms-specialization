#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;
};

class BinarySearchTree {
public:
  Node* root;

  BinarySearchTree(){
    root=NULL;
  }

  Node* get_root_node(){
    return root;
  }

  bool is_root_null(){
    return root == NULL;
  }

  Node* get_new_node(int value){
    Node* new_node = new Node;
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
  }

  void create_root(int value){
    root = get_new_node(value);
  }

  void insert(Node* root, int value){
    if (is_root_null()) {
      create_root(value);
    }
    else{
      if (value > root->data && root->right == NULL) {
        root->right = get_new_node(value);
      }
      else if (value < root->data && root->left == NULL) {
        root->left = get_new_node(value);
      }
      else if (value > root->data) {
        insert(root->right,value);
      }
      else{
        insert(root->left,value);
      }
    }
  }
  void inorder_traverse(Node* node){
    if (node == NULL) {
      return;
    }
    inorder_traverse(node->left);
    std::cout << node->data << ' ';
    inorder_traverse(node->right);
  }

  void inorder_traverse_revserse(Node* node){
    if (node == NULL) {
      return;
    }
    inorder_traverse_revserse(node->right);
    std::cout << node->data << ' ';
    inorder_traverse_revserse(node->left);
  }

  void preorder_traverse(Node* node){
    if (node == NULL) {
      return;
    }
    std::cout << node->data << ' ';
    inorder_traverse(node->left);
    inorder_traverse(node->right);
  }

  void postorder_traverse(Node* node){
    if (node == NULL) {
      return;
    }
    inorder_traverse(node->left);
    inorder_traverse(node->right);
    std::cout << node->data << ' ';
  }

};

int main(int argc, char const *argv[]) {
  BinarySearchTree test_bst = BinarySearchTree();
  test_bst.insert(test_bst.root,10);
  test_bst.insert(test_bst.root,-10);
  test_bst.insert(test_bst.root,20);
  test_bst.insert(test_bst.root,-20);
  test_bst.insert(test_bst.root,30);
  std::cout << "Inorder" << '\n';
  test_bst.inorder_traverse(test_bst.get_root_node());
  std::cout << '\n';
  std::cout << "Inorder Reversed" << '\n';
  test_bst.inorder_traverse_revserse(test_bst.get_root_node());
  std::cout << '\n';
  std::cout << "Preorder" << '\n';
  test_bst.preorder_traverse(test_bst.get_root_node());
  std::cout << '\n';
  std::cout << "Postorder" << '\n';
  test_bst.postorder_traverse(test_bst.get_root_node());
  std::cout << '\n';
  return 0;
}
