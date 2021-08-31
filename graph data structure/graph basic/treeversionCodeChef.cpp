#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> adj;
vector<int> w;





struct trio{
    int inversion,ones,zeroes;
};

bool comp(trio &a,trio &b){
    return a.ones*b.zeroes<a.zeroes*b.ones;
}


trio dfs(int cur=1,int pr=0){

    trio curr;
    curr.inversion=0,curr.ones=0,curr.zeroes=0;

    vector<trio> subtre;

    for(auto child : adj[cur]){
        if(child==pr){
            continue;
        }
        subtre.push_back(dfs(child,cur));
    }

    sort(subtre.begin(),subtre.end(),comp);

   if(w[cur]==1){
       curr.ones++;
   }else{
       curr.zeroes++;
   }

    for(auto &x: subtre){
        curr.inversion+=x.inversion ;
        curr.inversion +=(curr.ones)*(x.zeroes);
        curr.zeroes+=x.zeroes;
        curr.ones+=x.ones;
    }
    return curr;

    
}










int32_t main(){
    int t;
    cin>>t;
   while(t--){  

        int n;
        cin>>n;
        adj.clear();
        adj.resize(n+1);
        w.resize(n+1);
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }

        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      
        }

        trio ans = dfs();

        cout<<ans.inversion<<endl;

        
   
   }
   

    

    

 return 0;

} 