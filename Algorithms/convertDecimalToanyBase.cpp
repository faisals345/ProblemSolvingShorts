#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i,ini,n) for(ll i=ini;i<(int)n;i++)
#define all(x) x.begin(),x.end()

#define tc   int tt; cin>>tt; while(tt--)

#define endl "\n"
#define inf INT_MAX
#define ninf INT_MIN
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265358979323846264
 
const ll M =1e9+7;
const int N = 1e6+7;

void rev(string &s){

    int l = 0,r=s.length()-1;

    while(l<r){
        char temp = s[l];
        s[l]=s[r];
        s[r]=temp;
        l++;
        r--;
    }

}

char reVal(int num){

    if(num>=0 && num<=9){
        return (char)(num + '0');
    }
    return (char)(num-10 +'A');

}



void fromDeciToBase(string s,int base){

    int number = stoi(s);

    string res="";
    int i=0;

    while(number){
        res+=reVal(number%base);
        number/=base;

    }
    

    rev(res);

    cout<<res<<endl;






}



int main(){

    string s;
    cin>>s;

    fromDeciToBase(s,16);




  





    return 0;
}