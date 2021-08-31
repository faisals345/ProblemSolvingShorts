#include <bits/stdc++.h>

using namespace std;

void addEdge(unordered_map<int, list<pair<int, int>>> &graph, int x, int y, int weight)
{

    graph[x].push_back({y, weight});
}

void printGraph(unordered_map<int, list<pair<int, int>>> graph)
{

    for (auto x : graph)
    {
        cout << x.first << "->"
             << " ";
        for (auto vertex : x.second)
        {
            cout << "{" << vertex.first << "," << vertex.second << "}"
                 << " ";
        }
        cout << endl;
    }
}

void shortestPathDijikstraAlgo(unordered_map<int, list<pair<int, int>>> graph, int src, int vertices)
{

    int dist[vertices + 1];

    for (int i = 0; i < vertices + 1; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    set<pair<int, int>> s;
    s.insert({dist[src], src});

    while (!s.empty())
    {

        auto ele = *(s.begin());

        int node = ele.second;
        int nodeDist = ele.first;

        s.erase(s.begin());

        for (auto child : graph[node])
        {

            if (nodeDist + child.second < dist[child.first])
            {

                auto t = s.find({dist[child.first], child.first});
                if (t != s.end())
                {
                    s.erase(t);
                }

                s.insert(make_pair(nodeDist + child.second, child.first));
                dist[child.first] = nodeDist + child.second;
            }
        }
    }


    for(int i=1;i<=vertices;i++){
        cout<<"dist from src"<<src<<" ->";
        cout<<"to "<<i<<" = "<<dist[i]<<endl;
    }
}

int main()
{

    unordered_map<int, list<pair<int, int>>> graph;
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 1, 4, 7);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 4, 2);
    
    shortestPathDijikstraAlgo(graph,1,4);

    return 0;
}
