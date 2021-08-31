#include <bits/stdc++.h>
using namespace std;

int cnt[64];

void uniqueNumberThree(int arr[],int n){
    for(int i=0;i<64;i++){
        cnt[i]=0;
    }

    for(int i=0;i<n;i++){

        int temp = arr[i];
        int j=0;

        while(temp){
            int last_bit = temp&1;
            cnt[j++]+=last_bit;
            temp = temp>>1;
        }
    }

    int ans=0,p=0;
    for(int i=0;i<32;i++){
        cnt[i]%=3;
        ans = ans + cnt[i]*(1<<i);
    }

    cout<<ans<<" ";
}

int main(){

    int arr[]={1,1,1,2,3,3,3,4,5,5,5,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    uniqueNumberThree(arr,n);




    return 0;
}
