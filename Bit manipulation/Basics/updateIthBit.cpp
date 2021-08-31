#include <bits/stdc++.h>
using namespace std;

void updateIthBitNUM(int &num,int i,int v){

     num = num & (~(1<<i));
     num = num | (v<<i);

    return;

}




int main(){

    int n= 5;
    int i,v;
    cin>>i>>v;
    updateIthBitNUM(n,i,v);
    cout<<n<<"\n";


    return 0;
}