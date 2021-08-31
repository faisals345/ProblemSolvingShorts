#include <bits/stdc++.h>
using namespace std;


void insertionSort(int arr[],int n){

    // consider the first element as sorted

    // we will run 2 for loops

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=1;i<n;i++){

        int temp = arr[i];
        int k=i;

        for(int j=i-1;j>=0;j--){

            if(temp>=arr[j]){
               
                break;
            }
            else{
                arr[j+1]=arr[j];
            }

            k=j;
        }
        arr[k]=temp;

    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return ;

}


int main(){
      int arr[]={1,2,1};
      int n = sizeof(arr)/sizeof(arr[0]);

      insertionSort(arr,n);



    return 0;
}