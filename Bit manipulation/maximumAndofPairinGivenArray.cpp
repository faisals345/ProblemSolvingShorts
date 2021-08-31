#include <bits/stdc++.h>
using namespace std;

/*
Input : arr[] = {4, 8, 12, 16}
Output : Maximum AND value = 8
we want to have the most significant bit in our ans 1 as many times as possible

*/


int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern)
            count++;
    return count;
}

int maxAND(int arr[], int n)
{
    int res = 0, count;

    for (int bit = 31; bit >= 0; bit--)
    {

        count = checkBit(res | (1 << bit), arr, n);

        if (count >= 2)
            res |= (1 << bit);
    }

    return res;
}



int main(){


    int arr[] = {4, 8, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<maxAND(arr,n)<<endl;





    return 0;
}