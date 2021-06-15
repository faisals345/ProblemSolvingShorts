#include <bits/stdc++.h>
using namespace std;


template <typename T>

struct graph{

    int v;

    map<T,list<T>> mp;

    graph(T vertex){
        v=vertex;
    }

    void addEdge(T x,T y){
        mp[x].push_back(y);
        mp[y].push_back(x);
       
    }

    void printNode(){
        for(auto t : mp){
            cout<<t.first<<" -->";
            for(auto x:t.second){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        
    }

  

   

void bfs(T src){

    map<T,int> visited;
    queue<T> q;

    q.push(src);
  
    visited[src]=true;

    while(!q.empty()){
        T node = q.front();
        cout<<node<<" ";
        q.pop();

        for(int nbr : mp[node]){
            if(visited[nbr]==false){
                q.push(nbr);
                visited[nbr]=true;
            }
        }
    }

    

}


};





int main(){

     graph<int> g(6) ;
     g.addEdge(2,1);
     g.addEdge(1,0);
     g.addEdge(3,0);
     g.addEdge(2,3);
     g.addEdge(4,3);
     g.addEdge(4,5);

    //  g.printNode();
    g.bfs(1);








    return 0;
}