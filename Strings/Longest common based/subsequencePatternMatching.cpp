#include <bits/stdc++.h>

using namespace std;



void lcs_(string s1, string pat){


    // dp banann padega

    int dp[pat.length()+1][s1.length()+1];


    memset(dp,0,sizeof(dp));


    for(int i=1;i<=pat.length();i++){


        for(int j=1;j<=s1.length();j++){

            if(pat[i-1]==s1[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }

    for(int i=0;i<=pat.length();i++){
        for(int j=0;j<=s1.length();j++){
            cout<<dp[i][j]<<" ";
        }

        cout<<endl;
    }

    int ans = 1;

    for(int j=s1.length();j>=0;j--){
        if(dp[pat.length()][j]!=dp[pat.length()][j-1]){
            break;
        }
        else{
            ans++;
        }
    }

    cout<<ans<<endl;






}



int main(){

    string s1 ,pat;
    cin>>s1>>pat;

    lcs_(s1,pat);




    return 0;
}