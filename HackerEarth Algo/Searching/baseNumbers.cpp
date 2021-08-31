#include <bits/stdc++.h>
using namespace std;

#define ld long double
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

int a,b,n;

int numberOfDigit(int x){
    int ans=0;
    // cout<<log(a);
    // cout<<" "<<log(b)<<" "<<log(x)<<endl;
     ans = floor(log(a) / log(b) + x * log(x) / log(b)) + 1;
    return ans;

}

bool check(int val,int y){

    int t=numberOfDigit(val);
    if(t>=y){
        return true;
    }
    return false;



}


int32_t main(){


    while (cin >> a >> n >> b)
    {
        int low = 1;
        int high = 1e9;
        int res1 = 0;
        int res2 = 0;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            if (check(mid, n))
            {
                res1 = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        low = 1;
        high = 1e9;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(mid, n + 1))
            {
                res2 = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << res2 - res1 << endl;
    }

   



  





    return 0;
}