#include <bits/stdc++.h>
using namespace std;

#define int long long

void addEdge(list<int> adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}







void dfs(list<int> adj[],bool visited[],int node,int par,vector<int> &count,vector<int> &dist){

    visited[node]=true;
    count[node]=0;
    dist[node]=0;
  

    for(int child:adj[node]){
        if(visited[child]==false){ 
            dfs(adj,visited,child,node,count,dist);

            count[node]+=count[child];
            dist[node]+=dist[child]+count[child];
       }
    }

    count[node]+=1;

    return;
}

void dfsPostOrder(list<int> adj[],int node,int par,int V,bool visited[],vector<int> &count,vector<int> &dist){

    visited[node]=true;
    if(node!=par)
     dist[node]=dist[par]- count[node] + V -count[node];

    for(auto child:adj[node]){
        if(visited[child]==false){
            dfsPostOrder(adj,child,node,V,visited,count,dist);
        }
    }

    return;




}








int32_t main(){

    int V;
    cin>>V;
    vector<int> dist(V,0),count(V,0);

     bool visited[V];

    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    
   

    list<int> adj[V];   //array of lists
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,4);

    dfs(adj,visited,1,-1,count,dist);

     for(int i=0;i<V;i++){
        visited[i]=false;
    }

    dfsPostOrder(adj,1,1,V,visited,count,dist);

    for(int i=0;i<V;i++){
        cout<<"count["<<i<<"]="<<count[i]<<endl;
        cout<<"dist["<<i<<"]= "<<dist[i]<<endl;
        cout<<endl;
    }
   




    

 return 0;

}