#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);


    Node* current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}