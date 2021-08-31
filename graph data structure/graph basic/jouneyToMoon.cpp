#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &ar,int  x,int  y){
    ar[x].push_back(y);
    ar[y].push_back(x);
}



int  bfs__(vector<vector<int>> &ar,int  src,map<int ,bool> &visited){

    
    queue<int > q;
    int  count=1;
    q.push(src);
    visited[src]=true;
    

    while(!q.empty()){
        
        int  node = q.front();
        q.pop();
        

        for(auto nbr : ar[node]){
            if(visited[nbr]==false  ){
                visited[nbr]=true;
                count++;
                q.push(nbr);
            }
        }

    }
    return count;



}

void bfsHelper(vector<vector<int>> &ar,int  V){

    map<int ,bool> visited;

    for(int  i=0;i<V;i++){
        visited[i]=false;
    }


    int  ans=1;
    long long  final_res=(1ll*V*(V-1))/2;
   // cout<<final_res<<endl;
    
    
    for(int  i=0;i<V;i++){

        if(visited[i]==false){

            ans=bfs__(ar,i,visited);
           
            if(ans!=1){
                final_res-=1ll*(ans*(ans-1))/2;
            }           
            
        }
       
        
        ans=1;

    }

    
    
    
    cout<< final_res<<endl;;

}





int  main(){

    int  m,n;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>());

    // for(int i=0;i<n;i++){
    //     graph[i].push_back(-1);
    // }

    while(m--){
        int  x,y;
        cin>>x>>y;
        addEdge(graph,x,y);

    }
    bfsHelper(graph,n);

    return 0;
}