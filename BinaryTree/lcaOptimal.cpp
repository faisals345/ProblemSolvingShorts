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

node* lcaOptimalFind(node* root,int n1,int n2){

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    node* lh = lcaOptimalFind(root->left,n1,n2);
    node *rh = lcaOptimalFind(root->right,n1,n2);

    if(lh!=NULL && rh!=NULL){
        return root;
    }

    if(lh!=NULL){
        return lh;
    }
    else{
        return rh;
    }
}






int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    node * lca = lcaOptimalFind(root,5,6);
    cout<<lca->data<<endl;
  
    
    
   

    


    return 0;
}