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

int D,a,m,b,x;


bool solve(int mid){
    //write function to calculate how much you can make
    int amount=D;
    int months=mid;

    if(months/m==0){
        amount+=a*months;
    }
    else{
        int r=months/(m+1);
        amount+=(b*r) + a*(months-r);
    }

    if(amount>=x){
        return true;
    }
    return false;
   
}








int32_t main()
{
    tc{
        cin>>D>>a>>m>>b>>x;
        int l=1,high=1e9;
        int res=0;

        while(l<=high){

            int mid = (l+high)/2;

            if(solve(mid)){
                res=mid;
                high=mid-1;

            }
            else{
                l=mid+1;

            }

        }

        cout<<res<<endl;
    }

	return 0;
}
