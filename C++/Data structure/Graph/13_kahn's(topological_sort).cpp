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
        }

        void kahsTopoSort() {
            queue<int> q;
            vector<int> indegree(this->vertex, 0);

            for(int i = 0; i < this->vertex; i++) {
                for(int v: this->adjList[i]) {
                    indegree[v]++;
                }
            }

            for(int ind = 0; ind < this->vertex; ind++) {
                if(indegree[ind] == 0)
                    q.push(ind);
            }

            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                cout << curr << " ";

                for(int ng : this->adjList[curr]) {
                    indegree[ng]--;
                    if(indegree[ng] == 0) {
                        q.push(ng);
                    }
                }

            }
        }
        
};

int main() {
    int vertex = 6;
	graph G(vertex);
	G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(3,1);
    G.addEdge(4,1);
    G.addEdge(5,0);
    G.addEdge(5,2);
    G.kahsTopoSort();
}
// |--->2
// 5-->0--->1<---4
//     |    ^
//     3____|
