#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(int n,int a, int b){

    int x =  ceil((n*b*1.0)/(a+b));
    int y = n-x;

    int ans  = x*x*a  + y*y*b;

      x =  ((n*b*1.0)/(a+b));
      y = n-x;
     int ans2  = x*x*a  + y*y*b;
    cout<<min(ans,ans2)<<endl;
    return;




}


int32_t main(){

    int t;
    cin>>t;

while(t--){

    int N;
    int A,B;

    cin>>N>>A>>B;
    solve(N,A,B);



}

  





    return 0;
}