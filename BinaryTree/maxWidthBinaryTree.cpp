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

int maxWidth(node* root){

    if(root==NULL){
        return 0;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int maxTotal=0;
    int k=0;

    while(q.empty()==false){
        node* temp =q.front();
        
        if(temp==NULL){
            q.pop();
            if(q.empty()==true){
                return maxTotal;
            }
            maxTotal=max(maxTotal,k);
            k=0;
            q.push(NULL);

        }else{
            q.pop();
            k++;
            if(temp->left!=NULL)
               q.push(temp->left);

             if(temp->right!=NULL)
               q.push(temp->right);   

        }

    }
    return maxTotal;
    





}






int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    cout<<maxWidth(root)<<endl;
    
    
   

    


    return 0;
}