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

node *mid_point(node *head)
{
    if (head == NULL)
    {
        return head;
    }

    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
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

node *merge(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Breaking into two linked list
    node *mid = mid_point(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    a = merge(a);
    b = merge(b);

    node *c = merge_sorted_ll(a, b);
    return c; //returns the head pointer of sorted linked list
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
    insertAtTail(head1, 1);
    insertAtTail(head1, 8);
    insertAtTail(head1, 4);
    insertAtTail(head1, 0);
    print(head1);
    cout << endl;
    head1 = merge(head1);
    print(head1);
}