#include <bits/stdc++.h>
using namespace std;


int partition(int arr[],int start, int end){

    int pivot = end;
    int pIndex = start;

  

    while(start<end){

        if(arr[start]<arr[pivot]){
            swap(arr[start],arr[pIndex]);
            start++;
            pIndex++;

        }
        else{
            
         start++;
        }
        
    }

    swap(arr[pivot],arr[pIndex]);

    return pIndex;


}

void quickSort(int arr[],int start,int end){


    if(start<end)
    { 
       int pIndex = partition(arr,start,end);

  
       quickSort(arr,start,pIndex-1);
 
       quickSort(arr,pIndex+1,end);

       }

    return;


}





int main(){

      int arr[]={5,7,2,25,41,63,35};
      int n = sizeof(arr)/sizeof(arr[0]);



        quickSort(arr,0,n-1);

         for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
        }
        cout<<endl;
      

      



    return 0;
}