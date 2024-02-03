#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<< "Memory free for value "<<value<<endl;
    }
    
};

void insertNode(int d, int element, Node* &tail){

    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        newNode -> next = newNode;
        tail = newNode;
    }else{
        // assuming that the element is present in List
        Node* curr = tail;
        while (curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(int element, Node* &tail){
    if(tail==NULL){
        cout<<"List is empty, please check again"<<endl;
    }else{
        // assuming that the element is present in List
        Node* prev = tail;
        Node* curr = tail->next;
        while (curr->data != element){
            prev = curr;
            curr = curr->next;
        }

        // handle if 1 Node in List
        if (curr==prev){
            tail = NULL;
        }
        // handle if tail element will be delete
        if(curr == tail){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void printNode(Node* tail){
    if (tail == NULL){
        cout<<"List is empty, please check again"<<endl;
        return;
    }
    Node* temp = tail;
    do{
        cout<<" " << temp->data << " ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}
int main(){
    Node* tail = NULL;
    // Inserting
    insertNode(10, 20, tail);
    printNode(tail);
    // insertNode(20, 10, tail);
    // printNode(tail);
    // insertNode(30, 20, tail);
    // printNode(tail);
    // insertNode(40, 30, tail);
    // printNode(tail);
    // insertNode(100, 20, tail);
    // printNode(tail);

    // Deleting
    deleteNode(10, tail);
    printNode(tail);
    // deleteNode(30, tail);
    // printNode(tail);


    return 0;
}