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

bool solve(string s1,string &s2,int i){

    s2[i-1]='1';
    if(s2>=s1){
        return true;
    }
    return false;



}




int32_t main(){

    fast();

    int n,q;
    cin>>n>>q;

    string s1,s2;
    cin>>s1>>s2;
    int cnt1=0,cnt2=0,ind=-1;

    rep(i,0,n){
        if(s2[i]=='1'){
            cnt2++;
        }
        else{
            ind=i+1;
        }
        if(s1[i]=='1'){
            cnt1++;
        }
    }
    bool flag=true;

    while(q--){
        int i;
        cin>>i;
        if(flag==false){
            cout<<"YES"<<endl;
            continue;
        }
        if(cnt1==cnt2){
            cout<<"YES"<<endl;
            continue;
        }

        if(cnt1-cnt2==1){
            if(i!=ind){
                cout<<"NO"<<endl;
                continue;
            }
            else{
                 cout<<"YES"<<endl;
                 flag=false;
                 continue;

            }
        }
        if(solve(s1,s2,i)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }






  





    return 0;
}