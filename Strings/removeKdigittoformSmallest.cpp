#include <bits/stdc++.h>
using namespace std;

  string removeFirstKLargestDigit(string s,int k){
        string ans="";
        int cnt=0;
        int j=0;
        int i=0;
        
        for(i=1;i<s.length();i++){
            
              if(s[i]>s[j]){
                  s[i]='x';
                  
              }
              else{
                  s[j]='x';
                  j=i;
              }
              cnt++;
              if(cnt==k-1){
                  break;
              }
        
        }
        int tt=j;
      
        for(int z=i+1;z<s.length();z++){

            if(s[z]>s[tt]){
               tt=z;
            }
            else{
                break;
            }

        }

        s[tt]='x';
        
        for(int i=0;i<s.length();i++){
            if(s[i]!='x'){
                ans+=s[i];
            }
        }
        return ans;
      
    }
    
    string removeFirstK(string s,int k){
        
        
        
        string ans(s.begin()+k,s.end());

        while(ans.length()!=0 && ans.front()=='0'){
            ans.erase(ans.begin());
        }
        return ans;
        
        
        
        
    }
    
    int isBonusLeading(string s,int k){
        
        //base case likh lena
        
        if(k==s.length()){
            return k;
        }

        int t =0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                t=i;
                break;
            }
        }

        if(t<=k){
            return t;
        }

        return 0;
        
        
      

       
   
    }
    
    string helper(string s,int k){
        
        int t = isBonusLeading(s,k);
        
          if(t!=0){
            //remove first k dights
            
            string num = removeFirstK(s,t);
            if(t==k)
              return num;
            
            return helper(num,k-t) ; 
        }
        else{
            string num = removeFirstKLargestDigit(s,k);
            return num;
        }
        
        
        
        
    }
    
   


int main(){

    string S;
    cin>>S;
    int K;
    cin>>K;

    // string ans=helper(S,K);
    string ans2 =removeFirstKLargestDigit(S,K);
    cout<<ans2<<endl;




    return 0;
}