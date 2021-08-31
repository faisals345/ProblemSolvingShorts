#include <bits/stdc++.h>
using namespace std;

void setIthbitNUM(int &num,int i){

    int mask = 1<<i;
    num = (num | mask);

}




int main(){

    int n= 5;
    int i;
    cin>>i;
    setIthbitNUM(n,i);
    cout<<n<<"\n";


    return 0;
}