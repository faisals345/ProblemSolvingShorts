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
bool balanced=true;

int isBalanced(node* root){

    if(root==NULL){
        return 0;
    }

    int h1=isBalanced(root->left) ;
    int h2=isBalanced(root->right);

    if(abs(h1-h2)>1){
        balanced=false;
    }
    return max(h1,h2)+1;

}






int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    isBalanced(root);

    cout<<balanced<<endl;
   

    


    return 0;
}