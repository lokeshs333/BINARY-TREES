// C++ program to print top
// TOP view of binary tree

#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node
{
    Node *left;
    Node *right;
    int hd;
    int data;
};
Node *createnode(int data)
{
    Node *n = new Node;
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}

// function to create a new node
// Node *newNode(int key)
// {
//     Node *node = new Node();
//     node->left = node->right = NULL;
//     node->data = key;
//     return node;
// }

// function should print the topView of
// the binary tree
void topview(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;

    // push node and horizontal distance to queue
    q.push(root);

    cout << "The top view of the tree is : \n";

    while (q.size())
    {
        hd = root->hd;

        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
    }
}

// Driver Program to test above functions

int main()
{
    Node *root = createnode(1);
    Node *a = createnode(2);
    Node *b = createnode(3);
    Node *c = createnode(4);
    Node *d = createnode(5);
    Node *e = createnode(6);
    Node *f = createnode(7);
    Node *g = createnode(8);

    root->left = a;
    a->left = c;
    root->right = b;
    b->left = d;
    b->right = e;
    d->left = f;
    d->right = g;
    topview(root);
    return 0;
}
