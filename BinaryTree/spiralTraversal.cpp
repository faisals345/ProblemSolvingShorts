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

void spiralTreePrint(node *root){

    stack<node*> s1,s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty())
    { 
        while(s1.empty()==false){
            node*temp1= s1.top();
            cout<<temp1->data<<" ";
            s1.pop();
            if(temp1->left!=NULL){
                s2.push(temp1->left);
            }
            if(temp1->right!=NULL){
                s2.push(temp1->right);
            }
        }

        while(s2.empty()==false){

            node*temp2= s2.top();
            cout<<temp2->data<<" ";
            s2.pop();
            if(temp2->right!=NULL){
                s1.push(temp2->right);
            }
            if(temp2->left!=NULL){
                s1.push(temp2->left);
            }
        }

    }
    
    








    



}




int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    spiralTreePrint(root);

   
    
    
   

    


    return 0;
}