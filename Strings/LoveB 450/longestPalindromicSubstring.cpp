#include <bits/stdc++.h>

using namespace std;







string longestPalindrome(string s)
{

    int n = s.length();

    int dp[n][n];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

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
                }
                else
                {
                    int len = dp[i + 1][j - 1];
                    if (len == j - i - 1)
                    {
                        c1 = 2 + len;
                    }
                   
                }
            }
           
                c2 = max(dp[i+1][j],dp[i][j-1]);

                dp[i][j] = max(c1, c2);
            
        }
    }

    int index1 = 0, index2 = n - 1;

    for (int i = n - 1; i > 0; i--)
    {
        if (dp[0][i] != dp[0][i - 1])
        {
            index2 = i;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (dp[i][n - 1] != dp[i + 1][n - 1])
        {
            index1 = i;
            break;
        }
    }

    return s.substr(index1, dp[0][n-1]);
}


int main(){


    string s="geegfofgeeg";

    string ans = longestPalindrome(s);
    cout<<ans<<endl;




    return 0;
}