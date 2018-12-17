
// Cut the Singly Linked List into half and join the first half to second half.

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
Node *CutTheList(Node *head){
  int sizeList=0;       // Contains the size of the List
  Node *tracker=head;   // temprory tracker

  while(tracker!=NULL){sizeList++;tracker=tracker->next;} // Counts the Size of the List
  tracker=head;

  while(tracker->next!=NULL){tracker=tracker->next;}tracker->next=head; // Assigns the head to tail.

  int sizehalf=sizeList/2; //Size of the halved List.
  tracker=head;
  while(--sizehalf){tracker=tracker->next;}head=tracker->next;tracker->next=NULL;

  return head;
}

int main(int argc, char const *argv[]) {
  Insert(10);
  Insert(20);
  Insert(30);
  Insert(40);
  display(head);
  cout<<endl;
  display(CutTheList(head));
  return 0;
}
