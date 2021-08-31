#include <bits/stdc++.h>
using namespace std;



bool comp(const vector<int> &v1,const vector<int> &v2){
    return v1[0]<v2[0];

}

void merge(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end(), comp);

    // for(int i=0;i<intervals.size();i++){

    //     for(auto it=intervals[i].begin();it!=intervals[i].end();it++){
    //         cout<<*it<<" ";
    //     }
    //     cout<<endl;
    // }


   vector<vector<int>> ans;

   stack<pair<int,int>> st;

   st.push({intervals[0][0],intervals[0][1]});

   for(int i=1;i<intervals.size();i++){

       auto p = st.top();

       if(p.second<intervals[i][0]){

           ans.push_back({p.first,p.second});
           st.pop();
           st.push({intervals[i][0],intervals[i][1]});

       }
       else{
           if(intervals[i][1]>p.second){
               st.pop();
               st.push({p.first,intervals[i][1]});
           }

       }
   }

   ans.push_back({st.top().first,st.top().second});

    //  for(int i=0;i<ans.size();i++){

    //     for(auto it=ans[i].begin();it!=ans[i].end();it++){
    //         cout<<*it<<" ";
    //     }
    //     cout<<endl;
    // }

    return ans;







}

int main(){

    vector<vector<int>> intervals ={{1,3},{2,6},{8,10},{15,18},{20,22}};
    merge(intervals);



    return 0;
}