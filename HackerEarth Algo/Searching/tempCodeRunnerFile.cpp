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


int arr[N];

void solve(int arr[],int n,int x){
      
    int curr_sum = 0, min_len = n + 1;
    int totalSum=0;
 
   
    int start = 0, end = 0;
    while (end < n) {
      
        while (curr_sum < x && end < n)
        {
            totalSum += arr[end];
            curr_sum += arr[end++];
            
        }

        while (curr_sum >= x && start < n) {
         
            if (end - start < min_len)
                min_len = end - start;
 
         
            curr_sum -= arr[start++];
        }
    }
    if(totalSum<x){
        cout<<-1<<endl;
    }
    else if(totalSum>=x && x==0){
        cout<<1<<endl;
    }
    else
     cout<<min_len<<endl;
}



int noOfSetBits(int x){
    int res=0;
    int temp=x;
    if(x==0){
        return 0;
    }
    while(temp){
        res++;
        temp=temp&(temp-1);
    }
    return res;
}





int32_t main(){

    

    int n,q;
    cin>>n>>q;

    int setBits[n];

    rep(i,0,n){
        cin>>arr[i];
    }
  
   
    rep(i,0,n){
        int ones = noOfSetBits(arr[i]);
        setBits[i]=ones;
    }

   




    while(q--){
        int k;
        cin>>k;

        if(k==0){
            cout<<1<<endl;
            continue;
        }


        solve(setBits,n,k);
        

    }






  





    return 0;
}