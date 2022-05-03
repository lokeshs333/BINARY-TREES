// hight of a tree using recursion;
// we can also do this using level order traversal but in that case it will take space of queue..
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
    return 1 + max(l, r);
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
    cout << "height of this tree is " << height(root) << endl;

    return 0;
}