#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node * prev;
    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList{
    Node * head;
    Node * tail;
    int size = 0;
    public:
    DoublyList(){
        head = NULL;
        tail = NULL;
    }
    void insertAtBeg(int value){
        Node * temp = new Node(value);
        if(head == NULL) {
            head = tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtEnd(int value){
        Node * temp = new Node(value);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void display(){
        Node * temp = head;
        while(temp!= NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }
};

int main(){
    DoublyList dll;
    dll.insertAtBeg(10);
    dll.insertAtBeg(20);
    dll.insertAtBeg(30);
    dll.display();
    return 0;
}