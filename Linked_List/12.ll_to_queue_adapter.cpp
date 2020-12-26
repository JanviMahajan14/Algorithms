// LL to queue adapter
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
private:
    Node *head;
    Node *tail;

    void insertAtTail(Node *&head, Node *&tail, int d)
    {
        if (head == NULL)
        {
            head = new Node(d);
            tail = head;
            return;
        }

        Node *n = new Node(d);
        tail->next = n;
        tail = tail->next;
    }

    void deleteAtHead(Node *&head)
    {
        if (head == NULL)
            return;

        Node *n = head;
        head = head->next;
        delete n;
    }

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int d)
    {
        insertAtTail(head, tail, d);
    }
    void pop()
    {
        deleteAtHead(head);
    }
    int top()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Queue q;
    q.push(1);
    cout << q.top() << "\n";
    q.push(2);
    q.pop();
    q.pop();
    cout << q.top() << "\n";
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";
}