#include <bits/stdc++.h>
using namespace std;



void removeAdjacentDuplicates(const char* s){

    char prev=s[0];
    string ans="";
    ans=ans+s[0];

    for(int i=1;s[i]!='\0';i++){

        if(prev==s[i]){
            continue;
        }

        ans = ans + s[i];
        prev = s[i];
    }

    cout<<ans<<"\n";



    
}



int main(){

  const  char* s = "geeeekssss";
  

    removeAdjacentDuplicates(s);

    



    return 0;
}