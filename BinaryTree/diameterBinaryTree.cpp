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
int ans=0;

int maxDiameter(node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int h1 = maxDiameter(root->left);
    int h2 = maxDiameter(root->right);

    if (h1 + h2 + 1 > ans)
    {
        ans = h1 + h2 + 1;
    }
    return max(h1, h2) + 1;
}

int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    maxDiameter(root);
    cout<<ans<<endl;
    
    
    
   

    


    return 0;
}