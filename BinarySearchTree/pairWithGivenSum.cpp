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


node * insertBst(node *root,int key){

    if(root==NULL){
        node * nnode = new node(key);
        return nnode;
    }

    if(root->data>key){
        root->left= insertBst(root->left,key);
    }

   if(root->data<key){
        root->right= insertBst(root->right,key);
    }    

    return root;
}



void printInorder(node * root){
    if(root==NULL){
        return ;

    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}




void iReverseInorder(stack<node*> &st){
        
        node * p = st.top();
        
     
        st.pop();
        if(p->left!=NULL){
            st.push(p->left);
            p=p->left;
            while(p->right!=NULL){
                st.push(p->right);
                p=p->right;
            }
        }
        return;
        
        
        
    }
    
    void iInorder(stack<node*> &st){
        
         node * p = st.top();
        
        
        st.pop();
        if(p->right!=NULL){
            st.push(p->right);
            p=p->right;
            while(p->left!=NULL){
                st.push(p->left);
                p=p->left;
            }
        }
        
        return;
        
    
    }
    
    int isPairPresent(struct node *root, int target)
    {
   
    
        node * i=root,*j=root;
        stack<node*> st1,st2;
    
    
        
        while(i!=NULL){
            st1.push(i);
          //  visited.insert(i);
            i=i->left;
        }
        
        while(j!=NULL){
            st2.push(j);
           // visited.insert(j);
            j=j->right;
        }
        
        while(st1.top()->data < st2.top()->data && st1.empty()==false && st2.empty()==false ){
            
            i=st1.top();
            j=st2.top();
            
            if(i->data + j->data==target){
                cout<<i->data<<" "<<j->data;
                return 1;
                
                
            }else if(i->data + j->data<target){
                iInorder(st1);
                
                
            }else{
                iReverseInorder(st2);
            
            }
      
        }
        return 0;
        
    }
    
    

int main()
{

    node * root = NULL;
    root=insertBst(root,2);
    root=insertBst(root,3);
    root=insertBst(root,4);
    root=insertBst(root,5);
    root=insertBst(root,15);
    root=insertBst(root,155);
    root=insertBst(root,45);
    root=insertBst(root,1);
    root=insertBst(root,7);
    root=insertBst(root,8);

    
    printInorder(root);

    cout<<isPairPresent(root,23);

  

    return 0;
}