// Given a running stream of char.
#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *prev;

    Node(char d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insert(Node *&head, Node *&tail, char ch)
{
    if (head == NULL)
    {
        Node *n = new Node(ch);
        head = n;
        tail = n;
        return;
    }

    Node *n = new Node(ch);
    n->prev = tail;
    tail->next = n;
    tail = n;
}

void del(Node *&head, Node *&tail, char ch, unordered_map<char, Node *> &m)
{
    if (m[ch] == head)
    {
        Node *n = head;
        head = head->next;
        m[ch] = NULL;
        delete n;
        return;
    }

    else if (m[ch] == tail)
    {
        Node *n = tail;
        tail = tail->prev;
        tail->next->prev = NULL;
        tail->next = NULL;
        m[ch] = NULL;
        delete n;
        return;
    }

    Node *n = m[ch];
    n->prev->next = n->next;
    n->next->prev = n->prev;
    n->next = NULL;
    n->prev = NULL;
    m[ch] = NULL;
    delete n;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = NULL;
        Node *tail = NULL;
        unordered_map<char, Node *> m;
        while (n--)
        {
            char ch;
            cin >> ch;
            if (!m.count(ch))
            {
                insert(head, tail, ch);
                m[ch] = tail; // Inserting in hashmap
                cout << head->data << " ";
            }
            else if (m[ch] != NULL)
            {

                del(head, tail, ch, m);
                head == NULL ? cout << -1 << " " : cout << head->data << " ";
            }
            else
            {
                head == NULL ? cout << -1 << " " : cout << head->data << " ";
            }
        }
        cout << endl;
    }
}