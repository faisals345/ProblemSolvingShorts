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
 
const int M =1e9+7;
const int N = 1e6+7;

int preSum[N];

bool canDivide(int arr[],int n,int val){

    int i1 = lower_bound(arr,arr+n,val)-arr;
    int i2 = upper_bound(arr,arr+n,val)-arr;

    if(i1==0 || i2>n-1){
        return false;
    }
    int sum1 = preSum[i1-1];
    int sum2=preSum[n-1]-preSum[i2-1];

    if(sum1==sum2){
        return true;
    }
    return false;

}




int32_t main(){


    int n;
    cin>>n;

    int maxEle=INT_MIN;

    int arr[n];
    rep(i,0,n){
        cin>>arr[i];
        maxEle=max(maxEle,arr[i]);
    }

    
    preSum[0]=arr[0];
    rep(i,1,n){
        preSum[i]+=preSum[i-1]+arr[i];
    }

  

    rep(i,1,maxEle){
        if(canDivide(arr,n,i)){
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;








  





    return 0;
}