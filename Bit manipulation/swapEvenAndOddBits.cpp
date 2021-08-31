#include <bits/stdc++.h>
using namespace std;

void updateIthBit(int &num,int i,int v){

     num = num & (~(1<<i));
     num = num | (v<<i);

    return;

}


int main(){

    int n = 23;

    int k = (int)(log2(n));

    cout<<k<<endl;

    int j=k;
    j= k%2==0?k+1:k;

    for(j;j>=1;j-=2){
        int val1 = n &(1<<(j-1))?1:0;
        int val2= n &(1<<(j))?1:0;

        updateIthBit(n,j,val1);
        updateIthBit(n,j-1,val2);

    }

    cout<<n<<endl;

    return 0;
}