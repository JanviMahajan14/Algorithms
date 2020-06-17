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
    }
};

void insertAtHead(node *&head, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    n->next = head;
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    head = n;
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
}

void deleteNode(node *&head, int p)
{
    if (p == 0)
    {
        return deleteAtHead(head);
    }
    node *temp = head;
    node *prev = NULL;
    int index = 0;
    while (temp->next != head && index < p)
    {
        prev = temp;
        temp = temp->next;
        index++;
    }

    prev->next = temp->next;
    temp->next = NULL;
}

void print(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 8);
    deleteNode(head, 2);
    deleteNode(head, 0);
    deleteNode(head, 3);
    print(head);
}