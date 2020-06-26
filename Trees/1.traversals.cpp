#include <iostream>
#include <queue>
#include <algorithm>
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
    return max(op1, max(op2, op3));
}

// Optimised way of finding diameter --bottom up approach --- post order traversal
class Pair
{
public:
    int height;
    int diameter;
};

Pair fastdiameter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }

    Pair left = fastdiameter(root->left);
    Pair right = fastdiameter(root->right);

    Pair res;
    res.height = max(left.height, right.height) + 1;
    res.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return res;
}

// Replacing parent node with sum of its all descandts(children)--top-down---O(n^2)
node *replacebysum(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return NULL; //when it's a leaf node
    }
    root->data = sum(root) - root->data;
    replacebysum(root->left);
    replacebysum(root->right);
    return root;
}

// Bottom-up-approach--O(n)
int fastreplacebySum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = fastreplacebySum(root->left);
    int rightSum = fastreplacebySum(root->right);
    if (leftSum == 0 && rightSum == 0)
    {
        return root->data;
    }
    int temp = root->data; //trick
    root->data = leftSum + rightSum;
    return temp + root->data;
}

// check if a height balanced tree
pair<int, bool> heightBalanced(node *root)
{
    if (root == NULL)
    {
        return make_pair(0, true);
    }
    pair<int, bool> left = heightBalanced(root->left);
    pair<int, bool> right = heightBalanced(root->right);
    int diff = abs(left.first - right.first);
    if (left.second == false || right.second == false)
    {
        return make_pair(diff, false);
    }
    if (diff <= 1)
        return make_pair(max(left.first, right.first) + 1, true);
    else
        return make_pair(max(left.first, right.first) + 1, false);
}

node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a || root->data == b)
    {
        return root;
    }

    node *left = lca(root->left, a, b);
    node *right = lca(root->right, a, b);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
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
    // for (int i = 1; i <= heightoftree(root); i++)
    // {
    //     printkthlevel(root, i);
    //     cout << endl;
    // }
    bfs(root);
    // cout << count(root) << endl;
    // cout << sum(root) << endl;
    // cout << fastdiameter(root).height << " " << fastdiameter(root).diameter << endl;
    // fastreplacebySum(root); //changed because root is in heap memory
    // bfs(root);
    // cout << endl;
    // cout << heightBalanced(root).second << endl;

    int a = 6, b = 7;
    cout << lca(root, a, b)->data << endl;
}