#include <bits/stdc++.h>

using namespace std;

 map<char,int> mp1,mp2;
 
    void minWindow(string s, string t) {
        
        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }
        
        int m2=mp2.size();
        
        map<int,int> mp3(mp2.begin(),mp2.end());
        
        int j=0;
        string res="";
        int minLen=INT_MAX;
        int k=0; //pointed to those which are to be released
        
        for(int i=0;i<s.length();i++){
            
            
            //apply acquire and release
             mp1[s[i]]++;
            if(mp2.count(s[i])!=0 && mp2[s[i]]!=0){
                mp2[s[i]]--;
               
                if(mp2[s[i]]==0)
                   j++;
            } 
            // else{
            //     mp1[s[i]]+=1;
            // }
                
                
            if(j==m2){
                
                if(i-k+1<minLen){
                    minLen=i-k+1;
                    res=s.substr(k,minLen);
                }
                
                while(j==m2){
                    
                    mp1[s[k]]--;
                    
                    if(mp3.count(s[k])!=0 && mp1[s[k]]<mp3[s[k]]){
                        mp2[s[k]]++;
                        j--;
                        
                        minLen=i-k+1;
                        res=s.substr(k,minLen);
                    }
                    k++;
                    
                }
            }  
                
                
                
        
            
        }
       cout<<res<<endl;
       return;
        
        
    }

int main(){
    
    string s,t;
    cin>>s>>t;
    minWindow(s,t);
    
    return 0;
}