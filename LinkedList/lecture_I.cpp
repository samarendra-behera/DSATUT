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


void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}
void insertAtMiddle(int position,int data, Node* &head){
    if (position == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = new Node(data);
    int i = 1;
    Node* add = head;
    while(i<position-1){ 
        add = add->next;
        i++;
    }
    Node* store = add -> next;
    add ->next = temp;
    temp->next = store;

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

    Node* head = node1;
    Node* tail = node1;

    // Insert At Head
    // printNode(head);
    // insertAtHead(head, 15);
    // printNode(head);
    // insertAtHead(head, 20);
    // printNode(head);

    // Insert At Tail
    printNode(head);
    insertAtTail(tail, 15);
    printNode(head);
    insertAtTail(tail, 20);
    printNode(head);

    // Insert At Middle
    insertAtMiddle(5, 22, head);
    printNode(head);

    return 0;

}
