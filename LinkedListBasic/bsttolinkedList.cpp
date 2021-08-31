#include <bits/stdc++.h>
using namespace std;

struct TreeNode{

    int data;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};
//1 2 4 -1  -1 5 7 -1 -1 -1 3 -1 6 -1 -1

TreeNode* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    TreeNode *n=new TreeNode(d);
    n->left=buildTree();
    n->right=buildTree();

    return n;
}


void printPreorder_root_left_right(TreeNode* root){


    if(root==NULL){
        cout<<"NULL"<<" ";
        return;
    }
    cout<<root->data<<" ";

    printPreorder_root_left_right(root->left);
    
    printPreorder_root_left_right(root->right);



    return;
}

int NumberOfNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return NumberOfNodes(root->left) + NumberOfNodes(root->right) + 1;
}
vector<TreeNode *> ans;

vector<TreeNode *> helper(int n, int i, int j)
{

    // base case
    if (i == j)
    {

        vector<TreeNode *> t;
        TreeNode *singleNode = new TreeNode(i);
        t.push_back(singleNode);
        return t;
    }
    if (i > j)
    {
        vector<TreeNode *> t2;
        t2.push_back(NULL);
        return t2;
    }

    vector<TreeNode*> curr;

    for (int k = i; k <= j; k++)
    {
       
        vector<TreeNode*> v1 = helper(n, i, k - 1);
        vector<TreeNode*> v2 = helper(n, k + 1, j);

        for (auto it=v1.begin();it!=v1.end();it++)
        {
            for (auto itt=v2.begin();itt!=v2.end();itt++)
            {
                TreeNode *root = new TreeNode(k);
                root->left = *it;
                root->right = *itt;
                curr.push_back(root);
                // root->left=NULL;
                // root->right=NULL;
            }
        }
    }

    for (auto x : curr)
    {
        int d = NumberOfNodes(x);
        if (d == n)
        {
            ans.push_back(x);
        }
    }

    return curr;
}

int main(){

    // TreeNode* root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

        int n=3;
     vector<TreeNode*> t=  helper(n,1,n);

     for (auto x : ans)
       {
           printPreorder_root_left_right(x);
           cout<<endl;
       }  

     // printPreorder_root_left_right(root);

     return 0;
}