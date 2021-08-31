#include <bits/stdc++.h>
using namespace std;


void mergeFunction(int arr[],int start,int mid,int end){

    //merge two sorted function

    int sizeTotal = end - start + 1;
    int k=0;
    int orr[sizeTotal];

    int l = start, r = mid+1;

    while(l<=mid && r<=end){
        if(arr[l]<arr[r]){
            orr[k++]=arr[l++];
        }else{
            orr[k++]=arr[r++];
        }
    }
    while(l<=mid){
         orr[k++]=arr[l++];

    }
     while(r<=end){
         orr[k++]=arr[r++];

    }

    for(int i=0;i<k;i++){
        arr[start+i]=orr[i];
    }
    return;





}

void mergeSort(int arr[],int start,int end){


    if(start<end){

            int mid =(start+end)/2;

            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            mergeFunction(arr,start,mid,end);

    }

    return;

}





int main(){
      int arr[]={5,7,2,25,41,63,35};
      int n = sizeof(arr)/sizeof(arr[0]);



        mergeSort(arr,0,n-1);

         for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
        }
        cout<<endl;
      

      



    return 0;
}