// sum of maximum subtree in an tree.....

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *createnode(int data)
{
    node *n = new node;
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}
void inorder(node *root)

{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
map<node *, int> dp;
int function(node *root)
{
    if (!root)
    {
        return 0;
    }
    if (dp[root])
        return dp[root];
    int inc = root->data;
    if (root->left)
    {
        inc += function(root->left->left);
        inc += function(root->left->right);
    }
    if (root->right)
    {
        inc += function(root->right->left);
        inc += function(root->right->right);
    }
    int exc = function(root->left) + function(root->right);
    dp[root] = max(inc, exc);
    return dp[root];
}
int main()
{
    node *root = createnode(1);
    node *a = createnode(2);
    node *b = createnode(3);
    node *c = createnode(4);
    node *d = createnode(5);
    node *e = createnode(6);
    node *f = createnode(7);
    node *g = createnode(8);
    /*              1
                   /  \
                 2     3
                /     / \
              4      5   6
                    / \
                  7     8      */
    root->left = a;
    a->left = c;
    root->right = b;
    b->left = d;
    b->right = e;
    d->left = f;
    d->right = g;
    cout << endl
         << "hello lokesh pandey" << endl;

    cout << "lokesh pandey" << endl;
    int aa = function(root);
    return 0;
}