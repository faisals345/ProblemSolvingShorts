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

bool childrenSum(node* root){
    if(root==NULL){
        return true;
    }
    if(root->right==NULL && root->left==NULL)
        return true;
    int sum=0;



    if(root->left!=NULL){
        sum+=root->left->data;
    }
    if(root->right!=NULL){
        sum+=root->right->data;
    }



    return ( sum==root->data && childrenSum(root->left) && childrenSum(root->right));
    


    
}




int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
   cout<< childrenSum(root);

    


    return 0;
}