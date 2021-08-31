#include <bits/stdc++.h>
using namespace std;

void clearBitsFromItoJNUM(int &num,int i,int j){

    int a = (~0) << (i+1);
    int b = (1<<j) -1;

    int mask = a | b;
    num = num & mask;
     

    return;

}

void replaceBitsinnbym(int &n,int m,int i,int j){

    clearBitsFromItoJNUM(n,i,j);
    m = m<<j;

    n = n|m;
    return;



}




int main(){

    int n= 31;
    int m=6;
    int i,j;
    cin>>i>>j;
    replaceBitsinnbym(n,m,i,j);
    
    cout<<n<<"\n";


    return 0;
}