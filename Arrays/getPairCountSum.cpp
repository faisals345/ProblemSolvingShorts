#include <bits/stdc++.h>
using namespace std;

  int freq[100001];
   

int getPairsCount(int arr[], int n, int k)
{

  

    if (k > 2000000)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (k > arr[i] )
        {
            if(arr[i]*2==k ){
                ans+=freq[k-arr[i]]-1;
                continue;
            }

            ans += freq[k - arr[i]];
        }
    }

    ans /= 2;
    return ans;
}

int main(){

      memset(freq, 0, sizeof(freq));
      
      int n,k;
      cin>>n>>k;
      int arr[n];

      for(int i=0;i<n;i++){
          cin>>arr[i];
      }

      cout<<getPairsCount(arr,n,k);



    
      

      



    return 0;
}