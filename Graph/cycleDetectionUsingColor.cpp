//cycle detection in directed graph using color concept
#include <bits/stdc++.h>
using namespace std;


struct Graph{
    
    int V;
    
    vector<int> *adj;
    
    Graph(int n){
        V=n;
        adj = new vector<int>[n];
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    
};



void printGraph(vector<int> g[],int sz){

    for(int i=0;i<sz;i++){
        cout<<i<<"->";
       for(auto it:g[i]){
           cout<<it<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
   return;
 
}

bool dfs(vector<int> adj[],int node,int par,int color[]){

    color[node]=1;


    for(auto child:adj[node]){

        if(color[child]==1){
          return true;

        }
        else{
            if(color[child]==0 && dfs(adj,child,node,color)){
                return true;
            }

        }

       
    }
    color[node]=2;


    return false;
   
   



}









int main(){
    
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 4);

    int sz= 5;
    int color[5];
    memset(color,0,sizeof(color));

    cout<<dfs(g.adj,0,-1,color);
    
    
    
    
    
    return 0;
}