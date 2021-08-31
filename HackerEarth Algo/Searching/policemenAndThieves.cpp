#include <bits/stdc++.h>

using namespace std;

void solve(char arr[],int n,int &count,int k){

    vector<int> thieve,police;

    for(int i=0;i<n;i++){
        if(arr[i]=='P'){
            police.push_back(i);
        }
        else{
            thieve.push_back(i);
        }
    }

    int l=0,r=0;
    while(r<police.size() && l<thieve.size()){

         if(abs(thieve[l] - police[r]) <= k) {
            count++;
            l++;
            r++;
        }
 
        
        else if (thieve[l] < police[r])
            l++;
        else
            r++;

    }
    
    return;

}



int main(){

    int T;
    cin>>T;
    int cnt = 0;

    while(T--){

        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){

            char arr[n];
            for(int j=0;j<n;j++){
                cin>>arr[j];

            }
            solve(arr,n,cnt,k);
            
        }

        cout<<cnt<<endl;
        cnt=0;


    }



    return 0;
}