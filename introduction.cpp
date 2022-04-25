#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *cretenode(int data)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

/* TREE will look like this

                p

        p1            p2

    p1a    p1b    p2a    p2b


*/
int main()
{
    node *p = cretenode(333);
    node *p1 = cretenode(1);
    node *p2 = cretenode(2);
    node *p1a = cretenode(3);
    node *p1b = cretenode(4);
    node *p2a = cretenode(5);
    node *p2b = cretenode(6);
    p->left = p1;
    p->right = p2;
    p1->left = p1a;
    p1->right = p1b;
    p2->left = p2a;
    p2->right = p2b;

    return 0;
}