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

    bool dfsToDetectACycle(bool stArray[],int node,bool visited[]){

        visited[node]=true;
        stArray[node]=true;

        for(int child:l[node]){

            if(stArray[child]==true){
                return true;
            }
            else if(visited[child]==false){
                bool isCycle = dfsToDetectACycle(stArray,child,visited);
                if(isCycle){
                    return true;
                }

            }

        }
        stArray[node]=false;
        return false;


    }







};


int main(){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(0,5);

    bool visited[6];
    bool reArray[6];

    for(int i=0;i<6;i++){
        visited[i]=reArray[i]=false;
    }

    
    cout<<g.dfsToDetectACycle(reArray,0,visited);




    return 0;
}