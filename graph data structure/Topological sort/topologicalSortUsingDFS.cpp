#include <bits/stdc++.h>
using namespace std;

struct Graph{

    int V;
    list<int> *l;

    

     Graph(int V){

        this->V=V;
        l= new list<int>[V+1];

    }

    void addEdge(int x,int y){
        l[x].push_back(y);
    }


    void topologicalSortUsingDFS(bool visited[],int node,queue<int> &ans){

        visited[node]=true;

        for(auto child:l[node]){

            if(visited[child]==false){
                topologicalSortUsingDFS(visited,child,ans);
            }
        }

        ans.push(node);


        return;
       
      


          
    }






};


int main(){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(2,4);
     g.addEdge(3,5);
    g.addEdge(2,5);
    

    bool visited[6];
   


    for(int i=0;i<=5;i++){
        visited[i]=false;
    }

    queue<int> ans;
    
    g.topologicalSortUsingDFS(visited,0,ans);

   while(!ans.empty()){
       cout<<ans.front();
       ans.pop();
   }




    return 0;
}