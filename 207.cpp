//find the lowest common ancestor......
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
node *lca(node *root, node *p, node *q)
{
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }
    node *left = lca(root->left, p, q);
    node *right = lca(root->right, p, q);
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    else if (left != nullptr && right != nullptr)
    {
        return root;
    }
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
    node *aaa = lca(root, e, f);
    cout << "answer is " << aaa->data << endl;

    return 0;
}
