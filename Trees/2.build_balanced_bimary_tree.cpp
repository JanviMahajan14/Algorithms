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

node *build_balanced_tree(int a[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = new node(a[mid]);
    root->left = build_balanced_tree(a, start, mid - 1);
    root->right = build_balanced_tree(a, mid + 1, end);
    return root;
}

node *createtreeInPre(int *pre, int *in, int start, int end)
{
    static int i = 0;
    if (start > end)
    {
        return NULL;
    }
    node *root = new node(pre[i]);
    int index;

    // search for pre[i] in inorder array
    for (int j = start; j <= end; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++; // increament pointer for tarversing in preorder array
    root->left = createtreeInPre(pre, in, start, index - 1);
    root->right = createtreeInPre(pre, in, index + 1, end);
    return root;
}

void printrightview(node *root, int cur_level, int &max_level)
{
    if (root == NULL)
    {
        return;
    }

    // discovered a new level
    if (max_level < cur_level)
    {
        cout << root->data << " ";
        max_level = cur_level;
    }

    printrightview(root->right, cur_level + 1, max_level);
    printrightview(root->left, cur_level + 1, max_level);
    return;
}

void printkthlevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printkthlevel(root->left, k - 1);
    printkthlevel(root->right, k - 1);
}

// finding all the ancestors of a given node
int printansestors(node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        cout << root->data << " ";
        return 1;
    }
    int left = printansestors(root->left, data);
    if (left == 1)
    {
        cout << root->data << " ";
        return 1;
    }
    int right = printansestors(root->right, data);
    if (right == 1)
    {
        cout << root->data << " ";
        return 1;
    }
}

// Finding all the nodes at distance K from the target node
int printallnodesfromk(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printkthlevel(root, k);
        return 0; //distance of target from left/right child of the root
    }
    int left = printallnodesfromk(root->left, target, k);
    int right = printallnodesfromk(root->right, target, k);

    if (left >= 0)
    {
        if (k - (left + 1) == 0) //if root itself is a reqd node---corner-case
        {
            cout << root->data << " ";
            return -1;
        }
        printkthlevel(root->right, k - left - 2);
        return left + 1;
    }
    else if (right >= 0)
    {
        if (k - (right + 1) == 0)
        {
            cout << root->data << " ";
            return -1;
        }
        printkthlevel(root->left, k - right - 2);
        return right + 1;
    }

    // node not present anywhere
    return -1;
}

// max sum path from any node to any other node
class Pair
{
public:
    int totalPathSum;
    int maxBranchSum;
    Pair()
    {
        totalPathSum = 0;
        maxBranchSum = 0;
    }
};

Pair maxSumPathBtwNodes(node *root)
{
    Pair p;
    if (root == NULL)
    {
        return p;
    }

    Pair leftSubTree = maxSumPathBtwNodes(root->left);
    Pair rightSubTree = maxSumPathBtwNodes(root->right);

    int op1 = root->data;
    int op2 = root->data + leftSubTree.maxBranchSum;
    int op3 = root->data + rightSubTree.maxBranchSum;
    int op4 = root->data + leftSubTree.maxBranchSum + rightSubTree.maxBranchSum;

    int maxSumPassThroughRoot = max(op1, max(op2, max(op3, op4)));
    int maxBranchSumfromRoot = max(leftSubTree.maxBranchSum, max(rightSubTree.maxBranchSum, 0)) + root->data;

    p.maxBranchSum = maxBranchSumfromRoot;
    p.totalPathSum = max(maxSumPassThroughRoot, max(leftSubTree.totalPathSum, rightSubTree.totalPathSum));
    return p;
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        }
        node *n = q.front();
        q.pop();
        cout << n->data << " ";
        if (n->left)
        {
            q.push(n->left);
        }
        if (n->right)
        {
            q.push(n->right);
        }
    }
}

int main()
{
    // int a[] = {1, 2, 3, 4, 5, 6, 7};
    // node *root = build_balanced_tree(a, 0, 6);
    // bfs(root);

    // int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    // int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    // node *root = createtreeInPre(pre, in, 0, 7);
    // bfs(root);

    // int current_level = 1;
    // int max_level = 0;
    // printrightview(root, current_level, max_level);

    node *root = buildnode();
    bfs(root);
    cout << endl;
    // printallnodesfromk(root, root->left->left, 3);
    cout << maxSumPathBtwNodes(root).totalPathSum << endl;
}