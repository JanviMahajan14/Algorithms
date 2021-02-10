#include <iostream>
#include <climits>
#include <queue>
#include <stack>
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

// catalan series
// int numOfBST(int n)
// {
//     static int res = 0;
//     if (n == 0)
//     {
//         return 1;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         res = res + numOfBST(n) * numOfBST(n - i);
//     }

//     return res;
// }

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

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

// merge bst and get inorder traversal of final BST in O(h1+h2)
void merge_bst(node *r1, node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return;
    }
    else if (r1 == NULL)
    {
        inorder(r2);
    }
    else if (r2 == NULL)
    {
        inorder(r1);
    }
    else
    {
        stack<node *> s1;
        stack<node *> s2;
        while (r1 != NULL || r2 != NULL || !s1.empty() || !s2.empty())
        {
            if (r1 || r2)
            {
                if (r1)
                {
                    s1.push(r1);
                    r1 = r1->left;
                }
                if (r2)
                {
                    s2.push(r2);
                    r2 = r2->left;
                }
            }
            else
            {
                node *top1 = !s1.empty() ? s1.top() : NULL;
                node *top2 = !s2.empty() ? s2.top() : NULL;

                if (top2 == NULL)
                { //first OR when one stack is completely exhausted
                    s1.pop();
                    cout << top1->data << " ";
                    r1 = top1->right;
                }
                else if (top1 == NULL)
                {
                    s2.pop();
                    cout << top2->data << " ";
                    r2 = top2->right;
                }

                else if (top1->data < top2->data)
                {
                    s1.pop();
                    cout << top1->data << " ";
                    r1 = top1->right;
                }
                else if (top1->data > top2->data)
                {
                    s2.pop();
                    cout << top2->data << " ";
                    r2 = top2->right;
                }
                else
                {
                    s1.pop();
                    cout << top1->data << " ";
                    r1 = top1->right;
                    s2.pop();
                    cout << top2->data << " ";
                    r2 = top2->right;
                }
            }
        }
    }
}

class Pair
{
public:
    bool isBst;
    int size;
    int min;
    int max;
};

Pair largest_bst(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.isBst = true; //null is also a bst with 0 size
        p.size = 0;
        p.min = INT_MAX; //Think of case when there is only left or only right
        p.max = INT_MIN; // So pass parameters of min and max opposite
        return p;
    }

    if (!root->left && !root->right)
    {
        p.isBst = true;
        p.size = 1;
        p.min = root->data;
        p.max = root->data;
        return p;
    }

    Pair left = largest_bst(root->left);
    Pair right = largest_bst(root->right);

    Pair res;

    if (left.isBst && right.isBst)
    {
        if (root->data > left.max && root->data < right.min)
        {
            res.isBst = true;
            res.size = left.size + right.size + 1;
            res.min = root->left ? left.min : root->data;   //special case when root->left doesn't exist
            res.max = root->right ? right.max : root->data; //special case when root->right doesn't exist
            return res;
        }
    }

    res.isBst = false;
    res.min = left.min;
    res.max = right.max;
    res.size = max(left.size, right.size);
    return res;
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

// Follow gfg----- ^-^
//LinkedList flattenBST(node *root)

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

    // cout << numOfBST(2);
}
