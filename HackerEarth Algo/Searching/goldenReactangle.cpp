#include <bits/stdc++.h>
using namespace std;


int main(){

    int N;
    cin>>N;

    int cnt=0;
    for(int i=0;i<N;i++){
        int W,H;
        cin>>W>>H;
        double r1 = (W*1.0)/(H*1.0);
        double r2 = (H*1.0)/(W*1.0);

        if(r1>=1.6 && r1<=1.7 || (r2>=1.6 && r2<=1.7)){
            cnt++;
        }
    }
    cout<<cnt<<endl;



    return 0;
}