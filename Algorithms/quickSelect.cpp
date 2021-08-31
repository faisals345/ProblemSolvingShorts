#include <bits/stdc++.h>
using namespace std;


int partitionT(int arr[],int start,int end){

    int index = end;

    int dupArr[end - start +1];


    int k=0;

    for(int i=start;i<end;i++){
        if(arr[i]>arr[index]){
            continue;
        }
        dupArr[k++]=arr[i];
    }

        int ans =start+ k;

     dupArr[k++]=arr[index]  ; 

     for(int i=start;i<end;i++){
        if(arr[i]>arr[index]){
          dupArr[k++]=arr[i];
            
        }
    }

    for(int i=0;i<k;i++){
        arr[i+start]=dupArr[i];
    }

    return ans;






}


int quickSelect(int arr[],int start,int end,int k){

    int p = partitionT(arr,start,end);

    if(p==k){
        
        return p;

    }
    else if(p>k){
       return quickSelect(arr,start,p-1,k);

    }
    else{
      return  quickSelect(arr,p+1,end,k);

    }

    
}



int main(){


     int arr[]={7, 10, 4, 3 ,20, 15};
      int n = sizeof(arr)/sizeof(arr[0]);

      cout<<quickSelect(arr,0,n-1,2);




    return 0;
}