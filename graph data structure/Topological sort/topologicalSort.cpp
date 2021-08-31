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


    void topologicalSortUsingBFS(queue<int> q,int inDegree[]){
       
       
        // int node = q.front();
        // cout<<node<<" ";
        // q.pop();
        // visited[node]=true;

        while(!q.empty()){

            int node = q.front();
            
            q.pop();
            cout<<node<<" ";

            for(auto child: l[node]){
               
                inDegree[child]--;
              
                if(inDegree[child]==0){
                    q.push(child);
                }

            }

        }
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
    int inDegre[6]={};

    for(int i=0;i<=5;i++){
        for(auto x: g.l[i]){
            inDegre[x]++;
        }
    }

    queue<int> q;
    for(int i=0;i<=5;i++){
        if(inDegre[i]==0){
            q.push(i);
        }
    }

    for(int i=0;i<=5;i++){
        visited[i]=false;
    }
    g.topologicalSortUsingBFS(q,inDegre);
   




    return 0;
}