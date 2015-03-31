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

int howManyElemInNumBase(int num, int elem, int base) {
  int counter = 0;
  while(num > 0) {
    if ((num % base) == elem) counter++;
    num /= base;    
  }
  return counter;  
}

bool is8odd5(int n) {
  return howManyElemInNumBase(n, 5, 8) % 2 == 1;
}

Node* moveFront8odd5(Node* head) {
  
  if (head == nullptr) return head;
  
  Node* h = head;
  Node* newbegin;
  
  while(h->next != nullptr) {
    
    if(is8odd5(h->next->value)) {
      
      newbegin = h->next;
      h->next = h->next->next;
      newbegin->next = head;
      head = newbegin;
      
    }
    h = h->next;
  
  }
  return head;
  
}

int main() {

  return 0;
}
