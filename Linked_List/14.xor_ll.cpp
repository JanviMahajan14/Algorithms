#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *npx;

    Node(int d)
    {
        data = d;
        npx = NULL;
    }
};

Node *XOR(Node *prev, Node *next)
{
    return (Node *)((uintptr_t)(prev) ^ (uintptr_t)(next));
}

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *n = new Node(data);
        head = n;
        return;
    }

    Node *n = new Node(data);
    n->npx = XOR(NULL, head);      //xor of prev and next
    head->npx = XOR(n, head->npx); //xor of prev and next
    head = n;
}

//Find pair for given sum in a sorted singly linked without extra space
int get_target(Node *head, Node *tail, int target)
{
    int cnt = 0;
    Node *prev = NULL;
    Node *next = NULL;

    while (head != NULL && tail != NULL && head != tail && head != next) //last cond vvvimp in case head and tail cross each other
    {
        if (head->data + tail->data == target)
        {
            Node *curr = head;
            Node *curr_tail = tail;
            head = XOR(head->npx, prev);
            tail = XOR(tail->npx, next);
            prev = curr;
            next = curr_tail;
            cnt++;
        }

        else if (head->data + tail->data > target)
        {
            Node *curr_tail = tail;
            tail = XOR(tail->npx, next);
            next = curr_tail;
        }

        else
        {
            Node *curr = head;
            head = XOR(head->npx, prev);
            prev = curr;
        }
    }

    return cnt;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 11);
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 3);
    Node *old_head = head;

    //printing the linked list forward;
    Node *prev = NULL;
    Node *curr = NULL;
    while (head != NULL)
    {
        cout << head->data << " ";
        curr = head;
        head = XOR(prev, head->npx);
        prev = curr;
    }
    cout << "\n";

    //printing the list in backward direction
    Node *tail = prev; // to know about tail for next qs
    Node *next = NULL;
    while (prev != NULL)
    {
        cout << prev->data << " ";
        curr = prev;
        prev = XOR(prev->npx, next);
        next = curr;
    }

    //Find pair for given sum in a sorted singly linked without extra space
    head = old_head;
    cout << "\n"
         << get_target(head, tail, 17);
}