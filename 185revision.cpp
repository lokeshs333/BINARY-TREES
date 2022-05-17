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
// void leftview(node *root, int level)
// {
//     queue<node *> st;
//     if (root == nullptr)
//     {
//         return;
//     }
//     if (level == st.size())
//     {
//         st.push(root);
//     }

//     leftview(root->right, level + 1);
//     leftview(root->left, level + 1);
//     while (!st.empty())
//     {
//         cout << st.front()->data << " ";
//         st.pop();
//     }
// }
void printLeftView(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        // number of nodes at current level
        int n = q.size();

        // Traverse all nodes of current level
        for (int i = 1; i <= n; i++)
        {
            node *temp = q.front();
            q.pop();

            // Print the left most element
            // at the level
            if (i == 1)
                cout << temp->data << " ";

            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
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
    // leftview(root, 0);
    printLeftView(root);

    return 0;
}