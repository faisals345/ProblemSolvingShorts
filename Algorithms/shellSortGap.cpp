#include <bits/stdc++.h>
using namespace std;




void shellSort(int arr[],int n){
    int gap = n/2;
    while(gap>0)
    {
        for(int i=gap;i<n;i++)
        {
            int temp = arr[i];
            int j=i;
            while(j>=gap && arr[j-gap]>temp)
            {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap = gap/2;
    }
}



int main(){


    int arr[]={14,5,76,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    shellSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }




    return 0;
}