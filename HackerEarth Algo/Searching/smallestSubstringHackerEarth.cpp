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

void solve(string s,string t){

    int dist=0;

    //create map to store char of t and its frequency
    unordered_map<char,int> freq;
    int n = t.length();

    rep(i,0,n){
        if(freq.count(t[i])==0){
            freq[t[i]]=1;
            dist++;
        }
        else{
            freq[t[i]]++;
        }
    }

    bool found = false;

    int i=0,j=0,minLength=s.length()+1;

    int left=0,right=s.length()-1;

    while(j<s.length()){

            char endChar = s[j++];

            //start taking in char untill dist!=0
            if(freq.count(endChar)!=0){
                freq[endChar]--;
                if(freq[endChar]==0){
                    dist--;
                }
            }

            if(dist>0){
                continue;
            }

            //start filtering from right untille dist>0
            // cout<<i<<" "<<j<<endl;

            while(dist==0){
                char startChar = s[i++];
                if (freq.count(startChar) != 0)
                {
                    freq[startChar]++;
                    if (freq[startChar]>0)
                    {
                        dist++;
                    }
                }
            }

            if (minLength > j - i)
            {
                left = i, right = j;
                minLength=j-i;
                found = true;
            }

    }
    if(found){
       cout<<minLength+1<<endl;
    }









}




int32_t main(){

    string s;
    cin>>s;
    string t="";
    int visited[256]={0};
    memset(visited,0,sizeof(visited));



    rep(i,0,s.length()){
        if(visited[s[i]-'a']==0){
            visited[s[i]-'a']=1;
            t+=s[i];
        }

    }
    // cout<<t<<endl;
    solve(s,t);

    return 0;
}