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

int maxLevel=0;

void leftView(node* root,int currLevel){

    if(root==NULL){
        return;
    }

    if(currLevel>maxLevel){
        cout<<root->data<<" ";
        maxLevel=currLevel;
    }
    leftView(root->left,currLevel+1);
    leftView(root->right,currLevel+1);
    return;



}



int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    leftView(root,1);



    return 0;
}