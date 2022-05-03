// mirror of a tree..
#include <iostream>
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
void mirror(node *root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}
int main()
{
    node *root = createnode(1);
    node *a = createnode(2);
    node *b = createnode(3);
    node *c = createnode(4);
    node *d = createnode(5);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    inorder(root);
    cout << endl;

    cout << "lokesh pandey kse ho ap " << endl;
    mirror(root);
    inorder(root);

    return 0;
}