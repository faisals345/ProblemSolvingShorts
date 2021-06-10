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

void levelOrder(node * root)
{
        queue<node*> q;
        q.push(root);
        q.push(NULL);


        while(!q.empty())
            {   
                node * temp = q.front();
                q.pop();


                if(temp==NULL){
                    if(q.empty()){
                        return;
                    }
                    cout<<endl;
                    q.push(NULL);

                }
                else{

                    cout<<temp->data<<" ";

                    if(temp->left!=NULL){
                        q.push(temp->left);
                    }
                    if(temp->right!=NULL){
                        q.push(temp->right);
                    }
                }




            }







}



int main(){

    node* root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    



    //level order print;
    levelOrder(root);



    return 0;
}