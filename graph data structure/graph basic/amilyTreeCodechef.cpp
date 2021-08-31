#include <bits/stdc++.h>
using namespace std;

#define int long long

void addEdge(vector<vector<int>> &ar,int  x,int  y){
    ar[x].push_back(y);
    ar[y].push_back(x);
}

int res=0;
int W[100002];              

pair<int,int> dfs__(vector<vector<int>> &ar,int src,unordered_map<int,bool> &visited){

    visited[src]=true;
    int min_curr=W[src],max_curr=W[src];
    

        for(auto chld : ar[src]){

            if(visited[chld]==false){
                pair<int,int> desc=dfs__(ar,chld,visited);
                min_curr=min(min_curr,desc.first);
                max_curr=max(max_curr,desc.second);
            }

            
        }

        res = max({res,W[src] - min_curr,max_curr-W[src]});
        

        

        return {min_curr,max_curr};



}

 






int32_t main(){

    int n;
    cin>>n;

    

    for(int i=1;i<=n;i++){
        cin>>W[i];
    }

    vector<vector<int>> g(n+1,vector<int>());
    int root=0;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==-1){
            root=i;
            continue;
        }
        addEdge(g,x,i);
    }

    unordered_map<int,bool> visited;
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }

    dfs__(g,root,visited);
    cout<<res<<endl;

   

    return 0;
}