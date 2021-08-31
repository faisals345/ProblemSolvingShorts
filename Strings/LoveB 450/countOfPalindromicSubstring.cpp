#include <bits/stdc++.h>

using namespace std;







int countPalindromeSubstring(string s)
{

    int n = s.length();

    int dp[n][n];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    int count=n;

    // for str of length 2 deal sepeartely

    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = i + 1; j < n; j++)
        {   
            int c1=0,c2=0;

            if (s[i] == s[j])
            {

                if (j - i <= 1)
                {
                    dp[i][j] = 2;
                    count++;
                }
                else
                {
                    int len = dp[i + 1][j - 1];
                    if (len == j - i - 1)
                    {
                        c1 = 2 + len;
                        count++;
                    }
                   
                }
            }
           
                c2 = max(dp[i+1][j],dp[i][j-1]);

                dp[i][j] = max(c1, c2);
            
        }
    }
    return count;


}


int main(){


    string s="cddpd";

    int ans = countPalindromeSubstring(s);
    cout<<ans<<endl;




    return 0;
}