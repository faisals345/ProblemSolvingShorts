#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> A){

    vector<int> factors;
    unordered_map<int, int> um;

    unordered_map<int, int> ans, freq;
    vector<int> final_ans(A.size(), 0);

    for (int i = 0; i < A.size(); i++)
    {
        um[A[i]] = 0;
        freq[A[i]]++;
    }

    for (int i = 0; i < A.size(); i++)
    {
        int n = A[i];

        for (int j = 1; j * j <= n; j++)
        {

            if (n % j == 0)
            {

                if (n / j == n)
                {

                    ans[n] += freq[n] - 1;

                    if (um.find(1) != um.end() && n != 1)
                    {
                        ans[n] += freq[1];
                    }
                }

                else if (n / j != j)
                {

                    if (um.find(j) != um.end())
                    {
                        ans[j]++;
                        ans[n] += freq[j];
                    }
                    if (um.find(n / j) != um.end())
                    {
                        ans[n / j]++;
                        ans[n] += freq[n / j];
                    }
                }
                else
                {
                    if (um.find(n / j) != um.end())
                    {
                        ans[n / j]++;
                        ans[n] += freq[n / j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < A.size(); i++)
    {

        if (A[i] == 1)
        {
            final_ans[i] = A.size();
            cout<<final_ans[i]<<" ";
            continue;
        }
        if (ans.find(A[i]) != ans.end())
        {
            final_ans[i] = ans[A[i]];
            cout<<final_ans[i]<<" ";
        }
    }
    return ;
}

int main(){

    vector<int> A={10,12,2,5,6};
    solve(A);

}