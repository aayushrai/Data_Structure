#include<bits/stdc++.h>

using namespace std;


class directedGraph {
  int vertex;
  vector<vector<int>> adjList;
  public:
  directedGraph(int vertex) {
    this->vertex = vertex;
    adjList.resize(vertex,vector<int>()); 
  }

  void addEdge(int src,int dst) {
    adjList[src].push_back(dst);
  }

  bool _cycle(int src,vector<bool>& visited) {
    visited[src] = true;
    
      for(int v:adjList[src]) {
        if(!visited[v]) {
          if(_cycle(v,visited))
            return true;
          } else {
          return true;
          }
      }  
    visited[src] = false;  
    return false;
  }

  bool cycle() {

    for(int i = 0; i < this->vertex; i++){
      vector<bool> visited(this->vertex,false);
      if(_cycle(i,visited))
        return true;
    }
    return false;
  }
};

int main(){
  int vertex = 5;
  directedGraph G(vertex);
  G.addEdge(0,1);
  G.addEdge(2,1);
  G.addEdge(4,2);
  G.addEdge(4,0);
  G.addEdge(2,3);
  G.addEdge(3,4);
  cout << G.cycle() << endl;
}