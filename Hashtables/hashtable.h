#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string k, T val)
    {
        key = k;
        value = val;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next; //will delete the whole remaining list recursively
        }
    }
};

template <typename T>
class Hashmap
{
    Node<T> **table; //Pointer to the array of pointer
    int curr_size;
    int total_size;

    int hashfn(string key)
    {
        int res = 0;
        int p = 1;
        for (int i = 0; i < key.length(); i++)
        {
            res = res + (key[i] * p) % total_size;
            res = res % total_size;
            p = (p * 27) % total_size; //otherwise overflow
        }
        return res;
    }

    void rehash()
    {
        int old_table_size = total_size;
        total_size = 2 * total_size; //we can also find next nearest ts
        Node<T> **old_table = new Node<T> *[total_size];
        curr_size = 0; //it's very imp because now we have to insert all elements again

        for (int i = 0; i < old_table_size; i++)
        {
            old_table[i] = table[i];
        }

        for (int i = 0; i < total_size; i++)
        {
            table[i] = NULL;
        }

        for (int i = 0; i < old_table_size; i++)
        {
            Node<T> *temp = old_table[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
        }

        delete[] old_table;
    }

public:
    Hashmap(int ts = 7)
    {
        total_size = ts;
        curr_size = 0;
        table = new Node<T> *[total_size];

        for (int i = 0; i < total_size; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        int idx = hashfn(key);
        Node<T> *n = new Node<T>(key, value); //inserts new node at head of LinkedList
        n->next = table[idx];
        table[idx] = n;
        curr_size++;

        float load_factor = (float)curr_size / total_size;
        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    void print()
    {
        for (int i = 0; i < total_size; i++)
        {
            cout << "index " << i << " ";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << ":" << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T *search(string key)
    {
        int idx = hashfn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }

        return NULL;
    }

    void erase(string key)
    {
        int idx = hashfn(key);
        Node<T> *temp = table[idx];
        Node<T> *prev = table[idx];

        if (temp->key == key)
        {
            table[idx] = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }

        while (temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }

    // Operator overloading with which we can perform insert,update,search
    T &operator[](string key)
    {
        T *f = search(key);
        if (f == NULL)
        {
            T garbage;
            insert(key, garbage);
            f = search(key);
        }

        return *f; //pass value by reference so it gets updated in main
    }
};