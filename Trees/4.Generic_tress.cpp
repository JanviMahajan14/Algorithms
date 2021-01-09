#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int d)
    {
        data = d;
    }
};

void form_generic_tree(Node *&root, stack<Node *> &s, int data)
{
    if (data == -1)
    {
        s.pop();
        return;
    }
    else
    {
        Node *n = new Node(data);
        if (s.size() > 0)
            s.top()->children.push_back(n);
        else
            root = n;
        s.push(n);
        return;
    }
}

void display_generic_tree(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    for (auto x : root->children)
    {
        display_generic_tree(x);
    }
    return;
}

int size_of_tree(Node *root)
{ // Calculate total number of nodes in generic tree
    if (root == NULL)
    {
        return 0;
    }

    int size = 1;
    for (auto x : root->children)
    {
        size = size + size_of_tree(x);
    }
    return size;
}

int find_max_in_gen(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int max_val = root->data;
    for (auto x : root->children)
    {
        max_val = max(max_val, find_max_in_gen(x));
    }
    return max_val;
}

int height_tree(Node *root)
{ // Maximum depth of tree--------IMP-----------------------counting wrt to edges
    if (root == NULL)
    {
        return 0;
    }

    int height = 0;

    for (auto x : root->children)
    {
        height = max(height, 1 + height_tree(x));
    }
    return height;
}

void level_order(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL); // END of one level

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << "\n";
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        cout << front->data << " ";
        for (auto x : front->children)
        {
            q.push(x);
        }
    }
}

void mirror(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    for (auto x : root->children)
    {
        mirror(x);
    }

    int i = 0;
    int j = root->children.size() - 1;
    while (i < j)
    {
        swap(root->children[i], root->children[j]); //Swap the odes in the vector
        i++;
        j--;
    }
}

void zigzag_traversal(Node *root) //--------------IMP--------------------
{

    stack<Node *> ms; //main stack
    stack<Node *> cs; //child stack

    ms.push(root);
    int level = 0;

    while (!ms.empty())
    {
        Node *top = ms.top();
        cout << top->data << " ";
        ms.pop();

        if (level % 2 == 0)
        {
            for (auto x : top->children)
            {
                cs.push(x);
            }
        }
        else
        {
            for (int i = top->children.size() - 1; i >= 0; i--)
            {
                cs.push(top->children[i]);
            }
        }

        if (ms.empty())
        {
            swap(ms, cs);
            level++;
            cout << "\n";
        }
    }
}

// VVV IMP
bool remove_leaves(Node *root)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->children.size() == 0)
    {
        return true;
    }

    // if we delete on the same loop we are travesing. Then after every removal
    // elements will shift backward and i will move forward.Hence some elements willn't
    // be checked.So apply loop in opp direction
    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     bool isleaf = remove_leaves(root->children[i]);
    //     if (isleaf)
    //     {
    //         root->children.erase(root->children.begin() + i);
    //     }
    // }
    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        bool isleaf = remove_leaves(root->children[i]);
        if (isleaf)
        {
            root->children.erase(root->children.begin() + i); // Don't consider in TC
        }
    }
    return false;
} // TC O(n)

bool search(Node *root, int d)
{
    if (root->data == d)
    {
        return true;
    }

    for (auto x : root->children)
    {
        bool res = search(x, d);
        if (res)
            return true;
    }

    return false;
}

bool node_to_root(Node *root, int data, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        path.push_back(root->data);
        return true;
    }

    path.push_back(root->data);
    for (auto x : root->children)
    {
        bool isfound = node_to_root(x, data, path);
        if (isfound)
        {
            return true;
        }
    }
    path.pop_back();
    return false;
}

bool tree_similiar(Node *a, Node *b)
{
    if (a == NULL || b == NULL)
    {
        return a == b;
    }

    if (a->children.size() != b->children.size())
    {
        return false;
    }

    for (int i = 0; i < a->children.size(); i++)
    {
        bool isSimiliar = tree_similiar(a->children[i], b->children[i]);
        if (!isSimiliar)
        {
            return false;
        }
    }
    return true;
}

bool check_mirror(Node *a, Node *b)
{
    if (a == NULL || b == NULL)
    {
        return a == b;
    }

    if (a->children.size() != b->children.size())
    {
        return false;
    }

    int i = 0;
    int j = a->children.size() - 1;
    while (i < j)
    {
        bool ismirror = check_mirror(a->children[i], b->children[j]);
        if (!ismirror)
            return false;
        i++;
        j--;
    }

    return true;
}

// Check if a tree is symmetric around itself-----mirror of itself
bool isTreeSymmetric(Node *root)
{
    return check_mirror(root, root);
}

// The parameters in heap will not backtrack during recursion
// Finding predeccor and succesor in preorder traversal
static Node *pre = NULL;
static Node *succ = NULL;
static int state = 0;
void find_pre_and_succ(Node *root, Node *target)
{
    if (state == 0)
    {
        if (root == target)
        {
            state = 1;
        }
        else
        {
            pre = root;
        }
    }
    else if (state == 1)
    {
        succ = root;
        state = 2;
    }

    for (auto x : root->children)
    {
        find_pre_and_succ(x, target);
    }
    return;
}

// finding ceil and floor of a generic tree
void find_ceil_and_floor(Node *root, int data, int &ceil, int &floor)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data < data)
    {
        floor = max(floor, root->data);
    }
    if (root->data > data)
    {
        ceil = min(ceil, root->data);
    }

    for (auto x : root->children)
    {
        find_ceil_and_floor(x, data, ceil, floor);
    }
}

// Finding kth largest ---MUST READ
int kth_largest_value(Node *root, int k)
{
    int ceil = INT_MAX;
    int floor = INT_MIN;
    int ans = INT_MAX;
    while (k--)
    {
        find_ceil_and_floor(root, ans, ceil, floor);
        ans = floor;
        ceil = INT_MAX;
        floor = INT_MIN;
    }
    return ans;
}

void iterative_pre(Node *root)
{
    stack<Node *> s;
    if (root == NULL)
    {
        return;
    }
    s.push(root);
    while (!s.empty())
    {
        Node *top = s.top();
        s.pop();
        cout << top->data << " ";
        for (int i = top->children.size() - 1; i >= 0; i--)
        {
            s.push(top->children[i]);
        }
    }
}

void iterative_post(Node *root)
{
    stack<Node *> s;
    if (root == NULL)
    {
        return;
    }
    s.push(root);
    while (s.top()->children.size() > 0)
    {
        Node *top = s.top();
        for (int i = top->children.size() - 1; i >= 0; i--)
        {
            s.push(top->children[i]);
        }
    }

    Node *prev = NULL;
    while (!s.empty())
    {
        Node *top = s.top();
        if (top->children.size() == 0 || prev == top->children[top->children.size() - 1])
        {
            cout << top->data << " ";
            prev = top;
            s.pop();
        }
        else
        {
            for (int i = top->children.size() - 1; i >= 0; i--)
            {
                s.push(top->children[i]);
            }
        }
    }
}

int max_sum_subtree(Node *root, int &ms)
{
    int sum = 0;
    for (auto x : root->children)
    {
        sum = sum + max_sum_subtree(x, ms);
    }

    sum = sum + root->data;
    ms = max(ms, sum);
    return sum;
}

// DIAMETER of a generic tree---MAX distance between two nodes

int main()
{
    stack<Node *> s;
    Node *root = NULL;
    int arr[] = {
        10,
        20,
        50,
        -1,
        60,
        -1,
        -1,
        30,
        70,
        -1,
        80,
        110,
        -1,
        120,
        -1,
        -1,
        90,
        -1,
        -1,
        40,
        100,
        -1,
        -1,
        -1};

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        form_generic_tree(root, s, arr[i]);
    }

    // display_generic_tree(root);

    // cout << "\n"
    //      << size_of_tree(root);
    // cout << "\n"
    //      << find_max_in_gen(root);
    // cout << "\n"
    //      << height_tree(root);
    // cout << "\n";
    // level_order(root);

    // cout << "\n\n";
    // mirror(root);
    // level_order(root);

    // zigzag_traversal(root);

    // bool isleaf = remove_leaves(root);
    // cout << "\n";
    // level_order(root);

    // cout << "\n"
    //      << search(root, 110);

    // vector<int> path;
    // node_to_root(root, 90, path);
    // cout << "\n";
    // for (auto x : path)
    // {
    //     cout << x << " ";
    // }

    // cout << kth_largest_value(root, 5);
    iterative_pre(root);
    cout << "\n";
    iterative_post(root);
}