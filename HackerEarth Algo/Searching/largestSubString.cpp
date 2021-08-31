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

void solve(string s){
    int res=0;
    vector<int> vec(s.length());

    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            vec[i]=-1;
        }
        else{
            vec[i]=1;
        }
    }

    int sum=0;
    unordered_map<int,int> ump;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];

        if(sum<0){
            res= i+1;

        }
        else{
            if(ump.find(sum+1)!=ump.end()){
                res= max(res,i-ump[sum+1]);

            }
            else
              ump.insert({sum,i});
            

        }
    }

    cout<<res<<endl;



}




int32_t main(){

    int n;
    cin>>n;
    string s;
    cin>>s;

    solve(s);






  





    return 0;
}