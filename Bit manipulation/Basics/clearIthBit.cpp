#include <bits/stdc++.h>
using namespace std;

void clearIthBitNUM(int &num,int i){

    int mask = ~(1<<i);
    num = (num & mask);

    return;

}




int main(){

    int n= 5;
    int i;
    cin>>i;
    clearIthBitNUM(n,i);
    cout<<n<<"\n";


    return 0;
}