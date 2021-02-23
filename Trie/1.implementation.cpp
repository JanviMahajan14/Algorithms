#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insertion(string word)
    {
        Node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            if (temp->children.count(word[i]))
            {
                temp = temp->children[word[i]];
            }
            else
            {
                Node *n = new Node(word[i]);
                temp->children[word[i]] = n;
                temp = n;
            }
        }

        temp->terminal = true; //mark last node as terminal
    }

    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            if (!temp->children.count(word[i]))
            {
                return false;
            }

            temp = temp->children[word[i]];
        }

        return temp->terminal; //return true only if temp is at terminal node
    }
};

int main()
{
    Trie t;
    vector<string> v = {"no",
                        "not",
                        "app",
                        "apple",
                        "news"};

    for (int i = 0; i < v.size(); i++)
    {
        t.insertion(v[i]);
    }

    string in;
    cin >> in;

    cout << t.search(in);
}