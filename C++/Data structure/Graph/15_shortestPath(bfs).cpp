#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
  int vertex;
  vector<vector<vector<int>>> adjList;
  graph(int vertex)
  {
    this->vertex = vertex;
    this->adjList.resize(vertex, vector<vector<int>>());
  }

  void addEdge(int src, int dst, int wet)
  {
    adjList[src].push_back({dst, wet});
    adjList[dst].push_back({src, wet});
  }

  void shortestPathFromSrc(int src)
  {
    queue<int> q;
    q.push(src);
    vector<int> shortestPathArray(this->vertex, INT_MAX);
    shortestPathArray[src] = 0;
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();

      for (auto ng : adjList[curr])
      {
        if (shortestPathArray[curr] + ng[1] < shortestPathArray[ng[0]])
        {
          shortestPathArray[ng[0]] = shortestPathArray[curr] + ng[1];
          q.push(ng[0]);
        }
      }
    }
    for(int i = 0; i < shortestPathArray.size(); i++) {
      cout << "shortest distance from" << src << "to"
    }
  }
};

int main()
{
  int vertex = 7;
  graph G(vertex);
  G.addEdge(0, 1, 1);
  G.addEdge(0, 3, 1);
  G.addEdge(1, 2, 1);
  G.addEdge(1, 4, 1);
  G.addEdge(2, 3, 1);
  G.addEdge(2, 5, 1);
  G.addEdge(4, 5, 1);
  G.addEdge(4, 6, 1);
  G.addEdge(5, 6, 1);
}

// 0 ---- 1 --- 4
// |      |     |  \   
// 3 ---- 2 --- 5---6

// 0 1 2 3 4 5 6
// 0 1 i 1 i i i

// q -> 3