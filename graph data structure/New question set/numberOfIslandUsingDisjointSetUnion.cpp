#include <bits/stdc++.h>

using namespace std;


struct DSU{

    int n;
    vector<int> parent, rank;

    DSU(int n){
        this->n=n;
        parent.resize(n);
        rank.resize(n);

        init();
    }

    void init(){

        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }

    }


    int findSet(int x){

        if(parent[x]==-1){
            return x;
        }

        return parent[x]=findSet(parent[x]);


    }


    void unionSet(int x,int y){

        int s1 = findSet(x);
        int s2 = findSet(y);

        if(s1==s2){
            return;
        }

        if(rank[s1]<rank[s2]){
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }else{
            parent[s2]=s1;
            rank[s1]+=rank[s2];

        }

        return ;


    }





};







int main(){

    DSU dsu(25);

    vector<vector<int>> a = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    int n=5,m=5;
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            // If cell is 0, nothing to do
            if (a[j][k] == 0)
                continue;

            if (j + 1 < n && a[j + 1][k] == 1)
                dsu.unionSet(j * (m) + k,
                             (j + 1) * (m) + k);
            if (j - 1 >= 0 && a[j - 1][k] == 1)
                dsu.unionSet(j * (m) + k,
                             (j - 1) * (m) + k);
            if (k + 1 < m && a[j][k + 1] == 1)
                dsu.unionSet(j * (m) + k,
                             (j) * (m) + k + 1);
            if (k - 1 >= 0 && a[j][k - 1] == 1)
                dsu.unionSet(j * (m) + k,
                             (j) * (m) + k - 1);
            if (j + 1 < n && k + 1 < m &&
                a[j + 1][k + 1] == 1)
                dsu.unionSet(j * (m) + k,
                             (j + 1) * (m) + k + 1);
            if (j + 1 < n && k - 1 >= 0 &&
                a[j + 1][k - 1] == 1)
                dsu.unionSet(j * m + k,
                             (j + 1) * (m) + k - 1);
            if (j - 1 >= 0 && k + 1 < m &&
                a[j - 1][k + 1] == 1)
                dsu.unionSet(j * m + k,
                             (j - 1) * m + k + 1);
            if (j - 1 >= 0 && k - 1 >= 0 &&
                a[j - 1][k - 1] == 1)
                dsu.unionSet(j * m + k,
                             (j - 1) * m + k - 1);
        }
    }


    int *c = new int[n * m];
    int numberOfIslands = 0;

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < m; k++)
        {
            if (a[j][k] == 1)
            {
                int x = dsu.findSet(j * m + k);
 
               
                if (c[x] == 0)
                {
                    numberOfIslands++;
                    c[x]++;
                }
 
                else
                    c[x]++;
            }
        }
    }

    cout<<numberOfIslands<<endl;

    return 0;
}