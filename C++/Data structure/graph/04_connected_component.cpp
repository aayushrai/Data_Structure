#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
        int vertex;
        vector<vector<int>> adjMatrix;
        graph(int vertex){
            this->vertex = vertex;
            adjMatrix.resize(vertex,vector<int>());
        }
        
        void addEdge(int src,int dst){
            adjMatrix[src].push_back(dst);
        }

        void connectedComponents(int src,vector<bool>&visited,vector<int>& path){
            path.push_back(src);
            visited[src] = true;
            for(int j:adjMatrix[src]){
                if(!visited[j]){
                    connectedComponents(j,visited,path);
                }
            }

        }

};

int main(){
    int vertex = 7;
    graph G(vertex);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(4,5);
    G.addEdge(4,6);
    G.addEdge(5,6);
    vector<bool>visited(vertex,false);
    vector<vector<int>>result;
    for(int i=0;i<vertex;i++){
      if(!visited[i]){ 
         vector<int> path = {};
         G.connectedComponents(i,visited,path);
         result.push_back(path);
      }
    }

    // print componets
    for(int i=0;i<result.size();i++){
        for(int ver:result[i]){
            cout << ver << " ";
        }
        cout << endl;
    }
    return 0;
}