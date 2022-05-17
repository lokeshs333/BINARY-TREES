// check wheather the ttree in balanced tree or not
// leftview of binary tree of a tree
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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    if (abs(l - r) > 1)
    {
        return -1;
    }
    return 1 + max(l, r);
}

int main()
{
    node *root = createnode(1);
    node *a = createnode(2);
    node *b = createnode(3);
    // node *c = createnode(4);
    node *d = createnode(5);
    node *e = createnode(6);
    node *f = createnode(7);
    node *g = createnode(8);
    /*              1

                 2       3

              4      5      6

                  7     8      */
    root->left = a;
    // a->left = c;
    root->right = b;
    b->left = d;
    b->right = e;
    d->left = f;
    d->right = g;
    cout << endl
         << "hello lokesh pandey" << endl;
    int aa = height(root);
    if (aa == -1)
    {
        cout << "the tree is not balanced,therefore" << aa;
    }
    else
    {
        cout << "the tree is balanced and the height is" << aa;
    }
    // cout << "height is " << aa << endl;

    return 0;
}