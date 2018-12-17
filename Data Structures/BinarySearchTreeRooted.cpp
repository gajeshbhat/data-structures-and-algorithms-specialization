#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;
struct node{
  long int data;
  struct node *left;
  struct node *right;
};

class Rooted_Tree {
private:
struct node *root; // Base Root Pointer
public:
  Rooted_Tree (){
    root = NULL;
  };

  struct node *CreateNode(long int value){ //Module returns a newly created Node address
    struct node *newnode = new struct node;
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
  }

  void insertNode(long int val){    //Inserts node into tree iterartively.
    if (root == NULL) {
      root=CreateNode(val);
    }
    else{
      struct node *traversePtr=root;
      while (traversePtr!=NULL) {
        if (val > traversePtr->data && traversePtr->right==NULL) {
          traversePtr->right=CreateNode(val);
          break;
        }
        else if (val < traversePtr->data && traversePtr->left==NULL){
          traversePtr->left=CreateNode(val);
          break;
        }
        else if(val > traversePtr->data){
          traversePtr=traversePtr->right; //Traverse Right
        }
        else if ( val < traversePtr->data){
          traversePtr=traversePtr->left; //Traverse left
        }
        else{
          //Equal value ignore
          break;
        }
      }
    }
  }
  void preorderTraversalIterative(){
    std::stack<struct node*>s;
    struct node *preorderroot = root;

    if(root == NULL) return;
    s.push(preorderroot);
    while(!s.empty()){
        struct node *vis = s.top();
        s.pop();
        std::cout << vis -> data <<" ";
        if(vis->right)
           s.push(vis->right);
        if(vis->left)
           s.push(vis->left);
    }
}

void inOrderTraversalIterative() {
  stack<struct node*> s;
  struct node *current = root;
  while (!s.empty() || current) {
    if (current) {
      s.push(current);
      current = current->left;
    } else {
      current = s.top();
      s.pop();
      cout << current->data << " ";
      current = current->right;
    }
  }
}
void postOrderTraversalIterative() {
  struct node *postroot = root;
  if (!postroot) return;
  stack<struct node*> s;
  s.push(postroot);
  struct node *prev = NULL;
  while (!s.empty()) {
    struct node *curr = s.top();
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left)
        s.push(curr->left);
      else if (curr->right)
        s.push(curr->right);
    } else if (curr->left == prev) {
      if (curr->right)
        s.push(curr->right);
    } else {
      cout << curr->data << " ";
      s.pop();
    }
    prev = curr;
  }
}

};

int main(int argc, char const *argv[]) {
    Rooted_Tree treeobj;
    /*
    Methods Used are..
    1.insertNode
    2.CreateNode (returns a tree node address with left and right set to NULL)
    3.inOrderTraversalIterative
    4.preorderTraversalIterative
    5.postOrderTraversalIterative

    * preorder and Post order might need some more work.
    *Inorder and insertNode have been Optimized the most.

    *Raise an issue in github if you dound the fix or better way to do it.

    *Cost of avoiding recursion in this case is ending up with code that can easily brainfuck you! (Not worth the time unless Production)
    */
  return 0;
}
