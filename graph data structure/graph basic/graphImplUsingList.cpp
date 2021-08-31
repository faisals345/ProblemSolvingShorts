#include <bits/stdc++.h>
using namespace std;


template <typename T>

struct graph{

    int v;

    list<T> *l;

    graph(T vertex){
        v=vertex;
        l = new list<T>[v];
    }

    void addEdge(T x,T y){
        l[x].push_back(y);
        l[y].push_back(x);
       
    }

    void printNode(){
        
        for(int i=0;i<v;i++){
            cout<<i<< " -->";
            for(int j:l[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }


        
        
    }




};

int main(){

     graph<int> g(5) ;
     g.addEdge(0,1);
     g.addEdge(4,1);
     g.addEdge(2,1);
     g.addEdge(3,4);
     g.addEdge(2,3);

     g.printNode();








    return 0;
}