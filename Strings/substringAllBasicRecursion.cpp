#include <bits/stdc++.h>

using namespace std;


unordered_map<string,int> um;


void subString_(string S,int i,string ans){

    if(i>S.length()){
        return;
    }

    if(ans!="" && um.find(ans)==um.end()){
        um[ans]=1;
        cout<<ans<<" ";
       
    }

    string temp = "";

    subString_(S,i+1,ans+S[i]);
    subString_(S,i+1,temp);



    return;



}


int main(){

    string s,ans="";
    cin>>s;

    subString_(s,0,ans);





    return 0;
}