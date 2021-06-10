#include <bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;


    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};
//1 2 4 -1  -1 5 7 -1 -1 -1 3 -1 6 -1 -1

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node *n=new node(d);
    n->left=buildTree();
    n->right=buildTree();

    return n;
}

void printInorder_left_root_right(node* root){


    if(root==NULL){
        return;
    }

    printInorder_left_root_right(root->left);
    cout<<root->data<<" ";
    printInorder_left_root_right(root->right);



    return;
}

void printPreorder_root_left_right(node* root){


    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    printPreorder_root_left_right(root->left);
    
    printPreorder_root_left_right(root->right);



    return;
}

void printPostorder_left_right_root(node* root){


    if(root==NULL){
        return;
    }
    

    printPostorder_left_right_root(root->left);
    
    printPostorder_left_right_root(root->right);

    cout<<root->data<<" ";



    return;
}



int main(){

    node* root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    //InorderPrint
    printInorder_left_root_right(root);
    cout<<endl;

    //preOrder
    printPreorder_root_left_right(root);
    cout<<endl;



    //postorder
    printPostorder_left_right_root(root);
    cout<<endl;




    //level order print;



    return 0;
}