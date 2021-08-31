#include <bits/stdc++.h>

using namespace std;



void longestIncreSubSequence(vector<int> arr){

    int dp[arr.size()];
    dp[0]=1;
    int maxL=INT_MIN;

    for(int i=1;i<arr.size();i++){

        dp[i]=1;

        for(int j=0;j<i;j++){

            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }


        }
        maxL=max(maxL,dp[i]);
    }

    cout<<maxL<<endl;





    return;
   
  


}



int main(){

    vector<int> arr;
    int n;cin>>n;
    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    longestIncreSubSequence(arr);

   




    return 0;
}