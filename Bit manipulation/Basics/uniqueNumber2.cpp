#include <bits/stdc++.h>
using namespace std;

//find unique number where in array each numbers occurs twice except two numbers
// expected space complexity = o(1)

void uniqueNumberTwo(int arr[],int n){
    int res=0;

    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    cout<<res<<endl;

    int a=0,b=0;

    int j=0;
    int temp =res;

    while(temp){
        if((temp&1)==1){
            break;
        }
        j++;
        temp=(temp>>1);
    }
    cout<<j<<endl;

    for(int i=0;i<n;i++){
        if((arr[i] & (1<<j)) >0){
            cout<<arr[i]<<" ";
            a=(a^arr[i]);
        }
    }
    cout<<endl;

    b = res^a;

    cout<<b<<" "<<a<<endl;

}




int main(){

    int arr[]={1,2,3,2,1,5,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    uniqueNumberTwo(arr,n);




    return 0;
}