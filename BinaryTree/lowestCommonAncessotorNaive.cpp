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

vector<int> vec1,vec2;

int findPath1(node  *root,int n){

    if(root==NULL){
        return 0;
    }

    vec1.push_back(root->data);

    if(root->data==n){
        
        return -1;
    }

   int t1=findPath1(root->left,n);

   if(t1==-1){
       return -1;
   }
    int t2=findPath1(root->right,n);
   if(t2==-1){
       return -1;
   }
    
    vec1.pop_back();
    return 0;




}
int findPath2(node  *root,int n2){

    if(root==NULL){
        return 0;
    }
    vec2.push_back(root->data);

    if(root->data==n2){
    
        return -1;
    }

   int t3=findPath2(root->left,n2);
   
   if(t3==-1){
       return -1;
   }
    int t4=findPath2(root->right,n2);
   if(t4==-1){
       return -1;
   }
    
    vec2.pop_back();
    return 0;




}






int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

   int d1= findPath1(root,5);
  int d2=  findPath2(root,4);
    int ans=0;

    for(int i=0;i<vec1.size() && i<vec2.size();i++){
        if(vec1[i]==vec2[i]){
            ans=vec1[i];
        }
        else{
            break;
        }
    }
  

    
    cout<<d1<<" "<<d2<<endl;
    cout<<ans<<endl;


  
    
    
   

    


    return 0;
}