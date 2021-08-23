#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
  int vertex;
  vector<vector<vector<int>>> adjList;
  vector<vector<int>> edges;

  graph(int vertex)
  {
    this->vertex = vertex;
    adjList.resize(vertex, vector<vector<int>>());
  }

  void addEdge(int src, int dst, int wt)
  {
    adjList[src].push_back({dst, wt});
    adjList[dst].push_back({src, wt});
    edges.push_back({wt, src, dst});
  }

  vector<vector<int>> kruskalMst(int scr)
  {
    vector<vector<int>> mst;
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> > minHeap;
    vector<bool> visited(vertex, false);

    minHeap.push({0, -1, 0}); // wieght , parent , curr
    while(!minHeap.empty()) {
      vector<int> temp = minHeap.top();

      minHeap.pop();
      if(visited[temp[2]])
        continue;
      mst.push_back(temp);
      visited[temp[2]] = true;
      for(vector<int> ver: adjList[temp[2]]){
        if(!visited[ver[0]]) {
          minHeap.push({ver[1], temp[2], ver[0]});
        }
      }
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
  vector<vector<int>> mst = G.kruskalMst(0);

  for(vector<int> edge: mst) {
    cout << "u->v " << edge[1] << "->" << edge[2] << " Weight = " << edge[0] << endl ;
  }

}


//     6     4
//  0 ---- 1 --- 4
//1 |      |1   2| \ 1
//  3 ---- 2 --- 5---6
//     3     1    6