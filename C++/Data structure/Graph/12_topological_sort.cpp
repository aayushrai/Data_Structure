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

  void _topologicalSort(int src,stack<int>& stack,vector<bool>& visited) {
    visited[src] = true;
    
      for(int v:adjList[src]){
        if(!visited[v]){
          _topologicalSort(v,stack,visited);
        }
      }  
    stack.push(src);
  }

  void topologicalSort() {
    stack<int> stack;
    vector<bool> visited(this->vertex,false);

    for(int i = 0; i < this->vertex; i++){
      if(!visited[i]){
        _topologicalSort(i,stack,visited);
      }
    }
    while(!stack.empty()){
      cout << stack.top() << " ";
      stack.pop();
    }   
  }
};

int main(){
  int vertex = 6;
  directedGraph G(vertex);
  G.addEdge(0,2);
  G.addEdge(0,3);
  G.addEdge(3,1);
  G.addEdge(4,1);
  G.addEdge(5,0);
  G.addEdge(5,2);
  G.topologicalSort();
}