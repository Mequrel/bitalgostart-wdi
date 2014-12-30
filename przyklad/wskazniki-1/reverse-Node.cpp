/**
Zadanie 1/WskaŸniki: Odwróæ listê jednokierunkow¹.
Autor: Przemys³aw Jamrozowicz
Rozwi¹zanie wzorcowe.
Z³o¿onoœæ rozwi¹zania: O(n)
Opis rozwi¹zania:
    Rozwi¹zanie polega na przechowywaniu 3 kolejnych elementów listy, tzn.
    tego, który aktualnie "przepinamy", poprzedniego oraz nastêpnego.
    W ten sposób nie zgubimy ¿adnego elementu oraz jesteœmy w stanie obróciæ listê.
    Obracanie koñczymy kiedy dojdziemy do ostaniego elementu wskazuj¹cego na
    wskaŸnik zerowy.

    W przypadku kiedy do obrócenia dostaniemy listê jednoelementow¹
    od razu zwracamy otrzymany wskaŸnik.
    Pêtla while wykona siê n-1 razy (dla ka¿dego elementu listy,
    poczynaj¹c od drugiego, poniewa¿ pierwszy element przepinamy poza pêtl¹).
    Z³o¿onoœæ wynosi wiêc O(n).

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
