#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define int long long

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




void longestSubsequence(int b[], int n,int k)
{
 
 
        int longest = upper_bound(b, b + n, k) - b;
 
        cout<< longest << endl;
    
}








int32_t main()
{       fast();
   
        int n;
        cin>>n;
        int arr[n];
        rep(i,0,n){
            cin>>arr[i];
        }
        sort(arr, arr + n);

         int sum = 0;
 
   
    int b[n];
 
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        double av = (double)(sum) / (double)(i + 1);
        b[i] = ((int)(av + 1));
    }

        int q;
        cin>>q;
        while(q--){
            int k=0;
            cin>>k;
            longestSubsequence(b,n,k);

            
        }
     
    

	return 0;
}
