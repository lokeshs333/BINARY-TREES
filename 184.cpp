// postorder of a tree using recursion..........
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
void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void postorder_Iterative(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> st;
    st.push(root);
    stack<int> lok;
    while (!st.empty())
    {
        node *cur = st.top();
        st.pop();
        lok.push(cur->data);

        if (cur->left)
        {
            st.push(cur->left);
        }
        if (cur->right)
        {
            st.push(cur->right);
        }
    }
    while (!lok.empty())
    {
        cout << lok.top() << " ";
        lok.pop();
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
    postorder(root);
     cout << endl;
    cout << "postorder using iteration method is" << endl;
    postorder_Iterative(root);
    return 0;
}
