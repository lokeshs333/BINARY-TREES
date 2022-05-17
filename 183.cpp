// preorder of a tree
// revised
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
void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void preorder_iterative(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *cur = st.top();
        st.pop();
        cout << cur->data << " ";
        if (cur->right)
        {
            st.push(cur->right);
        }
        if (cur->left)
        {
            st.push(cur->left);
        }
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

    root->left = a;
    a->left = c;
    root->right = b;
    b->left = d;
    b->right = e;
    d->left = f;
    d->right = g;
    preorder(root);
      cout << "preorder using itterative approach is " << endl;
    preorder_iterative(root);
    return 0;
}
