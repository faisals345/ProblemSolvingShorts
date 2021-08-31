#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans=0;
    int cnt[26]={0};

    for (int b = 0; b < n; ++b)
    {
        for (int d = b + 1; d < n; ++d)
        {
            if (s[b] == s[d])
            {
                for (int c = b + 1; c < d; ++c)
                {
                    ans += cnt[s[c] - 'a']; // add the combinations in b/w b and d, suh that xa==ac && c>a
                }
            }
        }
        cnt[s[b] - 'a']++; // count all characters before the position b
    }

    cout<<ans<<endl;


    return 0;
}