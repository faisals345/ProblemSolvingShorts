#include <bits/stdc++.h>
using namespace std;


int main(){

    int N;
    cin>>N;
    set<int> s1,s2;

    int maxS1=INT_MIN,minS1,maxS2=INT_MIN,minS2;

    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        s1.insert(t);
        maxS1=max(maxS1,t);
    }
    int M;
    cin>>M;

    for(int i=0;i<M;i++){
        int t;
        cin>>t;
        s2.insert(t);
        maxS2=max(maxS2,t);
    }

    int diff = abs(maxS1-maxS2);
    set<int> ans;
    map<int,bool> visited;
    map<int,bool> flag;
    for(auto ele:s2){
        visited[ele]=false;
        
    }
    for(int i=1;i<=diff;i++){
        flag[i]=false;
    }

    for(auto x: s1){
        for(int j=1;j<=diff;j++){
            if(s2.find(x+j)!=s2.end() && visited[x+j]==false && flag[j]==false){
                ans.insert(j);
                visited[x+j]=true;
            }
            else if(s2.find(x+j)==s2.end()){
                auto it =ans.find(j);
                flag[j]=true;
                if(it==ans.end()){
                    continue;
                }
                ans.erase(it);
                

            }
        }
    }

    for(auto x:ans){
        cout<<x<<" ";
    }






    return 0;
}