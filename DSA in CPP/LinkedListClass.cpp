#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void insertAtBeg(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node *current = head;
        while(current != NULL){
            cout<< current->data<<"\t";
            current = current->next;
        }
    }
    void insertAtEnd(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertAtPos(int value, int pos) {
        Node* current = head;
        for(int i = 0; i < pos - 1; i++) {
            if(head == NULL) {
                cout << "Position out of bounds" << endl;
                return;
            }
            current = current->next;
        }
        if(current == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = current->next;
        current->next = newNode;
    }

};

int main() {
    LinkedList list;
    list.insertAtBeg(10);
    list.insertAtBeg(20);
    list.insertAtBeg(30);
    list.display();
}