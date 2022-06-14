// diameter is using recursion..
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
int height(node *root, int &dia)
{
    if (root == NULL)
        return 0;
    int l = height(root->left, dia);
    int r = height(root->right, dia);
    dia = max(dia, l + r + 1);
    return max(l, r) + 1;
}
int diameter(node *root)
{
    // Your code here
    int dia = 0;
    height(root, dia);
    cout << "diamerter is " << dia << endl;
    return dia;
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
    diameter(root);
    // cout << "diameter is " << a << endl;

    return 0;
}
