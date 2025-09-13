#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{
    Node * head;
    Node * tail;
    int size = 0;
    public:
    LinkedList(){
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

    int getSize(){
        return size;
    }

    void delAtBeg(){
        if(head == NULL){
            cout<<"LinkedList is empty";
            return;
        }
        else{
            Node * temp = head;
            head = head->next;
            delete(temp);
            size--;
        }
    }

    void delAtEnd(){
        if(tail == NULL){
            "LinkedList is empty";
            return;
        }
        else{
            Node *temp = tail;
            if(head == tail) {
                head = NULL;
                tail = NULL;
            }
            else{
                Node *curr = head;
                while(curr->next != tail){
                    curr = curr->next;
                }
                curr->next = NULL;
                tail = curr;
            }
            delete(temp);
            size--;
        }
    }

    void delAtPos(int pos){
        int count = 0;
        if(head == NULL){
            cout<<"LL is empty";
            return;
        }
        else if(head == tail){
            Node *temp = NULL;
            delete(head);
            head = NULL;
            size--;
        }
        else if(pos == 1){
            delAtBeg();
            return;
        }
        else{
            Node *temp = head;
            while(count != pos-2){
                temp = temp->next;
                count++;
            }
            Node *deleteNode;
            deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete(deleteNode);
            size--;
        }
    }

    Node *revList(Node *curr){
        // Node *curr = head;
        Node *prev = NULL;
        tail = head;
        while(curr != NULL){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }

    Node *findMidNode(){
        Node * fast = head;
        Node * slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *MidNodeCount(){
        Node * temp;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        count = count/2;

        temp = head;
        int i = 0;
        while(i != count){
            temp = temp->next;
            i++;
        }
        return temp;
    }

    bool isPalin(){
        Node *mid = findMidNode();
        Node *curr = mid->next;

        mid->next = revList(curr);

        Node * curr1 = head;
        curr = mid->next;

        while(curr && curr1->next != mid){
            if(curr->data != curr1->data) return false;
            curr = curr->next;
            curr1 = curr1->next;
        }

        return true;
    }

    int GetNth(Node *head, int index){
        Node *curr = head;
        int count = 1;
        
        while(curr != NULL){
            if(count == index) return curr->data;
            count++;
            curr = curr->next;
        }
        return -1;
    }

};

int main(){

    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(10);
    // cout<<list.getSize()<<endl;
    // list.delAtPos(2);
    // list.display();
    list.display();
    // list.revList();
    cout<< list.isPalin();
    // list.display();
}