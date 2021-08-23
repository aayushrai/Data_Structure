#include <bits/stdc++.h>

using namespace std;

class graph{

  public:
    int vertex;
    vector<vector<int>> adjList;
    vector<vector<int>> edges;
    graph(int vertex){
      this->vertex =  vertex;
      this->adjList.resize(vertex, vector<int> ());
    }

    void addEdge(int src, int dst) {
      this->adjList[src].push_back(dst);
      this->adjList[dst].push_back(src);

      this->edges.push_back({src,dst});
    }
};

// find parent by path compration
int findParent(int node, int parent[])
{
  if (parent[node] == -1)
    return node;
  return parent[node] = findParent(parent[node], parent);
}

// find parent without path compration
int _findParent(int node, int parent[])
{
  if (parent[node] == -1)
    return node;
  return findParent(parent[node], parent);
}

// find union by ranking
void unionn(int u, int v, int rankk[], int parent[])
{
  u = findParent(u, parent);
  v = findParent(v, parent);
  if (rankk[u] > rankk[v])
  {
    parent[v] = u;
  }
  else if (rankk[u] < rankk[v])
  {
    parent[u] = v;
  }
  else
  {
    parent[v] = u;
    rankk[u]++;
  }
}

// find union without ranking
void _unionn(int u, int v,int parent[])
{
    parent[v] = u;
}

int main()
{
  int vertex = 5;
  graph G(vertex);

  G.addEdge(0,1);
  G.addEdge(0,2);
  G.addEdge(2,3);
  G.addEdge(4,3);
  G.addEdge(4,1);

  int parent[10000];
  int rankk[10000];

  memset(parent,-1,sizeof(int)*vertex);
  memset(rankk,0,sizeof(int)*vertex);

  // iterate through all the edges;
  for(vector<int> edge: G.edges) {
      int u = findParent(edge[0], parent);
      int v = findParent(edge[1], parent);
      if(u == v) {
        cout << "cycle detected";
        break;
      }
      unionn(u,v,rankk,parent);
  }


}
