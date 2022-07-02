// sum of longest path in a binary tree

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
int maxsum;
void max_sum(node *root, int sum)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr && sum + root->data > maxsum)
    {
        maxsum = sum + root->data;
        return;
    }
    max_sum(root->left, sum + root->data);
    max_sum(root->right, sum + root->data);
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
    max_sum(root, 0);
    cout << "of max sum is " << maxsum << endl;
    cout << "lokesh pandey" << endl;

    // inorder(root);
    return 0;
}