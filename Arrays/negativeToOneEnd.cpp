#include <bits/stdc++.h>
using namespace std;


void solve(int arr[],int n){

    int neg,pos;
    neg=0,pos=n-1;

    while(neg<pos){

        while(arr[neg]<0){
            neg++;
        }
        while(arr[pos]>0){
            pos--;
        }
        if(neg<pos){
            swap(arr[neg],arr[pos]);
            neg++,pos--;
        }
        
    }
    return;



}


int main(){

    int arr[]= {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}