// #include<bits/stdc++.h>

// using namespace std;


// class directedGraph {
//   int vertex;
//   vector<vector<int>> adjList;
//   public:
//   directedGraph(int vertex) {
//     this->vertex = vertex;
//     adjList.resize(vertex,vector<int>()); 
//   }

//   void addEdge(int src,int dst) {
//     adjList[src].push_back(dst);
//   }

//   bool _cycle(int src,vector<bool>& visited) {
//     visited[src] = true;
    
//       for(int v:adjList[src]) {
//         if(!visited[v]) {
//           if(_cycle(v,visited))
//             return true;
//           } else {
//           return true;
//           }
//       }  
//     visited[src] = false;  
//     return false;
//   }

//   bool cycle() {
//     vector<bool> visited(this->vertex,false);
//     for(int i = 0; i < this->vertex; i++){    // this loop use for undirected graph and diconnected components
//       visited[i] = true;
//       if(_cycle(i,visited))
//         return true;
//       visited[i] = false;
//     }
//     return false;
//   }
// };

// int main(){
//   int vertex = 5;
//   directedGraph G(vertex);
//   G.addEdge(0,1);
//   G.addEdge(2,1);
//   G.addEdge(4,2);
//   G.addEdge(4,0);
//   G.addEdge(2,3);
//   G.addEdge(3,4);
//   cout << G.cycle() << endl;
// }

//  Above aproach take too much time to detect cycle, in worst case O(V*E) because it will revisite the
// visited verticies.
// That why we use another approach down below, in which we are not going to visite revisited verticies. we going to maintain 
// two array, in first one we mark all the visited vertices and another one for current dfs call, this aproach take O(v+e);

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

  bool _cycle(int src,vector<bool>& visited,vector<bool>& currentDfsVisited) {
    if(visited[src])
      return false;
    visited[src] = currentDfsVisited[src] = true;
  
    for(int v:adjList[src]) {
      if(!currentDfsVisited[v]) {
        if(_cycle(v,visited,currentDfsVisited))
          return true;
      } else {
        return true;
      }
    }  
  currentDfsVisited[src] = false;  
  return false;
  }

  bool cycle() {
    vector<bool> visited(this->vertex,false),currentDfsVisited(this->vertex,false);;
    for(int i = 0; i < this->vertex; i++){   // this loop use for undirected graph and diconnected components
      if(!visited[i])
        if(_cycle(i,visited,currentDfsVisited))
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

// 0 -----> 1 <------ 2-------> 3
// ^                  ^         |    <- cycle
// |                  |         |
// -------------------4<---------

//  you can see here if we start from 0 we can only reach 1 after that we can't go further. 