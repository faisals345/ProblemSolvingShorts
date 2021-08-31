#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<long long,long long>>> &ar,long long  x,long long  y,long long dist){
    ar[x].push_back(make_pair(y,dist));
    ar[y].push_back(make_pair(x,dist));
}

long long res=0;

long long dfs__(vector<vector<pair<long long,long long>>> &ar,long long src,unordered_map<long long,bool> &visited,long long V){

    visited[src]=true;
    long long subchild=0;

        for(auto chld : ar[src]){

            if(visited[chld.first]==false){
                long long temp = dfs__(ar,chld.first,visited,V);
                subchild+=temp;
                res+=2*min(temp,V-temp)*chld.second;
            }
        }

        

        return subchild+1;



}








int main(){

    long long t;
    cin>>t;
    long long k=1;

while(t--){ 
    long long  n;
    cin>>n;
    vector<vector<pair<long long,long long>>> graph(n+1,vector<pair<long long,long long>>());

    long long V=n;
    while(V-->1){
        long long x,y,dist;
        cin>>x>>y>>dist;
        addEdge(graph,x,y,dist);

    }
    unordered_map<long long,bool> visited;

    for(long long i=1;i<=n;i++){
        visited[i]=false;
    }

  
   long long total_nodes= dfs__(graph,1,visited,n);
   cout<<"Case "<<k++<<"#: "<<res<<endl;
   res=0;
   graph.clear();
   visited.clear();
 }  
    return 0;
}