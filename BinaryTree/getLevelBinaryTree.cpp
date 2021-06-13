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

void findLevel(node * root,int key,int h,int &ans){
    if(root==NULL){
        return ;
    }
    
    if(root->data==key){
        ans=h;
        return;
    }
    findLevel(root->left,key,h+1,ans);
    findLevel(root->right,key,h+1,ans);
    return;
}






int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    int level1=0,level2=0;
    findLevel(root,2,0,level1);
    cout<<level1<<endl;
   

    


    return 0;
}