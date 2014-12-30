/**
Zadanie 1/Wska�niki: Odwr�� list� jednokierunkow�.
Autor: Przemys�aw Jamrozowicz
Rozwi�zanie wzorcowe.
Z�o�ono�� rozwi�zania: O(n)
Opis rozwi�zania:
    Rozwi�zanie polega na przechowywaniu 3 kolejnych element�w listy, tzn.
    tego, kt�ry aktualnie "przepinamy", poprzedniego oraz nast�pnego.
    W ten spos�b nie zgubimy �adnego elementu oraz jeste�my w stanie obr�ci� list�.
    Obracanie ko�czymy kiedy dojdziemy do ostaniego elementu wskazuj�cego na
    wska�nik zerowy.

    W przypadku kiedy do obr�cenia dostaniemy list� jednoelementow�
    od razu zwracamy otrzymany wska�nik.
    P�tla while wykona si� n-1 razy (dla ka�dego elementu listy,
    poczynaj�c od drugiego, poniewa� pierwszy element przepinamy poza p�tl�).
    Z�o�ono�� wynosi wi�c O(n).

**/


#include <iostream>

using namespace std;

struct Node{
    Node * next;
    int value;
};

Node* reverse_node(Node *head){

    if(head->next==nullptr)
        return head;

    Node *tmp = head;
    Node *tmp_next;

    head = head->next;
    tmp_next = head->next;
    head->next = tmp;
    tmp->next = nullptr;

    while(tmp_next!=nullptr){
        tmp=head;
        head=tmp_next;
        tmp_next = head->next;
        head->next=tmp;
    }

    return head;
}

int main()
{
    int n;
    cin>>n;

    struct Node *head = new Node;
    cin>>head->value;
    struct Node *head_tmp = head;

    for(int i=1;i<n;i++){
        head_tmp->next = new Node;
        head_tmp=head_tmp->next;
        cin>>head_tmp->value;
    }
    head_tmp->next=nullptr;

    head = reverse_node(head);
    head_tmp = head;
    while(head_tmp!=nullptr){
        cout<<head_tmp->value<<" ";
        head_tmp=head_tmp->next;
    }

    return 0;
}
