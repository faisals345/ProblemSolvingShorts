#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i,ini,n) for(ll i=ini;i<(int)n;i++)
#define all(x) x.begin(),x.end()

#define tc   int tt; cin>>tt; while(tt--)

#define endl "\n"
#define inf INT_MAX
#define ninf INT_MIN
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265358979323846264
 
const ll M =1e9+7;
const int N = 1e6+7;

ld A[N],B[N];
ld k;
int n,col;


bool solve(ld val){
    ld sum=0;
    rep(i,0,n){
        sum+=A[i]/(B[i]+val);
    }
    if(sum<=k){
        return true;
    }
    else
      return false;
}


int main(){


    
    cin>>n>>col;

    ld minEle=inf;



    for(int i=0;i<n;i++){
        cin>>A[i]>>B[i];
        minEle=min(minEle,B[i]);
    }
    cin>>k;

    ld low = -minEle + 1e-7;
    ld high = 1e18;
    ld r = 0.0000001;
    ld res=0.0000000;

    rep(i,0,200){
        ld mid = (low+high)/2;
        if(solve(mid)){
            res=mid;high = mid+r;

        }
        else{
            low = mid-r;
        }
    }

    

    


 

    cout<<fixed;
    cout.precision(7);
    cout<<res<<endl;






    return 0;
}