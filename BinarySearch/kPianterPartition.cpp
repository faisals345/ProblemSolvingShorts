#include <bits/stdc++.h>
using namespace std;


bool canPainterPaintInGivenTime(int arr[],int n, int k,int targetTime){

    int count =1;
    int current =arr[0];

    for(int i=1;i<n;i++){
        if(current + arr[i]>targetTime){
            count++;
            current=arr[i];

        }
        else{
            current+=arr[i];
        }

        if(count>k){
            return false;
        }
    }

    return true;





}


int main(){



    return 0;
}