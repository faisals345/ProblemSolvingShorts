#include <bits/stdc++.h>
using namespace std;

#define int long long





int32_t main(){

    int arr[]={5, 9, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

  
    int ans=0;

    int id_sum;
    

    for(int j=0;j<32;j++){

        int ones=0,zrs=0;


        for(int i=0;i<n;i++){
            if((arr[i]&(1<<j))>0){
                ones++;
            }
            else{
                zrs++;
            }
        }
        id_sum=ones*zrs*(1<<j);

        ans+=id_sum;


    }

    cout<<ans<<endl;



    return 0;
}
