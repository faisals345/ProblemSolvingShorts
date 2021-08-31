#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s){

    int i=0,j=s.length()-1;

    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++,j--;

    }
    return true;
}


int palindromicP(string s){

     if(s.length()==1){
         return 0;
     }
     if(isPalindrome(s)){
         return 0;
     }


     int k= INT_MAX;

     for(int i=0;i<s.length()-1;i++){

         int c1 = palindromicP(s.substr(0,i+1));
         int c2 = palindromicP(s.substr(i+1));

         k=min(k,c1+c2);


     }

     return k+1;





}



int main(){

    string s = "cddpd";
    cout<<palindromicP(s)<<endl;




    return 0;
}