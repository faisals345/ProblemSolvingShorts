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
void findMinAndMax(node* root,int * min_d,int * max_d,int hd){
    if(root==NULL){
        return ;
    }

    if(hd<*min_d){
        *min_d=hd;
    }else if(hd>*max_d){
        *max_d=hd;
    }

    findMinAndMax(root->left,min_d,max_d,hd-1);
    findMinAndMax(root->right,min_d,max_d,hd+1);

    return;

}

void printVerticalOrder(node* root,int line_no,int hd){

    if(root==NULL){
        return;
    }
    if(line_no==hd){
        cout<<root->data<<" ";
    }
    printVerticalOrder(root->left,line_no,hd-1);
    printVerticalOrder(root->right,line_no,hd+1);

    return;



}

void findVerticalOrder(node * root){

    int min_d=0,max_d=0,line_no=0;

    findMinAndMax(root,&min_d,&max_d,0);

    for(int i=min_d;i<=max_d;i++){
        printVerticalOrder(root,i,0);
        cout<<endl;
    }






}





int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    int min_d=0,max_d=0;
    findVerticalOrder(root);

  
  
    
    
   

    


    return 0;
}