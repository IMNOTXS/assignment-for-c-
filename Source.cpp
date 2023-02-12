/* Saleh Abdulrahman 
ID: 201001980 
Date: 2/12/2023
*/

#include <iostream>
using namespace std;

//node class
class Node {
public:
    int data;
    Node* next;
    
    Node()
    {
        data = 0;
        next = NULL;
    }
    
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// the linked lists
class Linkedlist {
    Node* head, * tail;

public:
    Linkedlist() { head = NULL; tail = NULL; }
    
    void insertNode(int data)
    {
        
        Node* newNode = new Node(data);

        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    
    void insertNodeTail(int data)
    {
        
        Node* newNode = new Node(data);

        // Assign to tail
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    void printList()
    {
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // function to delete the node 
    void deleteNode()
    {
        if (head == NULL) {
            cout << "Linked List is already empty!" << endl;
            return;
        }
        else if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        else {
            Node* temp = head;
            while (temp->next != tail)
                temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
    }
};

int main()
{
    Linkedlist list;
    cout << "Inserting three nodes at the head." << endl;
    list.insertNode(30);
    list.insertNode(20);
    list.insertNode(10);
    list.printList();
    cout << "Inserting a node at the tail." << endl;
    list.insertNodeTail(40);
    list.printList();
    cout << "Deleting a node from the tail." << endl;
    list.deleteNode();
    list.printList();
}