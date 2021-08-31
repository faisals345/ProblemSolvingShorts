#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){

    int i=0,j=n-1;

    while(i<j){
        while(arr[i]>0){
            i++;
        }

        while(arr[j]<0){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
            
        }
       

        
    }

     int k=0;

        if(arr[i]<0){
            k=i;
        }
        else{
            k=i+1;
        }


    for(int i=0,j=k;i<n && j<n;i+=2,j++){
            swap(arr[i],arr[j]);  
        }


        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;



        return;


}




int main(){

       int arr[]={5,7,2,-25,41,-63,-35};
      int n = sizeof(arr)/sizeof(arr[0]);

      solve(arr,n);



    return 0;
}