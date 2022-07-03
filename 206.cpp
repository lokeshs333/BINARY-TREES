// all k sumpaths in an binary tree....

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
int m = 0;

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
void func(node *root, vector<int> &path, int k)
{
    if (!root)
    {
        return;
    }
    path.push_back(root->data);
    func(root->left, path, k);
    func(root->right, path, k);
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];
        if (f == k)
        {
            for (int i = j; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
    }
    path.pop_back();
}

int main()
{
    node *root = createnode(1);
    node *a = createnode(2);
    node *b = createnode(4);
    node *c = createnode(4);
    node *d = createnode(4);
    node *e = createnode(2);
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
    vector<int> path;
    func(root, path, 7);
    return 0;
}