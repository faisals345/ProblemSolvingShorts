#include <bits/stdc++.h>
using namespace std;


map<int,int> mp;
int maxWt=INT_MIN;


void solve(string s,bool flag){

    int date=0;


    for(int i=0;i<s.length()-1;){

        if(s[i]>=48 && s[i]<=57){
            if(s[i+1]>=48 && s[i+1]<=57){
                 date = (s[i]-'0')*10 + (s[i+1]-'0');
                if(flag){
                    mp[date]+=2;
                }
                else{
                    mp[date]+=1;
                }


            }
            else{
                  date = s[i]-'0';
                if(flag){
                    mp[date]+=2;
                }
                else{
                    mp[date]+=1;
                }

            }
            maxWt=max(maxWt,mp[date]);
            i+=2;
        }
        else{
            i++;
        }

    }

    





}




int main(){


    for(int i=1;i<=30;i++){
        mp[i]=0;
    }

    int n;
    cin>>n;
    cin>>ws;

    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);

        bool flag = false;
        if(s[0]=='G'){
            flag=true;
        }
        solve(s,flag);
    }

    int cnt=0;

    for(int i=1;i<31;i++){
        if(mp[i]==maxWt){
            cnt++;
        }
    }

    if(cnt==1 && (mp[19]==maxWt || mp[20]==maxWt)){
        cout<<"Date"<<endl;
    }
    else{
        cout<<"No Date"<<endl;
    }
    

   

   
   
   
       

    

   



  

    

    



    return 0;
}