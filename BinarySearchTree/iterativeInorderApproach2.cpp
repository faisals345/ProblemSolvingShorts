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
        node * nnode = new node(key);
        return nnode;
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

void printIterative2(node * root){


    stack<node*> st;
    node * p = root;

    while(p || !st.empty()){

        if(p!=NULL){
            st.push(p);
            p=p->left;

        }else{
            p=st.top();
            st.pop();
            cout<<p->data<<" ";
            p=p->right;

        }
        
       

    }




}





    

int main()
{

    node * root = NULL;
    root=insertBst(root,25);
    root=insertBst(root,18);
    root = insertBst(root,45);
    root=insertBst(root,12);
    root = insertBst(root,25);
    root=insertBst(root,35);
    root = insertBst(root,55);
    root=insertBst(root,58);
    root = insertBst(root,5);

    printIterative2(root);


    
  

  

    return 0;
}