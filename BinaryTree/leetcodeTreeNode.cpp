#include <bits/stdc++.h>
using namespace std;

struct node{

    int val;
    node* left;
    node* right;


    node(int d){
        val=d;
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

void preorder(node* root){


    if(root==NULL){
        cout<<"null ";
        return;
    }

     cout<<root->val<<" ";

    preorder(root->left);
   
    preorder(root->right);



    return;
}





  
   map<int,vector<node*>> dp;
    
    void init(){
        
        node* t = new node(0);
        dp[1].push_back(t);
        
        node* t2 = new node(0);
        t2->left= new node(0);
        t2->right=new node(0);
        dp[3].push_back(t2);
        return;
    }
    
    
  
    
    
    vector<node*> helper(int n){
        
        if(dp.count(n)!=0){
            
            return dp[n];
        }
        
          vector<node*> l,r;
        
       
        
       
        
        for(int i=1;i<n;i+=2){
           
            
           
            
              l = helper(i);
       
            
              r = helper(n-i-1);
        
            
            for(auto x:l){
                
                
                for(auto y:r){ 
                      node* root = new node(0);
                    
                    root->left=x;
                    
                    root->right=y;
                     dp[n].push_back(root);
                     
                   
                    
                }
            
               
            
            }
       
            
        }
        
        return dp[n];
        
        
    
        
    }
    
   
     


int main(){

    int n=7;

        init();
        
       vector<node*> ans=helper(n);
       for(auto x:dp[n]){
           preorder(x);
           cout<<endl;
       }

       cout<<endl;





    return 0;
}