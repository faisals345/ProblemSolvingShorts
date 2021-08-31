#include <bits/stdc++.h>
using namespace std;



int solve(int arr[], int cows, int noOfTents){


    int ans=arr[noOfTents-1]-arr[0];

   
    int prev = arr[0];

    for(int dist=1;dist<=arr[noOfTents-1]-arr[0];dist++){

        prev = arr[0];

        bool flag = false;


        for(int k=1;k<=cows-1;k++){

            if(k!=cows-1){
                auto it = lower_bound(arr,arr+noOfTents,prev+dist);

                if(it-arr>=noOfTents-1){
                        flag=true;
                        break;
                }
                prev = *it;

            }
            else{
                auto it = lower_bound(arr,arr+noOfTents,prev+dist);

                if(it-arr>=noOfTents){
                        flag=true;
                        break;
                }

            }

        }
        if(flag==false){
            ans=dist;
        }
        else{
            return ans;
        }

    }




    return ans;

}



int main(){


    int arr[]={5,8,10,12,15,20,24};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cows = 3;

    cout<<solve(arr,cows,n);
 
    



    return 0;
}