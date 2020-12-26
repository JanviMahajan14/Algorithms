#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *arb;

    node(int d)
    {
        data = d;
        next = NULL;
        arb = NULL;
    }
};

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

node *mid_point(node *head)
{
    if (head == NULL || head->arb == NULL)
    {
        return head;
    }

    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->arb != NULL)
    {
        fast = fast->arb->arb; // CHANGE TO ARB
        slow = slow->arb;
    }

    return slow;
}

// CODE STARTS FROM HERE

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->arb = merge(a->arb, b); // CHANGE TO ARB
    }
    else
    {
        c = b;
        c->arb = merge(a, b->arb); // CHANGE TO ARB
    }

    return c;
}

node *merge_sort(node *head)
{
    if (head == NULL || head->arb == NULL)
    {
        return head;
    }

    node *mid = mid_point(head);
    node *a = head;
    node *b = mid->arb; // CHANGE TO ARB
    mid->arb = NULL;    // CHANGE HERE

    node *aa = merge_sort(a);
    node *bb = merge_sort(b);
    node *c = merge(aa, bb);
    return c;
}

void arb_to_next_higher(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        temp->arb = temp->next; // Copy next pointer to arb
        temp = temp->next;
    }

    head = merge_sort(head);

    cout << head->arb->data << "\n";
    head = head->next;
    cout << head->arb->data << "\n";
    head = head->next;
    cout << head->arb->data << "\n";
    head = head->next;
    cout << head->arb->data << "\n";
    head = head->next;
    cout << head->arb ? head->arb->data : -1;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 22);
    insertAtTail(head, 5);
    insertAtTail(head, 3);
    insertAtTail(head, 15);
    insertAtTail(head, 37);
    arb_to_next_higher(head);
}