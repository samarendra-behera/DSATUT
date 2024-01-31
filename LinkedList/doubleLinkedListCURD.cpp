#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
int getLength(Node* head){
    int len =0;
    Node* temp = head;
    while (temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
    
}
void printNode(Node* head){
    Node* temp = head;
    while (temp != NULL){
        cout<<" "<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}
void insertAtHead(Node* &head, Node* &tail, int data){
    Node* temp = head;

    // create a new node
    if (temp==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* insertNode = new Node(data);
        insertNode->next = temp;
        temp->prev = insertNode;
        head = insertNode;
    }
}
void insertAtLast(Node* &tail, Node* &head, int data){
    Node* temp = tail;
    if (tail==NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }else{
        Node* insertNode = new Node(data);
        temp->next = insertNode;
        insertNode->prev = temp;
        tail = insertNode;
    }
    
}
void insertAtMiddle(Node* &head, Node* &tail, int position, int data){
    // insert at first
    if(position==1){
        insertAtHead(head, tail, data);
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if(temp->next == NULL){
        insertAtLast(tail, head, data);
        return ;
    }
    Node* insertNode = new Node(data);
    insertNode->prev = temp;
    insertNode->next = temp->next;
    temp->next = insertNode;
    insertNode->next->prev = insertNode;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // insert at First 
    // insertAtHead(head, tail, 20);
    // printNode(head);
    // insertAtHead(head,tail, 30);
    // printNode(head);
    // insertAtHead(head,tail, 40);
    // printNode(head);
    // insertAtHead(head,tail, 50);
    // printNode(head);
    // cout<< "Length of Linked List : "<< getLength(head)<<endl;
    // cout<<"First Element : "<<head->data << endl;
    // cout<<"Last Element : "<<tail->data<<endl;

    // insert at Last 
    insertAtLast(tail, head,100);
    printNode(head);
    insertAtLast(tail, head,200);
    printNode(head);
    insertAtLast(tail, head,300);
    printNode(head);
    cout<< "Length of Linked List : "<< getLength(head)<<endl;
    cout<<"First Element : "<<head->data << endl;
    cout<<"Last Element : "<<tail->data<<endl;

    // // insert at position 
    insertAtMiddle(head, tail, 4, 400);
    printNode(head);
    cout<<"First Element : "<<head->data << endl;
    cout<<"Last Element : "<<tail->data<<endl;
    return 0;
}