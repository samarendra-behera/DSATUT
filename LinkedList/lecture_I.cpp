#include<iostream>
using namespace std;
// Types of Linked list
// 1 . Singly Linked list
// 2 . Doubly Linked list
// 3 . Circular Linked list 

/*Singly Linked list*/

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void printNode(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< " " <<temp -> data << " ";
        temp = temp -> next;
    }
    cout<< endl;
}

int main(){
    Node* node1 = new Node(10);
    // cout<< node1 -> data << endl;
    // cout<< node1 -> next << endl;

    // Insert At Head
    Node* head = node1;
    printNode(head);
    insertAtHead(head, 15);
    printNode(head);
    insertAtHead(head, 20);
    printNode(head);



    return 0;

}
