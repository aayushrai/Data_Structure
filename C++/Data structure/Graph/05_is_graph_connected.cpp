#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class UndirectedGraph{
    public:
        int vertex;
        vector<vector<int>> adjList;
        UndirectedGraph(int vertex){
            this->vertex = vertex;
            adjList.resize(vertex,vector<int>()); 
        }

        void addEdge(int src,int dst){
            adjList[src].push_back(dst);
            adjList[dst].push_back(src);
        }

        void visiter(int src,vector<bool>& visited){
            visited[src]=true;
            for(int ver:adjList[src]){
                if(!visited[ver])
                    visiter(ver,visited);
            }
        }
        
        bool isConnected(){
            vector<bool> visited(this->vertex,false);
            visiter(0,visited);
            for(bool flg:visited){
                if(!flg)
                    return false;
            }
            return true;
        }

};
int main(){
     int vertex = 7;
    UndirectedGraph G(vertex);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    // G.addEdge(3,4);
    G.addEdge(4,5);
    G.addEdge(4,6);
    G.addEdge(5,6);
    cout << G.isConnected();
    return 0;
}