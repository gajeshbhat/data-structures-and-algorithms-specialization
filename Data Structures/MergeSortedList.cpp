#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};
Node *head=NULL;

Node* CreateNode(int d){
  Node *newnode=new Node;
  newnode->next=NULL;
  newnode->data=d;
  return newnode;
}
void Insert(int value){
  if(head==NULL){
    head=CreateNode(value);
  }
  else{
    Node *temp=CreateNode(value);
    temp->next=head;
    head=temp;
  }
}
void display(Node *base){
  Node *i=base;
  while(i!=NULL){
    cout<<i->data<<" ";
    i=i->next;
  }
}
Node *MergeSorted(Node *head1,Node *head2){
  
}
int main(int argc, char const *argv[]) {
  Insert(10);
  Insert(20);
  Insert(30);
  Insert(40);
  display(head);
  cout<<endl;
  return 0;
}
