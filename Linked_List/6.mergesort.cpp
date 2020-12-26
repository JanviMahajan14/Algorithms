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

    node *fast = head->next;
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

    // Doubt here
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

node *recursive_reverse(node *head)
{
    // Either we have no node or we want to iterate
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    node *temp = recursive_reverse(head->next);
    node *prev = head;
    prev->next->next = prev;
    prev->next = NULL;
    return temp;
}

bool isTriplet(node *a, node *b, node *c, int target)
{
    b = merge(a);
    c = merge(c);
    c = recursive_reverse(c); // Sort in des order

    node *headb = b;
    node *headc = c;

    while (a != NULL)
    {
        int val = target - a->data;
        while (b != NULL && c != NULL)
        {
            if (b->data + c->data == val)
            {
                return true;
            }
            else if (b->data + c->data < val)
            {
                b = b->next;
            }
            else
            {
                c = c->next;
            }
        }

        b = headb;
        c = headc;
        a = a->next;
    }
    return false;
}

void reverse(node *&head)
{
    node *prev = NULL;
    node *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next; //if we first break the link and then iterate will not work
        temp->next = prev;
        prev = temp;
    }
    head = prev;
}

// Delete nodes which have a greater value on right side----IMP+
node *del_right(node *head)
{
    reverse(head); //Reverse the current ll

    node *prev = head;
    node *curr = head->next;

    // Make sure it's in increasing order
    while (curr != NULL)
    {
        if (prev->data > curr->data)
        {
            node *temp = curr;
            prev->next = curr->next;
            curr->next = NULL;
            delete temp;
            curr = prev->next;
        }
        else
        {
            // max_so_far = max(max_so_far, curr->data);
            prev = prev->next;
            curr = curr->next;
        }
    }
    reverse(head);
    return head;
}

node *recursive_right(node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    node *curr = recursive_reverse(head->next);
    node *prev = head;
    if (prev->data < curr->data)
    {
        node *temp = curr;
        prev->data = curr->data;
        prev->next = curr->next;
        curr->next = NULL;
        delete temp;
    }
    return prev;
}

int main()
{
    node *head = NULL;
    // insertAtTail(head1, 2);
    // insertAtTail(head1, 1);
    // insertAtTail(head1, 8);
    // insertAtTail(head1, 4);
    // insertAtTail(head1, 0);
    // print(head1);
    // cout << endl;
    // head1 = merge(head1);
    // print(head1);

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);

    head = del_right(head);
    print(head);
}