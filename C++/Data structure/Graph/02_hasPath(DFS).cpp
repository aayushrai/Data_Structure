#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef struct vw{
    int vertex,weight;
}vw;

class graph{
    public:
        int vertex;
        vector<vector<vw>> adjList; 
        graph(int vertex){
            this->vertex = vertex;
            this->adjList.resize(vertex,vector<vw>());
        }
        void addEdge(int src,int dst,int weight){
            vw temp = {dst,weight};
            vw temp2 = {src,weight};
            this->adjList[src].push_back(temp);
            // this->adjList[dst].push_back(temp2);  // comment this line for directed graph or uncomment for undirected graph
        }
        void diplayGraph(){
             cout << "Edges:" << "\n" ;
            for(int i=0;i<adjList.size();i++){
                for(int j=0;j<adjList[i].size();j++){
                cout << i << " " <<  adjList[i][j].vertex << " " << adjList[i][j].weight << "\n" ;
                }
            }
        }
        bool hasPath(int src,int dst,vector<bool> visited){
            if(src == dst){
                return true;
            }
            visited[src] = true;
            for(vw i:adjList[src]){
                if(!visited[i.vertex]){
                    if(hasPath(i.vertex,dst,visited))
                        return true;
                }
            }
            return false;

        }
};
int main(){
    int vertex = 6;
    graph g(vertex);
    g.addEdge(0,1,10);
    g.addEdge(0,4,10);
    g.addEdge(4,5,10);
    g.addEdge(1,2,10);
    g.addEdge(2,3,10);
    g.addEdge(3,1,10);
    g.diplayGraph();
    vector<bool> visited(vertex,false);
    cout << g.hasPath(0,3,visited) << endl;
    return 0;
}