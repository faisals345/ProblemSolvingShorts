#include <bits/stdc++.h>
using namespace std;

void power_optimised(int a,int n){
    int ans =1;

    while(n){
        int last_bit = n&1;
        if(last_bit){
            ans=ans*a;
        }
        a=a*a;
        n=n>>1;
    }

    cout<<ans<<endl;

    return;
}


int main(){

    power_optimised(122,4);



    return 0;
}