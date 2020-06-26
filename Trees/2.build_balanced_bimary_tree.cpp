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

    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    node *root = createtreeInPre(pre, in, 0, 7);
    bfs(root);
    int current_level = 1;
    int max_level = 0;
    printrightview(root, current_level, max_level);
}