#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Accepts a old root node and returns a new root node
node *buildBst(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (data <= root->data)
    {
        root->left = buildBst(root->left, data);
    }

    if (data > root->data)
    {
        root->right = buildBst(root->right, data);
    }
    return root;
}

// Complexity is O(logn) because we are searching in one branch only
bool searchBst(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (data < root->data)
    {
        return searchBst(root->left, data);
    }
    else
    {
        return searchBst(root->right, data);
    }
}

node *deleteInBST(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        //if root has 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //if root has 1 child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        //if root has two children, we need to find potential replacement
        node *replacement = root->right;
        while (replacement->left != NULL)
        {
            replacement = replacement->left;
        }

        root->data = replacement->data;
        // we need to delete the replacement node it can again have 2cases: 0 child, 1 right child
        root->right = deleteInBST(root->right, replacement->data);
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteInBST(root->left, data);
    }
    else
    {
        root->right = deleteInBST(root->right, data);
    }
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); //for adding a endl after each level

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        }
        cout << f->data << " ";
        q.pop();
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
}

bool isBST(node *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < max && root->data > min)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);

        if (left && right)
        {
            return true;
        }
    }

    return false;
}

class LinkedList
{
public:
    node *head;
    node *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
};

LinkedList flattenBST(node *root)
{
    LinkedList l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }

    LinkedList left = flattenBST(root->left);
    LinkedList right = flattenBST(root->right);

    // got no ll from left and right
    if (left.head == NULL && right.head == NULL)
    {
        l.head = l.tail = root;
        return l;
    }

    // got a linked list from right but not from left
    if (left.head == NULL && right.head != NULL)
    {
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    }

    // got a ll from left but no from right
    if (left.head != NULL && right.head == NULL)
    {
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l;
    }

    // got a ll from both left and right
    if (left.head != NULL && right.head != NULL)
    {
        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;
        return l;
    }
}

int main()
{
    node *root = NULL;
    int in;
    cin >> in;
    root = buildBst(root, in);
    while (1)
    {
        cin >> in;
        if (in == -1)
            break;
        buildBst(root, in);
    }
    bfs(root);
    // cout << searchBst(root, 2) << " " << searchBst(root, -1);
    // deleteInBST(root, 7);
    // cout << endl;
    // bfs(root);

    // cout << "check bst " << isBST(root);

    node *head = flattenBST(root).head;
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->right;
    }
}
