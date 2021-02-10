#include <iostream>
#include <queue>
#include <stack>
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

// Inorder traversal without recursion using stack
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        if (root)
        {
            root = root->left;
            if (root)
                s.push(root);
        }
        else
        {
            node *top = s.top();
            s.pop();
            cout << top->data << " ";
            root = top->right;
            if (root)
                s.push(root);
        }
    }
}

// Morris inorder traversal---Without recursion and without stack
void moris(node *root)
{
    if (root == NULL)
    {
        return;
    }

    while (root != NULL)
    {
        if (!root->left) //if no left child
        {
            cout << root->data << " ";
            root = root->right;
        }
        else //find the predecessor of root
        {
            node *curr = root;
            root = root->left;
            while (root->right != NULL && root->right != curr)
            {
                root = root->right;
            }

            if (root->right == NULL) // if predessor visited for 1st time
            {
                root->right = curr;
                root = curr->left;
            }
            else if (root->right == curr) // if predessor is already visted
            {
                root->right = NULL;
                cout << curr->data << " ";
                root = curr->right;
            }
        }
    }
}

void moris_preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    while (root != NULL)
    {
        cout << root->data << " ";

        if (root && !root->left)
        {
            root = root->right;
        }
        else
        {
            node *curr = root;
            root = root->left;
            while (root->right != NULL && root->right != curr->right)
            {
                root = root->right;
            }
            if (root->right == NULL)
            {
                root->right = curr->right;
                root = curr->left;
            }
            else if (root->right == curr->right)
            {
                root->right = NULL;
                root = curr->right;
            }
        }
    }
}

// Iterative postorder traversal using two stacks
void post(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> s1; //contains left and right child
    stack<node *> s2; // contains the final result
    s1.push(root);

    while (!s1.empty())
    {
        node *top = s1.top();
        s1.pop();
        s2.push(top);
        if (top->left)
        {
            s1.push(top->left);
        }
        if (top->right)
        {
            s1.push(top->right);
        }
    }

    // Printing the result stored in s2
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void post_one_stack(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> s;
    node *prev = NULL;
    s.push(root);
    while (!s.empty())
    {
        if (root && root->left)
        {
            root = root->left;
            s.push(root);
        }
        else
        {
            node *top = s.top();
            if (top->right && top->right != prev)
            {
                root = top->right;
                s.push(root);
            }
            else
            {
                cout << top->data << " ";
                prev = top;
                s.pop();
            }
        }
    }
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

// worst case complexity is O(n^2) in case of screw tree for finding Level order traversal
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

// Finding shortest distance between nodes of binary tree
int getlevel(node *root, int a)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == a)
    {
        return 0;
    }

    int left = getlevel(root->left, a);
    int right = getlevel(root->right, a);

    if (left == -1 && right == -1)
    {
        return -1;
    }

    if (left != -1)
    {
        return left + 1;
    }
    return right + 1;
}

int shortdis(node *root, int a, int b)
{
    if (root == NULL)
    {
        return -1;
    }
    int levela = getlevel(root, a);
    int levelb = getlevel(root, b);
    int levellca = getlevel(root, lca(root, a, b)->data);
    return levela + levelb - (2 * (levellca));
}

// Check if two nodes are on same path--- LCA application
bool lca_for_same_path(node *root, int a, int b)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == a || root->data == b)
    {
        return true;
    }

    bool left = lca_for_same_path(root->left, a, b);
    bool right = lca_for_same_path(root->right, a, b);
    if (left && right)
    {
        return false;
    }
    if (left)
    {
        return true;
    }
    if (right)
    {
        return true;
    }
    return false; //nodes don't exist
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
    // inorder(root);
    // cout << endl;
    // moris_preorder(root);
    // post_one_stack(root);
    // bfs(root);
    // cout << count(root) << endl;
    // cout << sum(root) << endl;
    // cout << fastdiameter(root).height << " " << fastdiameter(root).diameter << endl;
    // fastreplacebySum(root); //changed because root is in heap memory
    // bfs(root);
    // cout << endl;
    // cout << heightBalanced(root).second << endl;

    // int a = 6, b = 7;
    // cout << lca(root, a, b)->data << endl;

    // cout << shortdis(root, 10, 3);
    cout << lca_for_same_path(root, 5, 2);
}