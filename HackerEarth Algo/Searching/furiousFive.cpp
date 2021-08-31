#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long

#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
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
 
const int M =1e9+7;
const int N = 1e6+7;

int calFX(int num){

    int sum=0;
    while(num){

        sum+=num/5;
        num/=5;
    }
    return sum;

}

bool solve(int x,int k){

    int fx = calFX(x);
    if(fx>=k){
        return true;
    }
    return false;

}




int32_t main(){

    //precomputation is required?? not at all


    tc{
        int n;
        cin>>n;

        int l=1,h=1e18;
        int ans=-1;
        while(l<=h){
            int mid =(l+h)/2;

            if(solve(mid,n)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        cout<<ans<<endl;
        
    }






  





    return 0;
}