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

bool floyd_cycle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (head != NULL && head->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

void breakcycle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (head != NULL && head->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    node *prev = NULL;
    while (fast != slow)
    {
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }
    prev->next = NULL;
}

int main()
{
    node *head = NULL;
    cout << floyd_cycle(head);
    breakcycle(head);
}