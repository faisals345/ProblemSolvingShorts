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
struct entry{
    int data;
    entry* next;
    entry(int data){
        this->data=data;
        next=NULL;
    }

};

struct headNode{
    int hd;
   struct  entry* list;
    headNode *left,*right;

    headNode(int hd){
        this->hd=hd;
        left=NULL;
        right=NULL;
        this->list=NULL;
        
    }
};

void buildVerticalOrder(node * root, headNode * &head){

    entry* e = new entry(root->data);
    e->next=head->list;
    head->list=e;

    if(root->left!=NULL){
        if(head->left==NULL){

            head->left=new headNode(head->hd-1);
            head->left->right=head;

        }
        buildVerticalOrder(root->left,head->left);
    }

     if(root->right!=NULL){
        if(head->right==NULL){

            head->right=new headNode(head->hd-1);
            head->right->left=head;

            
        }
        buildVerticalOrder(root->right,head->right);
    }




}

void printList(headNode *head){

    entry * curr=head->list;

    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;

}

void printVerticalDll(headNode * head){

    

    headNode * temp=head;
    while(head!=NULL){
        printList(head);
    //    cout<<head->list->data<<endl;
         head=head->left;
    }
    head=temp;
    cout<<"right"<<endl;


    while(head!=NULL){
        printList(head);
        //cout<<head->list->data<<endl;
        head=head->right;
    }

    return;

}







int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    int min_d=0,max_d=0;

    headNode* head = new headNode(0);
    buildVerticalOrder(root,head);
    printVerticalDll(head);

    

  
  
    
    
   

    


    return 0;
}