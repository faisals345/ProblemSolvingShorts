#include <bits/stdc++.h>

using namespace std;



void lcs_(string s1){


    // dp banann padega

    string s2=s1;

    int dp[s1.length()+1][s2.length()+1];


    memset(dp,0,sizeof(dp));

    int maxL = INT_MIN;


    for(int i=1;i<=s1.length();i++){


        for(int j=1;j<=s2.length();j++){

            if(s1[i-1]==s2[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

            maxL = max(maxL,dp[i][j]);

        }
    }

    cout<<maxL<<endl;






}



int main(){

    string s1 ;
    cin>>s1;

    lcs_(s1);




    return 0;
}