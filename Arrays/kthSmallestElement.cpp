#include <bits/stdc++.h>

using namespace std;


int main(){


    int arr[]={20,5,7,14};
    int n = sizeof(arr)/sizeof(arr[0]);

    set<int> s;

    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    auto it = s.begin();
    cout<<*it<<endl;

    




    return 0;
}