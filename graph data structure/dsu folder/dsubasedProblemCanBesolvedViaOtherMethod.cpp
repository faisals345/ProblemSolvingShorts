#include <bits/stdc++.h>

using namespace std;

struct Graph{
    
    int V;
    list<pair<int,int>> l;
    Graph(int V){
        this->V=V;
    
    }

    void addedge(int x ,int y){
        l.push_back(make_pair(x,y));
    }

    int findSet(int i,int parent[]){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]=findSet(parent[i],parent);  // parent[i]=findSet(parent[i],parent)
    }                                                //this is called path compression           

    void union_set(int a,int b,int parent[],int rank[]){
        int s1 = findSet(a,parent);
        int s2 = findSet(b,parent);

        if(s1!=s2){
            if(rank[s1]<rank[s2])
               {  parent[s1]=s2;
                  rank[s2]+=rank[s1];
               }
               else{
                   parent[s2]=s1;
                   rank[s1]+=rank[s2];

               }
        }
    }

    int journeyToMoon(){
        int *parent = new int[V];
        int *rank = new int[V];

        for(int i=0;i<V;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        int ans=0;

        for(auto paair:l){
            int s1 = findSet(paair.first,parent);
            int s2 = findSet(paair.second,parent);

            if(s1==s2){
                continue;
            }
            
            union_set(s1,s2,parent,rank);
            
        }

        for(int i=0;i<V;i++){

            int s1 = findSet(i,parent);
            
          
            ans+=V - rank[s1];
        }
        return ans/2;

        delete [] parent;
        
    }






};





int main(){

    Graph g(5);
    g.addedge(0,1);
    // g.addedge(1,2);
    // g.addedge(3,4);
    g.addedge(2,3);
    g.addedge(2,4);
    cout<<g.journeyToMoon()<<endl;



    return 0;
}