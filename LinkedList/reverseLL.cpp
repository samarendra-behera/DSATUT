#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next ;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

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
    return 0;
}