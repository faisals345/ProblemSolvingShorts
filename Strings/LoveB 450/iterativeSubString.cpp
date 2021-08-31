#include <bits/stdc++.h>

using namespace std;





int main(){

    string s;
    cin>>s;

    int n = s.length();

    for(int i=n-1;i>=0;i--){

        for(int j=i;j<n;j++){
            cout<<s.substr(i,j-i+1)<<" ";
        }
    }






 return 0;

}