#include <bits/stdc++.h>

using namespace std;



void lcs_(string s1, string s2){


    // dp banann padega

    int dp[s1.length()+1][s2.length()+1];


    memset(dp,0,sizeof(dp));


    for(int i=1;i<=s1.length();i++){


        for(int j=1;j<=s2.length();j++){

            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }

    cout<<dp[s1.length()][s2.length()]<<endl;






}



int main(){

    string s1 ,s2;
    cin>>s1>>s2;

    lcs_(s1,s2);




    return 0;
}