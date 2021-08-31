#include <bits/stdc++.h>
using namespace std;


void heapify(int arr[],int index,int sz){

    int left = 2*index +1;
    int right = left+1;
    int max = index;

    if(left<=sz && arr[left]>arr[max]){
        max=left;
    }

     if(right<=sz && arr[right]>arr[max]){
        max=right;
    }

    if(max!=index){
        swap(arr[max],arr[index]);
        heapify(arr,max,sz);
    }







}

void buildHeap(int arr[],int sz){

    int i;
    for(int i=sz/2;i>=0;i--){

        heapify(arr,i,sz);

    }


}







int main(){

      int arr[]={5,7,2,25,41,63,35,199};
      int n = sizeof(arr)/sizeof(arr[0]);



        buildHeap(arr,n-1);

         for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
        }
        cout<<endl;
      

      



    return 0;
}