#include <iostream>  
using namespace std;

//Node structure for a doubly linked list
class Node {
public:
    int data;    
    Node* pre;  
    Node* next;  

    //Constructor to create a new node
    Node(int value) {
        data = value;
        pre = nullptr;
        next = nullptr;
    }
};

//Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head; 

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    //Function to insert a node at the beginning (head)
    void insertAtHead(int value) {
        Node* newNode = new Node(value);  
        if (head != nullptr) {
            newNode->next = head;  
            head->pre = newNode;
        }
        head = newNode;  
    }

    //unction to insert a node at the end (tail)
    void insertAtTail(int value) {
        Node* newNode = new Node(value);  
        if (head == nullptr) {  
            head = newNode;
            return;
        }
        Node* temp = head; 
        while (temp->next != nullptr) {  
            temp = temp->next;
        }
        temp->next = newNode;  
        newNode->pre = temp; 
    }

    //Function to print the list in forward direction
    void printForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {  //Traverse and print each node
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    //Function to print the list in backward direction
    void printBackward() {
        if (head == nullptr) return;  //If list is empty, do nothing

        Node* temp = head;
        while (temp->next != nullptr) {  //Go to the last node
            temp = temp->next;
        }

        cout << "Backward: ";
        while (temp != nullptr) {  //Traverse backward and print
            cout << temp->data << " ";
            temp = temp->pre;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;  //Create an empty list

    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);

    dll.printForward();   //Output: Forward
    dll.printBackward();  //Output: Backward

    return 0;  
}
