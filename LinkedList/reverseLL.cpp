#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

Node *reverseLinkedList2(Node *&head)
{
    // Base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallHead = reverseLinkedList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void reverseLinkedList(Node *&head, Node *curr, Node *prev)
{
    // Base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    reverseLinkedList(head, curr->next, curr);
    curr->next = prev;
}

void insertAtTail(Node *&tail, Node *&head, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}
void printNode(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *tail = NULL;
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 50);
    insertAtTail(tail, head, 60);
    printNode(head);
    // Loop Method
    // Node* newHead = reverseLL(head);

    // Recursive Method
    // reverseLinkedList(head, head, NULL);
    // printNode(head);
    Node *newhead = reverseLinkedList2(head);
    printNode(newhead);
    return 0;
}