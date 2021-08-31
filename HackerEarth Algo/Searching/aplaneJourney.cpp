#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

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




ll bs(ll a[],ll b[],ll n,ll m)
{
    ll low=0,high=20,res=-1;
 
    while(low<=high)
    {
        ll mid=low+(high-low)/2;
 
        ll pos=n,x;
 
        for(ll i=m;i>=1;i--)
        {
            if(mid%2==0) x=mid/2;
            else x=mid/2+1;
 
            while(x>0 && a[pos]<=b[i] && pos>0)
            pos--,x--;
        }
 
        if(pos==0)
        res=mid,high=mid-1;
        else low=mid+1;
    }
 
    return res;
}
 
int main()
{
    ll n,m;
    cin>>n>>m;
 
    ll a[n+1],b[m+1];
 
    rep(i,1,n+1)
    cin>>(a[i]);
    rep(i,1,m+1)
    cin>>(b[i]);
 
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
 
    ll ans=bs(a,b,n,m);
 
    cout<<(ans);


    return 0;
}