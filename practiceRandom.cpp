// connected components in graph kosaraju algorithm
// A strongly connected-> 
//component (SCC) of a directed graph is a maximal strongly connected subgraph.
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

void reverseEdge(vector<int> g[],vector<int> revG[],int sz){
    
   for(int i=0;i<sz;i++){
       for(auto it:g[i]){
           revG[it].push_back(i);
       }
   }

   return ;
    
}

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

void dfs(vector<int> adj[],bool visited[],int sz,int node,stack<int> &st){

    visited[node]=true;


    for(auto child:adj[node]){
        if(!visited[child]){
            dfs(adj,visited,sz,child,st);
        }
    }


    st.push(node);

    return;



}

void dfs2(vector<int> revAdj[],bool visited[],int sz,int node){


        visited[node]=true;


        for(auto child:revAdj[node]){
            if(!visited[child]){
                dfs2(revAdj,visited,sz,child);
            }
        }



}








int main(){
    
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    Graph revG(5);
    int sz=5;
    
 reverseEdge(g.adj,revG.adj,sz);
//  printGraph(g.adj,sz);
//  printGraph(revG.adj,sz);
    
    //kosarju algo 
    // first do simple dfs and have stack and nodes in order
    // then do dfs according to this order only

    bool visited[sz];
    memset(visited,false,sizeof(visited));
    stack<int> st;

    for(int i=0;i<sz;i++){
            if(!visited[i]){
                dfs(g.adj,visited,sz,i,st);
            }
    }

    memset(visited,false,sizeof(visited));
    int count=0;

    while(st.empty()==false){
        if(visited[st.top()]==false){
            dfs2(revG.adj,visited,sz,st.top());
            
            count++;
        }
        st.pop();
    }

    cout<<count<<endl;


    

    
    
    
    
    
    
    
    return 0;
}