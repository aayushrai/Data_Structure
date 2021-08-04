#include <bits/stdc++.h>

using namespace std;

class Graph
{
	int vertex;
	vector<vector<int>> adjList;

public:
	Graph(int vertex)
	{
		this->vertex = vertex;
		this->adjList.resize(vertex, vector<int>());
	}

	void addEdge(int src, int dst)
  {
		adjList[dst].push_back(src);
		adjList[src].push_back(dst);
	}

	bool isBipartite() {
		vector<int> colored(this->vertex, -1);

		for(int v = 0; v < this->vertex; v++ ) {   // for disconnected component
			if( colored[v] == -1 ) {
				queue<int> q;
				q.push(v);
				colored[v] = 1;

				while(!q.empty()) {
					int curr = q.front();
					q.pop();
					
					for( int j : this->adjList[curr] ) {
						if(colored[j] == -1) {
							colored[j] = 1 - colored[curr];
							q.push(j);
						} else if( colored[j] == colored[curr] ){
							return false;
						}
					}
				}
			}
		}
		return true;
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
	// G.addEdge(4,6);
	G.addEdge(5,6);
	cout << G.isBipartite();
}

// 0 ---- 1 --- 4  
// |      |     |  \    <- odd length cycle that why it is not bipartite
// 3 ---- 2 --- 5---6

// 0 ---- 1 --- 4  
// |      |     |     <- if we remove edge from 4 to 6 from above graph then odd length cycle
// 3 ---- 2 --- 5---6			will remove from graph then it will become bipartite graph, just comment
// 												4 to 6 edge.

