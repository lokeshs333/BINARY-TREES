// boundary of a binary tree
//done easy one
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
// left tree top to bottom....
// leaves left to right....
// right part of tree doen to up....

// A simple function to print leaf nodes of a binary tree
void printLeaves(node *root)
{
    if (root == nullptr)
        return;

    printLeaves(root->left);

    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
    {
        cout << root->data << " ";
    }

    printLeaves(root->right);
}

// A function to print all left boundary nodes, except a
// leaf node. Print the nodes in TOP DOWN manner
void printBoundaryLeft(node *root)
{
    if (root == nullptr)
        return;

    if (root->left)
    {

        // to ensure top down order, print the node
        // before calling itself for left subtree
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to print all right boundary nodes, except a
// leaf node Print the nodes in BOTTOM UP manner
void printBoundaryRight(node *root)
{
    if (root == nullptr)
        return;

    if (root->right)
    {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to do boundary traversal of a given binary
// tree
void printBoundary(node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";

    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);

    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);

    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
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

                 2       3

              4      5      6

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
    printBoundary(root);
    return 0;
}
