#include <bits/stdc++.h>
using namespace std;

#define int long long

void addEdge(list<int> adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

// void dfs(list<int> adj[],int node,bool visited[]){


//     visited[node]=true;
//     cout<<node<<" ";

//     for(auto child:adj[node]){
//         if(visited[child]==false){
//             dfs(adj,child,visited);
//         }
//     }
//     return;

// }

int dfs(list<int> adj[],bool visited[],int node){

    visited[node]=true;
    int maxHeight=0;
    int temp=0;

    for(int x:adj[node]){
        if(visited[x]==false){ 
            temp=dfs(adj,visited,x);
            maxHeight= max(maxHeight,temp);
       }
    }

    return maxHeight+1;


}

void dfs_helper(list<int> adj[],int src,int V){

    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
   cout<<"height->"<< dfs(adj,visited,src);

}




int32_t main(){

    int V;
    cin>>V;

    list<int> adj[V];   //array of lists
    int E;
    cin>>E;
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        addEdge(adj,x,y);
    }

    // for(int i=0;i<V;i++){
    //     cout<<i<<" -->";
    //     for(int x:adj[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    dfs_helper(adj,1,V);

 return 0;

}