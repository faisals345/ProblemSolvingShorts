#include <bits/stdc++.h>
using namespace std;

void subsequenceUsingBitset(string s){

    int n = 1<<(s.length());

    for(int i=1;i<n;i++){
        

        int j=i;
        while(j){
            int k = __builtin_ffs(j);
            cout<<s[k-1];
            int mask = ~(1<<(k-1));
            j=j&mask;
        }
        cout<<endl;
    }
}



int main(){

    string s;
    cin>>s;
    subsequenceUsingBitset(s);




    return 0;
}