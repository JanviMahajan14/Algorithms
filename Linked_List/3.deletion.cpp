// Function snippet for performing deletion in linked_list
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
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
    node *temp = NULL;
    while (head->next != NULL)
    {
        temp = head; //one step behind head
        head = head->next;
    }
    delete head;
    temp->next = NULL;
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

int main()
{
    node *head = NULL;
    deleteAtHead(head);
    deleteAtEnd(head);
    deleteAtMid(head, 2);
}