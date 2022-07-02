// check if a binary tree has same level of trees or not..
//https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

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
int ans;
void solve(node *root, int h, int &ma)
{
    if (!root)
    {
        return;
    }
    if (ans == 0)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        if (ma == -1)
        {
            ma = h;
        }
        else if (h != ma)
        {
            ans = 0;
        }
        return;
    }
    solve(root->left, h + 1, ma);
    solve(root->right, h + 1, ma);
}

void same_level_or_not(node *root)
{
    int ma = -1;
    int h = 0;
    ans = 1;
    solve(root, h, ma);
    cout << "answer is    " << ans << endl;
    if (ans == 0)
    {
        cout << "false " << endl;
    }
    else
    {
        cout << "trur" << endl;
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
    same_level_or_not(root);
    cout << "lokesh pandey" << endl;

    // inorder(root);
    return 0;
}
