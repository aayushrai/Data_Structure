#include <bits/stdc++.h>
using namespace std;

class graph
{
  int vertex;
  vector<vector<vector<int>>> adjList;

public:
  graph(int vertex)
  {
    this->vertex = vertex;
    this->adjList.resize(vertex, vector<vector<int>>());
  }

  void addEdge(int src, int dst, int wt)
  {
    adjList[src].push_back({dst, wt});
    adjList[dst].push_back({src, wt});
  }

  int minimumDistIndex(vector<int> dist, vector<bool> visited)
  {
    int mn = INT_MAX,index = -1;

    for (int i = 0; i < this->vertex; i++)
    {
      if (!visited[i] and mn > dist[i])
        mn = dist[i],index = i;
    }
    return index;
  }

  void mst(int startPoint)
  {
    vector<int> dist(this->vertex, INT_MAX);
    vector<bool> partOfMst(this->vertex, false);
    vector<int> parent(this->vertex, -1);

    parent[startPoint] = -1;
    dist[startPoint] = 0;

    while (true)
    {
      int miniIndex = this->minimumDistIndex(dist, partOfMst);
      if (miniIndex == -1)
        break;
      partOfMst[miniIndex] = true;

      for (vector<int> ver : adjList[miniIndex])
      {
        if (!partOfMst[ver[0]] and dist[ver[0]] > ver[1])
          dist[ver[0]] = ver[1], parent[ver[0]] = miniIndex;
      }
    }
    // for display
    for (int i = 1; i < vertex; i++)
    {
      cout << "u->v: " << parent[i] << "->" << i << endl;
    }
  }
};

int main()
{
  int vertex = 7;
  graph G(vertex);
  G.addEdge(0, 1, 6);
  G.addEdge(0, 3, 1);
  G.addEdge(1, 2, 1);
  G.addEdge(1, 4, 4);
  G.addEdge(2, 3, 3);
  G.addEdge(2, 5, 1);
  G.addEdge(4, 5, 2);
  G.addEdge(4, 6, 1);
  G.addEdge(5, 6, 6);
  G.mst(0);
}

//     6     4
//  0 ---- 1 --- 4
//1 |      |1   2| \ 1
//  3 ---- 2 --- 5---6
//     3     1    6