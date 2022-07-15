// level order traversal using queue.........
//Iterative approach............
#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
};
node *createnode(int data)
{
    node *n = new node;

    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        cout << n->data << " ";
        if (n->left != NULL)
        {
            q.push(n->left);
        }
        if (n->right != NULL)
        {
            q.push(n->right);
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
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    levelordertraversal(root);
    // cout << "root ka data he " << root->data;

    return 0;
}
