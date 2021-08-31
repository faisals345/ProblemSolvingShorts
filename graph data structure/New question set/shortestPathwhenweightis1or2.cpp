#include <bits/stdc++.h>

using namespace std;

struct Graph{

    int V;
    list<int> *l;

    Graph(int ver){
        this->V=ver;
        l = new list<int>[2*V];
    }

    void addEdge(int x, int y,int w){


        if(w==2){
            l[x].push_back(x+V);
            l[x+V].push_back(y);
        }else{
            l[x].push_back(y);
        }
    }

   

};

void printPath(int parent[],int src,int des,int ver){

    if(parent[src]==-1){
        cout<<"shortest path from src to des is"<< src<<" ";
        return ;
    }

    printPath(parent,parent[src],des,ver);

   if(src<ver) 
    cout<<src<<" ";

    return;




}


void shortestPath(int src,int des,Graph g,int ver){


    queue<int> q;
    q.push(src);
    int parent[2*ver];
    bool visited[2*ver];

    for(int i=0;i<2*ver;i++){
        visited[i]=false;
        parent[i]=-1;
    }

   visited[src]=true;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        if(node==des){
            printPath(parent,node,des,ver);
            return;
        }

        for(auto child : g.l[node]){


            if(visited[child]==false){

                visited[child]=true;
                q.push(child);
                parent[child]=node;

            }
        }

    }






}



int main()
{


    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 3, 2);

    shortestPath(0,3,g,4);



 
    return 0;
}
