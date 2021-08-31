#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> prime;

void sieve(int n){

    vector<bool> isPrime(n+1,true);

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j=i*i;j<=n;j++){
                isPrime[j]=false;
            }
        }
    }

    return;

}

void segmentedSieve(int l,int h){

    vector<bool> isPrime(h-l+1,true);
    int sq= sqrt(h);
    sieve(sq);

    for(auto primeNum:prime){

        int sm = (l/primeNum)*primeNum;

        if(sm<l){
            sm+=primeNum;
        }

        for(int j=sm;j<=h;j+=primeNum){
            isPrime[j-l]=false;
        }
    }

    for(int i = l;i<=h;i++){
        if(isPrime[i-l]==true){
            cout<<i<<" ";
        }
    }
    cout<<endl;

}




int32_t main(){

    int l,h;
    cin>>l>>h;
    segmentedSieve(l,h);




    return 0;
}