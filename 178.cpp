// reverse the level order traversal..
// done
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
void reverse_level_ordertraversal(node *root)
{
    queue<node *> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {
        node *n = q.front();
        ans.push_back(n->data);
        // cout << n->data << " ";
        q.pop();
        if (n->right != NULL)
        {
            q.push(n->right);
        }
        if (n->left != NULL)
        {
            q.push(n->left);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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
    reverse_level_ordertraversal(root);

    return 0;
}
