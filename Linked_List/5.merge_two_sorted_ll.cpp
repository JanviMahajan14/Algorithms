#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

node *merge_sorted_ll(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge_sorted_ll(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge_sorted_ll(a, b->next);
    }
    return c;
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        node *n = new node(data);
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *n = new node(data);
    temp->next = n;
    return;
}

int main()
{
    node *head1 = NULL;
    insertAtTail(head1, 2);
    insertAtTail(head1, 4);
    insertAtTail(head1, 7);
    insertAtTail(head1, 9);
    insertAtTail(head1, 10);
    print(head1);
    cout << endl;
    node *head2 = NULL;
    insertAtTail(head2, 1);
    insertAtTail(head2, 3);
    insertAtTail(head2, 8);
    insertAtTail(head2, 19);
    print(head2);
    cout << endl;
    node *c = merge_sorted_ll(head1, head2);
    print(c);
}