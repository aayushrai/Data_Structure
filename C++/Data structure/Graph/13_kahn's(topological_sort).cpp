#include<bits/stdc++.h>

using namespace std;

class graph {
    vector<vector<int>> adjList;
    int vertex;
    public:
        graph(int vertex) {
            this->vertex = vertex;
            this->adjList.resize(vertex, vector<int> () );
        }
        
        void addEdge(int src, int dst) {
            this->adjList[src].push_back(dst);
            this->adjList[dst].push_back(src);
        }
        
};

int main() {

}