#//check if two trees are mirror or not.....

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
int are_mirror(node *a, node *b)
{
    if (a == NULL && b == NULL)
    {
        return true;
    }
    if (a == NULL || b == NULL)
    {
        return false;
    }
    return (a->data == b->data && are_mirror(a->left, b->right) && are_mirror(a->right, b->left));
}
int main()
{
    node *root1 = createnode(1);
    node *a1 = createnode(2);
    node *b1 = createnode(3);
    node *c1 = createnode(4);
    node *root2 = createnode(1);
    node *a2 = createnode(2);
    node *b2 = createnode(3);
    node *c2 = createnode(4);
    root1->left = a1;
    root1->right = b1;
    b1->right = c1;
    root2->left = b2;
    root2->right = a2;
    b2->left = c2;

    cout << endl
         << "hello lokesh pandey" << endl;

    cout << "lokesh pandey" << endl;
    int a = are_mirror(root1, root2);
    cout << "value is " << a << endl;

    return 0;
}