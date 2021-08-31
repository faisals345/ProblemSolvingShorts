#include <bits/stdc++.h>
using namespace std;

const int N = 100000;




void sieveGet(int *sieve){
    
    for(int i=1;i<=N;i++){
        sieve[i]=1;
    }
    sieve[1]=0;
    
    for(int i=2;i*i<=N;i++){
        
        if(sieve[i]==1){
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=0;
            }
        }
    }

  
    return;
    
    
    
}

int main() {

    int sieve[N+1];
    
    sieveGet(sieve);

    
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        string s;
        cin>>s;
        
        bool flag =true;
        
        for(int j=0;j<s.length();j++){
            if(sieve[arr[j]]!=s[j] -'0'){
                
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    
	
	
	
	
	
	return 0;
}