#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> ar[],int x,int y){
    ar[x].push_back(y);
    ar[y].push_back(x);
}

void printGraph(vector<int> ar[],int V){
    for(int i=0;i<V;i++){
        cout<<i<<" -->";
        for(int x:ar[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void bfs__(vector<int> ar[],int V,int src){

    map<int,pair<bool,int>> visited;
    queue<int> q;
    q.push(src);
    visited[src]=make_pair(true,0);

    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        cout<<node<<" "<<visited[node].second<<endl;

        for(auto nbr : ar[node]){
            if(visited[nbr].first==false){
                visited[nbr].first=true;
                visited[nbr].second=visited[node].second+1;
                q.push(nbr);
            }
        }

    }



}

void dfs__(vector<int> ar[],int node,map<int,bool> &visited){

    visited[node]=true;
    cout<<node<<" ";

    for(int nbr:ar[node]){
        if(visited[nbr]==false){
            dfs__(ar,nbr,visited);
        }
    }

}

void dfsHelper(vector<int> ar[],int V,int src){
    map<int,bool> visited;
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    visited[src]=true;
  
    dfs__(ar,src,visited);

    for(int x=0;x<V;x++){
        if(!visited[x]){
            dfs__(ar,x,visited);
        }
    }

}




int main(){

   vector<int> graph[6];
   addEdge(graph,0,1);
   addEdge(graph,1,2);
   addEdge(graph,2,3);
   addEdge(graph,3,0);
   addEdge(graph,3,4);
   addEdge(graph,4,5);
  // printGraph(graph,6);
  //bfs__(graph,6,1);
  dfsHelper(graph,6,1);









    return 0;
}