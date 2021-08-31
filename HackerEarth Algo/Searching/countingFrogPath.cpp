#include <bits/stdc++.h>
using namespace std;


void solveFroginFrame(int x,int y,int s,int t){

    int time_spent =y+x;
    int count =0;
    if(time_spent>t){
        cout<<0<<endl;
        return ;
    }
    count =1;
    int top_row=x+s;
   


    for(int i=x;time_spent<=t && i<=top_row;i++){

        int steps=0;
        if(time_spent+s>t){
            steps=t-time_spent;
        }
        else{
            steps=s;
        }
        count+=steps;
        if(time_spent<t && i<top_row){
            count++;
        }
        time_spent++;

    }

    cout<<count<<endl;
    return;


}


int main(){

    int x,y,s,t;
    cin>>x>>y>>s>>t;

    solveFroginFrame(x,y,s,t);





    return 0;
}