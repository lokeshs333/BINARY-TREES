// leftview of binary tree of a tree
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
vector<int> diagonal(node *root)
{
    // your code here
    queue<node *> q;
    vector<int> ans;
    if (root == nullptr)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
                q.push(temp->left);
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

// void diagonal(node *root)
// {
//     vector<node *> ans;
//     queue<node *> q;
//     q.push(root);
//     if (root == NULL)
//     {
//         return;
//     }
//     while (!q.empty())
//     {
//         diagonal(root->right);
//         cout << root->data << " ";
//         ans.push_back(root->left);
//     }
//     for (int i = 0; i < ans.size(); i++)
//     {
//         ans[i];
//     }
// }

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
    vector<int> aa = diagonal(root);
    for (int i = 0; i < aa.size(); i++)
    {
        cout << aa[i] << " " << endl;
    }

    return 0;
}