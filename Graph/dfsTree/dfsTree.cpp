// its is one of the most important concept in entire graph
// it will be used to solve so many problems
// these red edges are called back edges
// back edge-> an edge  that is pointing backwards
//No matter where you start dfs , if there is cycle 
// ther will be back edges
//If we remove back edges from the graph, it becomes tree
// so thats why it is called a dfs tree
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

vector<int> gr[N];
int vis[N];

void dfs(int cur,int par){
    cout<<cur<<endl;
    vis[cur]=true;

    for(auto child:gr[cur]){
        if(!vis[child]){
            dfs(child,cur);
        }
        else{
            if(child!=par){
                cout<<"this is back edge"<<child<<"->"<<cur<<endl;
            }

        }
    }
    return;
 
}

int main(){

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }

    




}