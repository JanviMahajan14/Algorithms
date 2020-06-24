#include <iostream>
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

node *buildnode()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *n = new node(d);
    n->left = buildnode();
    n->right = buildnode();
    return n;
}

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void printIn(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void printpost(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printpost(root->left);
    printpost(root->right);
    cout << root->data << " ";
}

int heightoftree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = heightoftree(root->left);
    int rightHeight = heightoftree(root->right);
    int height = max(leftHeight, rightHeight) + 1;
    return height;
}

// worst case complexity is O(n^2) in case of screw tree
void printkthlevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printkthlevel(root->left, k - 1);
    printkthlevel(root->right, k - 1);
}

//O(n) because every element is push and pop in tree
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
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

//preorder traversal O(n)
int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int res = count(root->left) + count(root->right) + 1;
    return res;
}

int sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = sum(root->left) + sum(root->right) + root->data;
    return ans;
}

// when we talk about diameter we talk about edges and when we talk about height/level
// we talk about nodes
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    //O(n) for height and we are doing this for every node so O(n^2)
    int h1 = heightoftree(root->left);
    int h2 = heightoftree(root->right);
    int op1 = h1 + h2;               //passes throught root
    int op2 = diameter(root->left);  //lies in left sub tree
    int op3 = diameter(root->right); // lies in right sub tree
    return max(op1, op2, op3);
}

int main()
{
    node *root = buildnode();
    // print(root);
    // cout << endl;
    // printIn(root);
    // cout << endl;
    // printpost(root);
    // cout << endl;
    // cout << heightoftree(root);
    // cout << endl;
    for (int i = 1; i <= heightoftree(root); i++)
    {
        printkthlevel(root, i);
        cout << endl;
    }
    bfs(root);
    cout << endl;
    cout << count(root) << endl;
    cout << sum(root) << endl;
}