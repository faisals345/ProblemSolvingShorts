//also known as graph coloring 
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

bool dfs(vector<int> adj[],int node,int par,int color[],int col){

    color[node]=col;


    for(auto child:adj[node]){

        if(color[child]==0){
          bool isCycle = dfs(adj,child,node,color,3-col);
          if(isCycle){
              return true;
          }

        }
        else{
            if(child!=par && color[node]==color[child]){
                return true;
            }

        }

       
    }
    


    return false;
   
   



}









int main(){
    
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);

    int sz= 5;
    int color[5];
    memset(color,0,sizeof(color));

    cout<<dfs(g.adj,0,-1,color,1);
    
    
    
    
    
    return 0;
}