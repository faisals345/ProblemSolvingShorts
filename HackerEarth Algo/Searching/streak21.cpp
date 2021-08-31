#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        string n;
        
        cin>>n;
        int num = stoi(n);
        bool flag =true;

        size_t ind = n.find('2');
        while(n.find('2',ind)!=string::npos && ind<n.length()-1)
        {   
                if(n[ind+1]=='1'){
                    flag=false;
                    break;
                }
                ind++;

           
        }

        if(num%21==0){
            flag=false;
        }

        if(flag){
            cout<<"The streak lives still in our heart!"<<endl;
        }
        else{
            cout<<"The streak is broken!"<<endl;
        }
        
        
    }




    return 0;
}