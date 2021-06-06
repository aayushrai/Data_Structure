#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
        int vertex;
        vector<vector<int>> adjList;
        graph(int vertex){
            this->vertex = vertex;
            adjList.resize(vertex,vector<int>());
        }
        
        void addEdge(int src,int dst){
            adjList[src].push_back(dst);
        }

        void printAllPathsFromSrc2dst(int src,int dst,vector<bool>&visited,vector<int> path){
            if(src==dst){
                path.push_back(src);
                for(int i:path){
                    cout << i << " ";
                }
                cout << endl;
            }
            path.push_back(src);
            visited[src] = true;
            for(int j:adjList[src]){
                if(!visited[j]){
                    printAllPathsFromSrc2dst(j,dst,visited,path);
                }
            }
            visited[src] = false;

        }

};

int main(){
    int vertex = 7;
    graph G(vertex);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,5);
    G.addEdge(4,6);
    G.addEdge(5,6);
    vector<bool>visited(vertex,false);
     G.printAllPathsFromSrc2dst(0,6,visited,{});
    return 0;
}