//Single Linked List Inserting , Traversing, Deletion
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
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<" memory is free for node with data "<< value <<endl;
    }
};


void insertAtHead(Node* &head, Node* &tail, int data){
    if(head==NULL){ 
        Node* newNode = new Node(data);
        head=newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }
}
void insertAtTail(Node* &tail, Node* &head, int data){
    if(tail==NULL){
        Node* newNode = new Node(data);
        head=newNode;
        tail = newNode;
    }else{
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = temp;
    }
}
void insertAtMiddle(int position,int data, Node* &head, Node* &tail){

    // insert at First
    if (position == 1){
        insertAtHead(head, tail, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }

    // insert at Last
    if(temp -> next == NULL){
        insertAtTail(tail, head, data);
        return ;
    }

    Node* insertNode = new Node(data);
    Node* store = temp->next; 
    temp->next = insertNode;
    insertNode->next = store;
}

void deleteNode(int position, Node* &head, Node* &tail){
    if (position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int count = 1;
    Node* prev = NULL;
    Node* curr = head;
    while(count< position){
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    if (prev->next == NULL){
        tail = prev;
    }
}
void printNode(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< " " <<temp -> data << " ";
        temp = temp -> next;
    }
    cout<< endl;
}
int getLength(Node* &head){
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    // Insert At First
    // insertAtHead(head, tail, 15);
    // printNode(head);
    // insertAtHead(head, tail, 20);
    // printNode(head);
    // insertAtHead(head, tail, 25);
    // printNode(head);
    // cout<<"Length of Linked List : "<<getLength(head)<<endl;
    // cout<< "First Element : "<< head ->data << endl;
    // cout<< "Last Element : "<< tail ->data << endl;

    // Insert At Last
    insertAtTail(tail, head, 15);
    printNode(head);
    insertAtTail(tail, head, 20);
    printNode(head);
    insertAtTail(tail, head, 25);
    printNode(head);
    cout<<"Length of Linked List : "<<getLength(head)<<endl;
    cout<< "First Element : "<< head ->data << endl;
    cout<< "Last Element : "<< tail ->data << endl;


    // Insert At Middle
    insertAtMiddle(4, 30, head, tail);
    printNode(head);
    insertAtMiddle(1, 10, head, tail);
    printNode(head);
    insertAtMiddle(3, 19, head, tail);
    printNode(head);
    cout<<"Length of Linked List : "<<getLength(head)<<endl;
    cout<< "First Element : "<< head ->data << endl;
    cout<< "Last Element : "<< tail ->data << endl;

    deleteNode(4, head, tail);
    printNode(head);
    // deleteNode(3, head, tail);
    // printNode(head);
    // deleteNode(2, head, tail);
    // printNode(head);
    // deleteNode(1, head, tail);
    // printNode(head);
    cout<<"Length of Linked List : "<<getLength(head)<<endl;
    cout<< "First Element : "<< head ->data << endl;
    cout<< "Last Element : "<< tail ->data << endl;
    return 0;

}
