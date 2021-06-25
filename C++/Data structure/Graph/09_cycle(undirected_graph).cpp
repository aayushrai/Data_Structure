#include<bits/stdc++.h>

using namespace std;

class graph{
    int vertex;
    vector<vector<int>> adjList;
    public:
    graph(int vertex){
        this->vertex = vertex;
        this->adjList.resize(vertex,vector<int>());
    }
    void addEdge(int s,int d){
        adjList[s].push_back(d);
        adjList[d].push_back(s);
    }
    
    bool _isCycle(int src,vector<bool>& visited,int parent){
        visited[src] = true;
        for(int v:this->adjList[src]){
            if(!visited[v]){
                if(_isCycle(v,visited,src))
                    return true;
            }
            else if(v != parent){
                return true;
            }
        }
        visited[src] = false;
        return false;
    }

    bool isCycle(){
        vector<bool> visited(this->vertex,false);
        for(int i=0;i<this->vertex;i++){    // for disconnected components
            if(!visited[i]){
                if(_isCycle(i,visited,-1))
                    return true;
            }
        }
        return false;
    }

};

int main(){
    int vertex = 7;
    graph G(vertex);
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
// 0 ---- 1 --- 4  
// |      |     |  \    
// 3 ---- 2 --- 5---6
