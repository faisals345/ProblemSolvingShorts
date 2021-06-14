#include <bits/stdc++.h>
using namespace std;

void foo(int *arr){
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;  //always 2

    // Pointer variable size is not depending on data type as pointer 
    //always stores the address of other variable which is always integer 
   // data type. So, any pointer (int, char, double, etc) size will be 2 for 16
    // bit processor, 4 for 32 bit processor and 8 for 64 bit processor.

}

void foo2(int * arr,int n){
    arr[1]=88;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void foo3(int * arr,int n){
    arr[1]=88;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void foo4(int (*arr),int n){
 
 
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
           
            cout<<*(arr +i+j)<<" ";
        }
        cout<<endl;
    }
    

   
}


int main(){
    //foo part
    // int arr[]={1,2,3,7,9,7};
    // cout<<sizeof(arr);
    // cout<<endl;
    // int *p;
    // p=arr;
    // foo(p);
    //foo end

    //passing arr as pointer and see changes in function, can it really impact orig one
   
   /*
    int arr2[]={1,2,3,4,5};
    foo2(arr2,5);                           // It is proved that arr is passed as pointer in c 
                                            and c++.They are decayed to pointer wheather
                                            foo is having parameter(int arr[]) or foo(int *arr);
                                            information such as size all are lost;

    for(int i=0;i<5;i++){
        cout<<arr2[i]<<" ";
    }
    */

   //trying arr as reference using & //
//    int arr3[]={1,2,3,4,5};
//    foo3(arr3,5);
//                                                 //not possible bro 
//     for(int i=0;i<5;i++){
//         cout<<arr3[i]<<" ";
//     }

    int arr4[][3]={{12,3,4},{2,3,4},{2,6,7}};
    cout<<sizeof(arr4)<<endl;
    foo4(*arr4,3);
    // cout<<arr4[3][5]<<endl;

    //  for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         //arr5[i][j]++;
    //         cout<<arr4[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}