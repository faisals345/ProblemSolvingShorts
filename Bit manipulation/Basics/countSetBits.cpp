#include <bits/stdc++.h>
using namespace std;

int countSetBitsinNum(int n){
    int ans = 0;

    while(n){
        ans++;
        n= n &  (n-1);
    }
    return ans;
}


int main(){


    int n=5;
    cout<<countSetBitsinNum(n)<<"\n";



    return 0;
}