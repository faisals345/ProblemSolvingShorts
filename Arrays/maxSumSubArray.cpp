#include <bits/stdc++.h>
using namespace std;


int solve(int arr[],int n){

    
        int curr_max=-1e7;
        int total_max=-1e7;
        
        for(int i=0;i<n;i++){
            
            curr_max=max(curr_max+arr[i],arr[i]);
            total_max=max(total_max,curr_max);
        }
        
        return total_max;



}


int main(){

    int arr[]= {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<solve(arr,n)<<endl;;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}