// sort all the edges in increasing order;
// pick edge in increasing order one by one and check by adding this edge cycle forms or not
// if cycle forms skip this edge and go to next edge if not then add the edge to mst.
//  for detecting cycle use disjoint_set
#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
  int vertex;
  vector<vector<vector<int>>> adjList;
  vector<vector<int>> edges;
  vector<int> parent;
  vector<int> rank;

  graph(int vertex)
  {
    this->vertex = vertex;
    adjList.resize(vertex, vector<vector<int>>());
    parent.resize(vertex, -1);
    rank.resize(vertex, 0);
  }

  void addEdge(int src, int dst, int wt)
  {
    adjList[src].push_back({dst, wt});
    adjList[dst].push_back({src, wt});
    edges.push_back({wt, src, dst});
  }

  int findParent(int node)
  {
    if (parent[node] == -1)
      return node;
    return parent[node] = findParent(parent[node]);
  }

  void unionn(int u, int v)
  {
    u = findParent(u);
    v = findParent(v);

    if (rank[u] > rank[v])
    {
      parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
      parent[u] = v;
    }
    else
    {
      parent[v] = u;
      rank[u]++;
    }
  }

  vector<vector<int>> kruskalMst()
  {
    vector<vector<int>> mst;
    sort(edges.begin(), edges.end());
    for (vector<int> edge : edges)
    {
      int u = findParent(edge[1]);
      int v = findParent(edge[2]);

      if(u == v) {
        continue;
      }

      unionn(u, v);
      mst.push_back(edge);
    }
    return mst;
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
  vector<vector<int>> mst = G.kruskalMst();

  for(vector<int> edge: mst) {
    cout << "u->v " << edge[1] << "->" << edge[2] << " Weight = " << edge[0] << endl ;
  }

}


//     6     4
//  0 ---- 1 --- 4
//1 |      |1   2| \ 1
//  3 ---- 2 --- 5---6
//     3     1    6