#include <bits/stdc++.h>
using namespace std;

void clearLastIthBitNUM(int &num,int i){

    int mask = (~0) << i;
    num = num & mask;
     

    return;

}




int main(){

    int n= 31;
    int i;
    cin>>i;
    clearLastIthBitNUM(n,i);
    cout<<n<<"\n";


    return 0;
}