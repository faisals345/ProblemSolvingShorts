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


node * insertBst(node *root,int key){

    if(root==NULL){
        node * nNode = new node(key);
        return nNode;
    }

    if(root->data>key){
        root->left= insertBst(root->left,key);
    }

   if(root->data<key){
        root->right= insertBst(root->right,key);
    }    

    return root;
}



void printInorder(node * root){
    if(root==NULL){
        return ;

    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

int main()
{

    node * root = NULL;
    root=insertBst(root,2);
    root=insertBst(root,3);
    root=insertBst(root,4);
    root=insertBst(root,5);
    root=insertBst(root,15);
    root=insertBst(root,155);
    root=insertBst(root,45);
    root=insertBst(root,1);
    root=insertBst(root,7);
    root=insertBst(root,8);

    
    printInorder(root);

  

    return 0;
}