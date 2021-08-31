#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//1 2 4 -1  -1 5 7 -1 -1 -1 3 -1 6 -1 -1

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void printNodesAtK(node *root, int k)
{

    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printNodesAtK(root->left, k - 1);
    printNodesAtK(root->right, k - 1);
}

void printNodes(node *root, int key, int &dist, int k)
{

    if (root == NULL)
    {
        return;
    }

    if (key == root->data)
    {
        dist = 0;
        printNodesAtK(root, k);
        return;
    }
    int ldist = -1, rdist = -1;
    printNodes(root->left, key, ldist, k);
    printNodes(root->right, key, rdist, k);

    if (ldist != -1)
    {
        dist = ldist + 1;
        if (k - dist == 0)
        {
            cout << root->data;
        }
        else if (k > dist)
            printNodesAtK(root->right, k - dist - 1);
    }

    if (rdist != -1)
    {
        dist = rdist + 1;
        if (k - dist == 0)
        {
            cout << root->data;
        }
        else if (k > dist)
            printNodesAtK(root->left, k - dist - 1);
    }

    return;
}

int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    //1 2 4 6 -1 -1 7 -1 -1 5 8 -1 9 -1 -1 -1 3 10 -1 -1 11 12 14 -1 -1 -1 13 15 -1 -1 -1
    int dist=-1;
    printNodes(root,3,dist,3);

   

    return 0;
}