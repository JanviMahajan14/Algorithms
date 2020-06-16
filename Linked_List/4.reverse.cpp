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

void reverse(node *&head)
{
    node *prev = NULL;
    node *last = NULL;
    while (head != NULL)
    {
        prev = head;
        head = head->next;
        prev->next = last; //last is prev to prev
        last = prev;
    }
    head = last;
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
    node *prev = NULL;
    reverse(head);
    recursive_reverse(head);
    print(head);
}