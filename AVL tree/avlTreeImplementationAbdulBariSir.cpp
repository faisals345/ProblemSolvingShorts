#include <bits/stdc++.h>

using namespace std;





struct node
{

    int data;
    node *left;
    int height;
    node *right;

    node(int d)
    {
        data = d;
        height=1;
        left = NULL;
        right = NULL;
    }
};



int nodeHeight(node * root){

    if(root==NULL){
        return 0;
    }

    int lh = root->left?root->left->height:0;
    int rh = root->right?root->right->height:0;
    return max(lh,rh)+1;
}

int balanceF(node * root){
    return nodeHeight(root->left)- nodeHeight(root->right);
}

node * llRotation(node * root){

    node *p= root;
    node *rc = root->left;
    node * rcc=root->left->right;

    p->left=rcc;
    rc->right=p;
    p->height=nodeHeight(p);
    rc->height=nodeHeight(rc);
    return rc;

}

node * lrRotation(node * root){

    node *p= root;
    node *plc = root->left;
    node * plrc=root->left->right;
    node *tempC1= plrc->left;
    node *tempC2=plrc->right;

    plrc->left=plc;
    plrc->right=p;
    p->left=tempC2;
    plc->right=tempC1;
    p->height = nodeHeight(p);
    plc->height = nodeHeight(plc);
    plrc->height=nodeHeight(plrc);

    return plrc;

}

node * rrRotation(node * root){

    node *p= root;
    node *prc = root->right;
    node * prlc=prc->left;

    p->right=prlc;
    prc->left=p;
    p->height=nodeHeight(p);
    prc->height=nodeHeight(prc);
    return prc;

}

node * rlRotation(node * root){

    node *p= root;
    node *prc = root->right;
    node * prlc=prc->left;
    node *tempC1= prlc->left;
    node *tempC2=prlc->right;

    prlc->left=p;
    prlc->right=prc;
    p->right=tempC1;
    prc->left=tempC2;

     p->height = nodeHeight(p);
    prc->height = nodeHeight(prc);
    prlc->height=nodeHeight(prlc);



    return prlc;

}


node * insertInAvlTree(node * root,int key){
    if(root==NULL){
        node * nNode = new node(key);
        return nNode;
    }

    if(root->data>key){
        root->left = insertInAvlTree(root->left,key);
    }
    else if(root->data<key){
        root->right  = insertInAvlTree(root->right,key);
    }
    node *temp = NULL;

    if(balanceF(root)==2 && balanceF(root->left)==1){
        // left left rotation needed;
        temp = llRotation(root);
        return temp;

    }
    else if (balanceF(root)==2 && balanceF(root->left)==-1 ){
        //left right rotation required;
        temp=lrRotation(root);
        return temp;


    }
     else if (balanceF(root)==-2 && balanceF(root->right)==-1 ){
        //rightright rotation required;
        temp=rrRotation(root);
        return temp;


    }
     else if (balanceF(root)==-2 && balanceF(root->right)==1 ){
        //right left rotation required;
        temp=rlRotation(root);
        return temp;


    }
    return root;
    
}
void printPreorder(node * root){
    if(root==NULL){
        return ;

    }

    cout<<root->data<<" ";
    printPreorder(root->left);
   
    printPreorder(root->right);

}

int main()
{

    node * root = NULL;
    root=insertInAvlTree(root,5);
    root=insertInAvlTree(root,4);
    printPreorder(root);
    cout<<endl;
    root=insertInAvlTree(root,3);
    printPreorder(root);
    root= insertInAvlTree(root,25);
    root=insertInAvlTree(root,55);
    cout<<endl;
    printPreorder(root);
  
    
    

  

    return 0;
}