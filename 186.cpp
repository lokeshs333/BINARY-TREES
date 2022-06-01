// rightview of o tree uhsing recursion done in first attempt
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
void rightViewUtil(struct node *root,
                   int level, int *max_level)
{
    // Base Case
    if (root == NULL)
        return;

    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }

    // Recur for right subtree first,.......
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void right_view(struct node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
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

    root->left = a;
    a->left = c;
    root->right = b;
    b->left = d;
    b->right = e;
    d->left = f;
    d->right = g;
    right_view(root);
    return 0;
}
