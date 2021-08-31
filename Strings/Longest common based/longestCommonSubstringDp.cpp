#include <bits/stdc++.h>

using namespace std;



void lcsubStr_(string s1, string s2){


    // dp banann padega

    int dp[s1.length()+1][s2.length()+1];


    memset(dp,0,sizeof(dp));
    int maxL = INT_MIN;


    for(int i=1;i<=s1.length();i++){


        for(int j=1;j<=s2.length();j++){

            if(s1[i]==s2[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            maxL = max(maxL,dp[i][j]);

        }
    }

    for(int i=0;i<=s1.length();i++){
        for(int j=0;j<=s2.length();j++){
            cout<<dp[i][j]<<" ";
        }

        cout<<"\n";
    }

    cout<<maxL<<endl;






}



int main(){

    string s1 ,s2;
    cin>>s1>>s2;

    lcsubStr_(s1,s2);




    return 0;
}