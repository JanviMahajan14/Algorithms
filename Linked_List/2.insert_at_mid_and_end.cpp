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

int len(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

void insertAtHead(node *&head, int data)
{
    node *n = new node(data);
    n->next = head;
    head = n;
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

void insertAtMid(node *&head, int data, int p)
{
    if ((head == NULL) || (p == 0))
    {
        return insertAtHead(head, data);
    }

    if (p >= len(head))
    { //position greater than len of linked list
        insertAtTail(head, data);
        return;
    }

    int index = 0;
    node *temp = head;
    while (index < (p - 1))
    {
        temp = temp->next;
        index++;
    }
    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
    return;
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtEnd(node *head)
{
    node *prev = NULL;
    while (head->next != NULL)
    {
        prev = head; //one step behind head
        head = head->next;
    }
    delete head;
    prev->next = NULL;
}

void deleteAtMid(node *&head, int p)
{
    if (p == 0 || head == NULL)
    {
        return deleteAtHead(head);
    }
    if (p >= (len(head) - 1))
    {
        return deleteAtEnd(head);
    }
    node *temp = head;
    node *prev = NULL;
    int index = 0;
    while (temp->next != NULL && index < p)
    {
        prev = temp;
        temp = temp->next;
        index++;
    }
    prev->next = temp->next;
    delete temp;
}

void iterative_search(node *head, int data)
{
    while (head != NULL)
    {
        if (head->data == data)
        {
            cout << true << endl;
            return;
        }
        head = head->next;
    }
    cout << false << endl;
}

void recursive_search(node *head, int data)
{
    if (head == NULL)
    {
        cout << false << endl;
        return;
    }
    else if (head->data == data)
    {
        cout << true << endl;
        return;
    }
    recursive_search(head->next, data);
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

// Very important
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

node *k_node_from_end(node *head, int k)
{
    node *fast = head;
    node *slow = head;
    // Move fast K steps ahead of slow
    while (k--)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtMid(head, 8, 2);
    insertAtMid(head, 10, 0);
    insertAtMid(head, 3, 4);
    insertAtTail(head, 2);
    // deleteAtHead(head);
    // deleteAtEnd(head);
    // deleteAtMid(head, 2);
    // iterative_search(head, 7);
    // iterative_search(head, 17);
    // recursive_search(head, 3);
    // recursive_search(head, 18);
    print(head);
    cout << endl;
    reverse(head);
    print(head);
    // head = recursive_reverse(head);
    // print(head);
    node *ans = mid_point(head);
    cout << ans->data;
    // node *n = k_node_from_end(head, 3);
    // cout << n->data << " ";
}