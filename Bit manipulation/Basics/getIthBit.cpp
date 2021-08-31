#include <bits/stdc++.h>
using namespace std;

int getIthBitNum(int num,int i){

    int mask = 1<<i;
    return (num&mask) >0 ? 1:0;  //take care of precedence

}




int main(){

    int n= 5;
    int i;
    cin>>i;
    cout<<getIthBitNum(n,i)<<"\n";


    return 0;
}