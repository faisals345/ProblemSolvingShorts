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