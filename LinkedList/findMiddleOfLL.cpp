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

Node* findMiddleNode(Node* head){
    if (head==NULL){
        cout<< "List is Empty, please try again!"<<endl;
        return head;
    }
    int len = getLength(head);
    int midPos = len/2;
    Node* temp = head;
    while(midPos>0){
        temp = temp->next;
        midPos--;
    }
    return temp;
}

// Optimize Approach
Node* findMiddleNode2(Node* head){
    if (head==NULL){
        cout<< "List is Empty, please try again!"<<endl;
        return head;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next!=NULL){
        fast= fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 50);
    insertAtTail(tail, head, 60);
    printNode(head);

    // Node* mid = findMiddleNode(head);
    //Optimize approach
    Node* mid = findMiddleNode2(head);
    cout<< "Middle Node is "<< mid->data << endl; 
    return 0;
}