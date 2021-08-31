#include <bits/stdc++.h>
using namespace std;

void decimalToBinaryNum(int n){
    int ans =0;
    int p=1;

    while(n){
        int t = n&1;
        ans+=t*p;
        p=p*10;
        n=n>>1;
    }

    cout<<ans<<"\n";
}


int main(){

    int n = 985;
    decimalToBinaryNum(n);


    return 0;
} 