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

int burnTree(node* root,int &dist,int leaf){

 // this problem is just finding longest path through one of the ancestors of the target node of burning point   
 // function return krega height max(lh,rh) + 1 and dist jo parameter me hai wo btayega ki target node se given common ancestor ka kitna distance hai


 if(root==NULL){
     return 0;
 }

 if(leaf==root->data){
     dist=0;
     return 1;
 }



 int ldist=-1,rdist=-1;
 int lh = burnTree(root->left,ldist,leaf);
 int rh = burnTree(root->right,rdist,leaf);

 if(ldist!=-1){
     dist=ldist+1;
     ans=max(ans,rh+ldist+1);
     

 }
 if(rdist!=-1){
     dist=rdist+1;
    ans=max(ans,lh+rdist+1);

 }

 return max(lh,rh)+1;


}




int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    int t = -1;
   int x= burnTree(root,t,7);
   cout<<ans<<endl;
   

    


    
   

    


    return 0;
}