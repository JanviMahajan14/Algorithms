// Sort the biotonic list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *n = new Node(d);
        head = n;
        return;
    }

    Node *n = new Node(d);
    n->next = head;
    n->next->prev = n;
    head = n;
}

Node *get_biotonic(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != NULL && curr->data > prev->data)
    {
        curr = curr->next;
        prev = prev->next;
    }

    return curr;
}

Node *merge(Node *a, Node *b)
{
    if (b == NULL)
    {
        return a;
    }
    if (a == NULL)
    {
        return b;
    }

    Node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
        c->next->prev = c;
        c->prev = NULL; //vvvimp else prev of first node will never be null;
    }
    else
    {
        c = b;
        c->next = merge(a, b->prev);
        c->next->prev = c;
        c->prev = NULL; //vvvimp else prev of first node will never be null;
    }
    return c;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 4);
    insertAtHead(head, 6);
    insertAtHead(head, 10);
    insertAtHead(head, 12);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 2);

    Node *a = head;
    Node *b = get_biotonic(head);
    Node *res = NULL;

    if (b == NULL)
    {
        res = a;
    }
    else
    {
        Node *back = b->prev;
        back->next = NULL;
        b->prev = NULL;

        while (b->next != NULL)
        {
            b = b->next;
        }

        res = merge(a, b);
    }

    while (res->next != NULL)
    {
        res = res->next;
    }

    //Printing ll in opp direction
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->prev;
    }
}