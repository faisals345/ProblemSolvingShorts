#include <bits/stdc++.h>
using namespace std;


bool canMakePrataInGivenMinutes(int arr[],int n,int minTime,int target){

    int current=0;

    for(int i=0;i<n;i++){

        for(int t=0,k=1;t<=minTime;){

            if(t+k*arr[i]<=minTime){
                    current++;
                    t+=k++*arr[i];
            }
            else{
                break;
            }
            
            

            
        }
        if(current>=target){
                return true;

            }
    }
    return false;





}


int main(){

    int t;
    cin>>t;
    while(t--){
        int target=0;
        cin>>target;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = INT_MAX;

        int l=1,r=arr[n-1]*(target*(target+1))/2;
        while(l<=r){
            int mid = (l+r)/2;

            if(canMakePrataInGivenMinutes(arr,n,mid,target)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans<<"\n";
    }





    return 0;
}