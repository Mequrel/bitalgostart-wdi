#include <iostream>
using namespace std;

class Node {
  public:
    int value;
    Node* next;
    
    Node(int val, Node* n) {
      value = val;
      next = n;
    }  
};

void removeElement(Node* head, int elem) {
  
  Node* to_del = nullptr;
  
  if(head == nullptr) return;
  
  while(head->next != nullptr) {
    if(head->next->value == elem) {
    
      to_del = head->next;
      head->next = head->next->next;
      delete to_del;
      
    }    
  }
  
}

Node* removeDuplicates(Node* head) {
  
  Node* h = head;
  while(h != nullptr) {
    removeElement(h, h->value);
    h = h->next;
  }
  
  return head;
}

int main() {}
