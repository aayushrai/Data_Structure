#include<bits/stdc++.h>

using namespace std;

class Graph {
    vector<vector<int>> adjList;
    int vertex;
    public:
        Graph(int vertex) {
            this->vertex = vertex;
            this->adjList.resize(vertex, vector<int>());
        }

        void addEdge(int src, int dst) {
            adjList[src].push_back(dst);
            adjList[dst].push_back(src);
        } 

        bool _isCycle(int v, vector<bool> visited, int parent ) {
            visited[v] = true;

            for(int vt:this->adjList[v]) {
                if(!visited[vt]) {
                    if(_isCycle(vt, visited, v)) {
                        return true;
                    }
                } else {
                    if(parent != vt)
                        return true;
                }
            }
            return false;
        }
        bool isCycle(){
            vector<bool> visited(this->vertex,false);
            for(int i = 0; i < this->vertex; i++ ){
                if(!visited[i]) {
                    if(_isCycle(i,visited,-1)){
                        return true;
                    }
                }
            }
            return false;
        }
};

int main() { 
    int vertex = 7;
    Graph G(vertex);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(1,4);
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(4,5);
    G.addEdge(4,6);
    G.addEdge(5,6);
    cout << G.isCycle();
}