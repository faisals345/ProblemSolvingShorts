#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> isPalindrome;








int main(){

    string s;
    cin>>s;

    int n = s.length();

    isPalindrome.resize(n,vector<int>(n));

    // creating isPalindrome dp in bottom up fashion

    for(int i=0;i<n;i++){
        isPalindrome[i][i]=1;
    }

    for (int startI = n - 1; startI >= 0; startI--)
    {

        for (int endI = startI + 1; endI < n; endI++)
        {

            if (s[startI] == s[endI])
            {
                if (endI - startI <= 1)
                {
                    isPalindrome[startI][endI] = 1;
                }
                else
                {
                    isPalindrome[startI][endI] = isPalindrome[startI + 1][endI - 1];
                }
            }
            else
              isPalindrome[startI][endI] = 0;
        }
    }


    for(int i=0;i<isPalindrome.size();i++){
        for(auto it = isPalindrome[i].begin();it!=isPalindrome[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }


    int cuts[n];

    cuts[0]=0;

    for(int i=1;i<n;i++){

         int val = INT_MAX;

        for(int j=i;j>=0;j--){

            if(j==0 && isPalindrome[j][i]==1){
                val=0;
            }

           
          else  if(isPalindrome[j][i]==1){
                val = min(val,1+cuts[j-1]);
            }
        }
        cuts[i]=val;
    }

    cout<<cuts[n-1]<<endl;

    return 0;
}