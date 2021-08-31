#include <iostream>
#include <vector>
using namespace std;


long long dp[21][21][2];              //dp array


long long dig[21];                    //digit array

long long solve(long long pos, long long cnt, long long flag)
{
    if(dp[pos][cnt][flag]!=-1)
    return dp[pos][cnt][flag];        //memoization
    if(pos==20)
    {
        if(cnt<=3) 
        return 1;                     
        return 0;
    }
    long long res = 0;
    if(flag==0)                       //if flag is 0 then range of next digit is from 0 to dig[pos]
    {
        for(long long d = 0;d<dig[pos];d++)
        {
            res+=solve(pos+1,cnt + (d!=0),1);
        }
        res+=solve(pos+1,cnt+(dig[pos]!=0),0);
    }
    else
    {                                 //if flag is 1 then range of next digit is 0-9
        for(long long d = 0;d<10;d++)
        {
            res+=solve(pos+1,cnt + (d!=0), 1);
        }
    }
    return dp[pos][cnt][flag]=res;
}


long long count(long long n)
{
    for(long long i= 0;i<21;i++)
    {
        for(long long cnt = 0;cnt<21;cnt++)
        {
            for(long long f = 0;f<2;f++)
            dp[i][cnt][f]=-1;                //initializing dp table
        }
    }
    long long c = 19;
    for(long long i = 0;i<=c;i++)
    {
        dig[i]=0;
    }
    while(n)
    {
        long long d = n%10;
        dig[c--]=d;
        n/=10;
    }
    return solve(0,0,0);
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long a;
        cin>>a;
        cout<<count(a)<<endl;
    }
}