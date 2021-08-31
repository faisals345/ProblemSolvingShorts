#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> prime;

void sieve(int n){

    vector<bool> isPrime(n+1,true);

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    isPrime.clear();

    return;

}

int segmentedSieve(int l,int h){
    
 
    vector<bool> isPrime(h-l+1,true);
    int sq= sqrt(h);
    sieve(sq);
    int cnt=0;
    if(l==1){
        isPrime[0]=false;
    }

    for(auto primeNum:prime){

        int sm = (l/primeNum)*primeNum;
        if(sm==0){
            sm=2*primeNum;
        }

        if(sm<l){
            sm+=primeNum;
        }

        for(int j=sm;j<=h;j+=primeNum){
            isPrime[j-l]=false;
        }
    }
    
      for(int i = l;i<=h;i++){
            if(isPrime[i-l]==true ){
                cnt++;
             }
       }
       
       isPrime.clear();
       
    return cnt;

}




int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 
 int q;
 cin>>q;
 while(q--){
     int l,h;
     cin>>l>>h;
     int t=segmentedSieve(l,h);
     cout<<t<<"\n";
     prime.clear();

 }




    return 0;
}