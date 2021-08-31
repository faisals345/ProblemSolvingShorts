#include <bits/stdc++.h>
using namespace std;

int gcd__(int a,int b){
    if(b==0){
        return a;
    }
    return gcd__(b,a%b);
}

int funcX(char strg[],int n){
    int ans;

   

    for(int i=0;i<n ;i++){
        if(strg[i]>=48 && strg[i]<58){
            ans+=(strg[i]-48);
        }
        else{
            ans+=(strg[i]-55);
        }

    }
    

    return ans;
}

int decToHexa(int n)
{
   
    char hexaDeciNum[100];
 
   
    int i = 0;
    int num_char=0;
    while (n != 0) {
        
        int temp = 0;

 
        
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
            num_char++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
             num_char++;
        }
 
        n = n / 16;
    }

    int ans =  funcX(hexaDeciNum,num_char);
    return ans;
 
  
}

int main(){
   
   

   int t;
   cin>>t;
   while(t--){
       int L,R;
       cin>>L>>R;
        int cnt=0;
       for(int j=L;j<=R;j++){
           
           int d=decToHexa(j);

           int gcd=gcd__(j,d);
           if(d>1){
               cnt++;
           }
       

       }
       cout<<cnt<<endl;
   }


    
}